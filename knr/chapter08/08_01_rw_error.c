/* KnR Book Second Edition, written by Brian Kernighan and Dennis Ritchie */
/* Exercise 8.1 - Rewrite read and write with error handling */

#include <stdio.h>
#include <unistd.h>
#include <errno.h>
#include <string.h>

/* Rewrite the program cat from Chapter 7 using read, write, open, and close
   instead of their standard library equivalents. Perform experiments to determine
   the relative speeds of the two versions. */

#define BUFSIZE 4096

void error(char *s) {
    fprintf(stderr, "error: %s\n", s);
}

int main(int argc, char *argv[]) {
    int fd, n;
    char buf[BUFSIZE];
    
    if (argc == 1) {
        /* Read from stdin */
        while ((n = read(0, buf, BUFSIZE)) > 0) {
            if (write(1, buf, n) != n) {
                error("write error");
                return 1;
            }
        }
        if (n < 0) {
            error("read error");
            return 1;
        }
    } else {
        while (--argc > 0) {
            if ((fd = open(*++argv, 0)) == -1) {
                fprintf(stderr, "cat: can't open %s: %s\n", *argv, strerror(errno));
                continue;
            }
            while ((n = read(fd, buf, BUFSIZE)) > 0) {
                if (write(1, buf, n) != n) {
                    error("write error");
                    close(fd);
                    return 1;
                }
            }
            if (n < 0) {
                fprintf(stderr, "cat: read error on %s: %s\n", *argv, strerror(errno));
                close(fd);
                continue;
            }
            close(fd);
        }
    }
    return 0;
} 