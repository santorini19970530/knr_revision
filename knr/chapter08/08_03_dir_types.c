/* Exercise 8.3 - Directory listing with file types */

#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <dirent.h>
#include <string.h>

void fsize(char *);
void dirwalk(char *, void (*fcn)(char *));

#define MAXPATH 1024

int main(int argc, char *argv[]) {
    if (argc == 1)
        fsize(".");
    else
        while (--argc > 0)
            fsize(*++argv);
    return 0;
}

void fsize(char *name) {
    struct stat stbuf;
    
    if (stat(name, &stbuf) == -1) {
        fprintf(stderr, "fsize: can't access %s\n", name);
        return;
    }
    if ((stbuf.st_mode & S_IFMT) == S_IFDIR)
        dirwalk(name, fsize);
    
    /* Print file type and size */
    printf("%8ld ", stbuf.st_size);
    switch (stbuf.st_mode & S_IFMT) {
        case S_IFREG:
            printf("file     ");
            break;
        case S_IFDIR:
            printf("dir      ");
            break;
        case S_IFCHR:
            printf("char dev ");
            break;
        case S_IFBLK:
            printf("block dev");
            break;
        case S_IFLNK:
            printf("link     ");
            break;
        case S_IFSOCK:
            printf("socket   ");
            break;
        case S_IFIFO:
            printf("fifo     ");
            break;
        default:
            printf("unknown  ");
            break;
    }
    printf(" %s\n", name);
}

void dirwalk(char *dir, void (*fcn)(char *)) {
    char name[MAXPATH];
    struct dirent *dp;
    DIR *dfd;
    
    if ((dfd = opendir(dir)) == NULL) {
        fprintf(stderr, "dirwalk: can't open %s\n", dir);
        return;
    }
    while ((dp = readdir(dfd)) != NULL) {
        if (strcmp(dp->d_name, ".") == 0 || strcmp(dp->d_name, "..") == 0)
            continue;
        if (strlen(dir) + strlen(dp->d_name) + 2 > sizeof(name))
            fprintf(stderr, "dirwalk: name %s/%s too long\n", dir, dp->d_name);
        else {
            sprintf(name, "%s/%s", dir, dp->d_name);
            (*fcn)(name);
        }
    }
    closedir(dfd);
} 