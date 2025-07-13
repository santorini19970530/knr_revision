# Chapter 6 - Structures

## 6.1 Basics of Structures

### Structure Declaration:
```c
struct point {
    int x;
    int y;
};
```

### Structure Variable:
```c
struct point pt;
pt.x = 320;
pt.y = 200;
```

### Structure Initialization:
```c
struct point maxpt = {320, 200};
```

### Structure Assignment:
```c
pt = maxpt;  /* copy structure */
```

## 6.2 Structures and Functions

### Pass by Value:
```c
struct point makepoint(int x, int y) {
    struct point temp;
    
    temp.x = x;
    temp.y = y;
    return temp;
}
```

### Pass by Reference:
```c
struct point *pp;
pp = &pt;
(*pp).x = 320;  /* parentheses required */
pp->x = 320;    /* equivalent */
```

## 6.3 Arrays of Structures

### Array Declaration:
```c
struct key {
    char *word;
    int count;
} keytab[NKEYS];
```

### Array Initialization:
```c
struct key keytab[] = {
    {"auto", 0},
    {"break", 0},
    {"case", 0},
    {"char", 0},
    {"const", 0},
    {"continue", 0},
    {"default", 0},
    {"unsigned", 0},
    {"void", 0},
    {"volatile", 0},
    {"while", 0}
};
```

- [Exercise 6.1 - getword function](./chapter06/06_01_getword.c)
- [Exercise 6.2 - Write program to read C declarations](./chapter06/06_02_c_decl.c)
- [Exercise 6.3 - Cross-reference program](./chapter06/06_03_crossref.c)

## 6.4 Pointers to Structures

### Pointer Declaration:
```c
struct point *pp;
```

### Access via Pointer:
```c
pp->x = 320;  /* equivalent to (*pp).x = 320 */
```

### Example - String Length:
```c
struct namect {
    char fname[20];
    char lname[20];
    int letters;
};

void getinfo(struct namect *pst) {
    printf("Please enter your first name.\n");
    gets(pst->fname);
    printf("Please enter your last name.\n");
    gets(pst->lname);
}
```

## 6.5 Self-referential Structures

### Binary Tree Node:
```c
struct tnode {
    char *word;
    int count;
    struct tnode *left;
    struct tnode *right;
};
```

### Tree Node Allocation:
```c
struct tnode *talloc(void) {
    return (struct tnode *) malloc(sizeof(struct tnode));
}

char *strdup(char *s) {
    char *p;
    
    p = (char *) malloc(strlen(s) + 1);
    if (p != NULL)
        strcpy(p, s);
    return p;
}
```

### Add Tree Node:
```c
struct tnode *addtree(struct tnode *p, char *w) {
    int cond;
    
    if (p == NULL) {
        p = talloc();
        p->word = strdup(w);
        p->count = 1;
        p->left = p->right = NULL;
    } else if ((cond = strcmp(w, p->word)) == 0)
        p->count++;
    else if (cond < 0)
        p->left = addtree(p->left, w);
    else
        p->right = addtree(p->right, w);
    return p;
}
```

- [Exercise 6.4 - Print tree in order](./chapter06/06_04_treeprint.c)

## 6.6 Table Lookup

### Hash Table Entry:
```c
struct nlist {
    struct nlist *next;
    char *name;
    char *defn;
};
```

### Hash Table:
```c
#define HASHSIZE 101
static struct nlist *hashtab[HASHSIZE];
```

### Hash Function:
```c
unsigned hash(char *s) {
    unsigned hashval;
    
    for (hashval = 0; *s != '\0'; s++)
        hashval = *s + 31 * hashval;
    return hashval % HASHSIZE;
}
```

### Lookup Function:
```c
struct nlist *lookup(char *s) {
    struct nlist *np;
    
    for (np = hashtab[hash(s)]; np != NULL; np = np->next)
        if (strcmp(s, np->name) == 0)
            return np;
    return NULL;
}
```

### Install Function:
```c
struct nlist *install(char *name, char *defn) {
    struct nlist *np;
    unsigned hashval;
    
    if ((np = lookup(name)) == NULL) {
        np = (struct nlist *) malloc(sizeof(*np));
        if (np == NULL || (np->name = strdup(name)) == NULL)
            return NULL;
        hashval = hash(name);
        np->next = hashtab[hashval];
        hashtab[hashval] = np;
    } else
        free((void *) np->defn);
    if ((np->defn = strdup(defn)) == NULL)
        return NULL;
    return np;
}
```

## 6.7 Typedef

### Type Definitions:
```c
typedef int Length;
typedef char *String;

Length len, maxlen;
String p, lineptr[MAXLINES], alloc(int);
```

### Structure Typedef:
```c
typedef struct tnode *Treeptr;
typedef struct tnode {
    char *word;
    int count;
    struct tnode *left;
    struct tnode *right;
} Treenode;
```

### Function Pointer Typedef:
```c
typedef int (*PFI)(char *, char *);
PFI strcmp, numcmp;
```

- [Exercise 6.5 - Undefine macro](./chapter06/06_05_undef.c)
- [Exercise 6.6 - Simple version of #define](./chapter06/06_06_define.c)

## 6.8 Unions

### Union Declaration:
```c
union u_tag {
    int ival;
    float fval;
    char *sval;
} u;
```

### Union Usage:
```c
if (utype == INT)
    printf("%d", u.ival);
else if (utype == FLOAT)
    printf("%f", u.fval);
else if (utype == STRING)
    printf("%s", u.sval);
else
    printf("bad type %d in utype", utype);
```

### Union in Structure:
```c
struct {
    char *name;
    int flags;
    int utype;
    union {
        int ival;
        float fval;
        char *sval;
    } u;
} symtab[NSYM];
```

## 6.9 Bit-fields

### Bit-field Declaration:
```c
struct {
    unsigned int is_keyword : 1;
    unsigned int is_extern : 1;
    unsigned int is_static : 1;
} flags;
```

### Bit-field Usage:
```c
flags.is_extern = flags.is_static = 1;
if (flags.is_extern)
    /* ... */;
```

### Example - Date Structure:
```c
struct date {
    unsigned int d : 5;
    unsigned int m : 4;
    unsigned int y : 7;
};
``` 