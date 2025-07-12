# Chapter 8 - The UNIX System Interface

## 8.1 File Descriptors

### File Descriptors:
- `0` - standard input (stdin)
- `1` - standard output (stdout)
- `2` - standard error (stderr)

### Low-level I/O:
```c
#include <fcntl.h>

int open(char *name, int flags, int perms);
int creat(char *name, int perms);
int close(int fd);
int read(int fd, char *buf, int n);
int write(int fd, char *buf, int n);
```

### Example - File Copy:
```c
#include <stdio.h>
#include <fcntl.h>

#define BUFSIZE 1024

int main(int argc, char *argv[]) {
    int fd1, fd2, n;
    char buf[BUFSIZE];
    
    if (argc != 3) {
        fprintf(stderr, "usage: %s source dest\n", argv[0]);
        return 1;
    }
    
    if ((fd1 = open(argv[1], O_RDONLY, 0)) == -1) {
        fprintf(stderr, "can't open %s\n", argv[1]);
        return 1;
    }
    
    if ((fd2 = creat(argv[2], 0644)) == -1) {
        fprintf(stderr, "can't create %s\n", argv[2]);
        return 1;
    }
    
    while ((n = read(fd1, buf, BUFSIZE)) > 0)
        if (write(fd2, buf, n) != n) {
            fprintf(stderr, "write error\n");
            return 1;
        }
    
    close(fd1);
    close(fd2);
    return 0;
}
```

## 8.2 Low Level I/O - Read and Write

### Read Function:
```c
int read(int fd, char *buf, int n);
```

### Write Function:
```c
int write(int fd, char *buf, int n);
```

### Return Values:
- `read` returns number of bytes read, 0 for EOF, -1 for error
- `write` returns number of bytes written, -1 for error

### Example - Character Copy:
```c
#include <stdio.h>
#include <unistd.h>

int main() {
    char buf[1];
    int n;
    
    while ((n = read(0, buf, 1)) > 0)
        write(1, buf, 1);
    return 0;
}
```

## 8.3 Open, Creat, Close, Unlink

### Open Function:
```c
int open(char *name, int flags, int perms);
```

### Flags:
```c
O_RDONLY    open for reading only
O_WRONLY    open for writing only
O_RDWR      open for reading and writing
O_CREAT     create file if it doesn't exist
O_TRUNC     truncate file to zero length
O_APPEND    append to file
```

### Permissions:
```c
0644    owner read/write, group read, others read
0755    owner read/write/execute, group read/execute, others read/execute
```

### Example - File Operations:
```c
#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>

int main() {
    int fd;
    
    /* Create file */
    fd = creat("test.txt", 0644);
    if (fd == -1) {
        perror("creat");
        return 1;
    }
    close(fd);
    
    /* Open for writing */
    fd = open("test.txt", O_WRONLY | O_APPEND, 0);
    if (fd == -1) {
        perror("open");
        return 1;
    }
    
    write(fd, "Hello, World!\n", 14);
    close(fd);
    
    /* Remove file */
    unlink("test.txt");
    return 0;
}
```

## 8.4 Random Access - Lseek

### Lseek Function:
```c
#include <unistd.h>

long lseek(int fd, long offset, int origin);
```

### Origins:
```c
SEEK_SET    beginning of file
SEEK_CUR    current position
SEEK_END    end of file
```

### Example - Random Access:
```c
#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>

int main() {
    int fd;
    char buf[100];
    
    fd = open("file.txt", O_RDWR, 0);
    if (fd == -1) {
        perror("open");
        return 1;
    }
    
    /* Seek to position 10 */
    lseek(fd, 10L, SEEK_SET);
    
    /* Read 10 bytes */
    read(fd, buf, 10);
    buf[10] = '\0';
    printf("Read: %s\n", buf);
    
    /* Seek to end and append */
    lseek(fd, 0L, SEEK_END);
    write(fd, "Appended text\n", 14);
    
    close(fd);
    return 0;
}
```

## 8.5 Example - An implementation of Fopen and Getc

### Fopen Implementation:
```c
#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>

#define PERMS 0666

FILE *fopen(char *name, char *mode) {
    int fd;
    FILE *fp;
    
    if (*mode != 'r' && *mode != 'w' && *mode != 'a')
        return NULL;
    for (fp = _iob; fp < _iob + OPEN_MAX; fp++)
        if ((fp->flag & (_READ | _WRITE)) == 0)
            break;
    if (fp >= _iob + OPEN_MAX)
        return NULL;
    
    if (*mode == 'w')
        fd = creat(name, PERMS);
    else if (*mode == 'a') {
        if ((fd = open(name, O_WRONLY, 0)) == -1)
            fd = creat(name, PERMS);
        lseek(fd, 0L, 2);
    } else
        fd = open(name, O_RDONLY, 0);
    if (fd == -1)
        return NULL;
    fp->fd = fd;
    fp->cnt = 0;
    fp->base = NULL;
    fp->flag = (*mode == 'r') ? _READ : _WRITE;
    return fp;
}
```

### Getc Implementation:
```c
int getc(FILE *fp) {
    return (--fp->cnt >= 0) ? (unsigned char) *fp->ptr++ : _fillbuf(fp);
}

int _fillbuf(FILE *fp) {
    int bufsize;
    
    if ((fp->flag & (_READ | _EOF | _ERR)) != _READ)
        return EOF;
    bufsize = (fp->flag & _UNBUF) ? 1 : BUFSIZ;
    if (fp->base == NULL)
        if ((fp->base = (char *) malloc(bufsize)) == NULL)
            return EOF;
    fp->ptr = fp->base;
    fp->cnt = read(fp->fd, fp->ptr, bufsize);
    if (--fp->cnt < 0) {
        if (fp->cnt == -1)
            fp->flag |= _EOF;
        else
            fp->flag |= _ERR;
        fp->cnt = 0;
        return EOF;
    }
    return (unsigned char) *fp->ptr++;
}
```

## 8.6 Example - Listing Directories

### Directory Listing:
```c
#include <stdio.h>
#include <sys/types.h>
#include <dirent.h>
#include <sys/stat.h>
#include <string.h>

void fsize(char *);

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
    printf("%8ld %s\n", stbuf.st_size, name);
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
```

## 8.7 Example - A Storage Allocator

### Memory Allocator:
```c
#include <unistd.h>

typedef long Align;

union header {
    struct {
        union header *ptr;
        unsigned size;
    } s;
    Align x;
};

typedef union header Header;

static Header base;
static Header *freep = NULL;

void *malloc(unsigned nbytes) {
    Header *p, *prevp;
    Header *morecore(unsigned);
    unsigned nunits;
    
    nunits = (nbytes + sizeof(Header) - 1) / sizeof(Header) + 1;
    if ((prevp = freep) == NULL) {
        base.s.ptr = freep = prevp = &base;
        base.s.size = 0;
    }
    for (p = prevp->s.ptr; ; prevp = p, p = p->s.ptr) {
        if (p->s.size >= nunits) {
            if (p->s.size == nunits)
                prevp->s.ptr = p->s.ptr;
            else {
                p->s.size -= nunits;
                p += p->s.size;
                p->s.size = nunits;
            }
            freep = prevp;
            return (void *)(p + 1);
        }
        if (p == freep)
            if ((p = morecore(nunits)) == NULL)
                return NULL;
    }
}

#define NALLOC 1024

Header *morecore(unsigned nu) {
    char *cp, *sbrk(int);
    Header *up;
    
    if (nu < NALLOC)
        nu = NALLOC;
    cp = sbrk(nu * sizeof(Header));
    if (cp == (char *) -1)
        return NULL;
    up = (Header *) cp;
    up->s.size = nu;
    free((void *)(up + 1));
    return freep;
}

void free(void *ap) {
    Header *bp, *p;
    
    bp = (Header *)ap - 1;
    for (p = freep; !(bp > p && bp < p->s.ptr); p = p->s.ptr)
        if (p >= p->s.ptr && (bp > p || bp < p->s.ptr))
            break;
    
    if (bp + bp->s.size == p->s.ptr) {
        bp->s.size += p->s.ptr->s.size;
        bp->s.ptr = p->s.ptr->s.ptr;
    } else
        bp->s.ptr = p->s.ptr;
    if (p + p->s.size == bp) {
        p->s.size += bp->s.size;
        p->s.ptr = bp->s.ptr;
    } else
        p->s.ptr = bp;
    freep = p;
}
```

## Exercises

- [Exercise 8.1 - Rewrite read and write with error handling](./chapter08/08_01_rw_error.c)
- [Exercise 8.2 - Rewrite fopen and getc with buffering](./chapter08/08_02_fopen_buf.c)
- [Exercise 8.3 - Directory listing with file types](./chapter08/08_03_dir_types.c)
- [Exercise 8.4 - Memory allocator with best-fit](./chapter08/08_04_best_fit.c)
- [Exercise 8.5 - Memory allocator with first-fit](./chapter08/08_05_first_fit.c)
- [Exercise 8.6 - Memory allocator with boundary tags](./chapter08/08_06_boundary.c)
- [Exercise 8.7 - Memory allocator with coalescing](./chapter08/08_07_coalesce.c)
- [Exercise 8.8 - Memory allocator with segregated lists](./chapter08/08_08_segregated.c) 