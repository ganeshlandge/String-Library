int mystrlen(const char *);
char *mystrcpy(char *, const char *);
char *mystpcpy(char *, const char *);
char *mystrncpy(char *, const char *, int);
char *mystrcat(char *, char *);
char *mystrncat(char *, char *, int);
int mystrcmp(char *, char *);
int mystrcasecmp(char *, char *);
int mystrncmp(char *, char *, int);
int mystrncasecmp(char *, char *, int);
char *mystrdup(const char *);
//is this function in string.h
//giving wierd outpt
char *mystrdupa(const char *);
char *mystrndup(const char *, int);
//is this function in string.h
//giving wierd outpt
char *mystrndupa(const char *, size_t);
char *mystrrev(char *);
char *mystrchr(char *, int);
char *mystrrchr(char *, int);
char *mystrpbrk(char *, char *);
int mystrcspn(char *, char *);
int mystrspn(char *, char *);
int mystrreplace(char *, char *, char *);
char *mystrstr(char *, const char *);
char *mystrtok(char *, char *);
char *strtok_r(char *, const char *, char **);
char *mystrfry(char *);
char *myindex(const char *, int );
char *myrindex(const char *, int );
void *mymemchr(void *, int , size_t );
void *mymemrchr(void *, int , size_t );
int mymemcmp(const void *, const void *, size_t);

void *mymemmem(void *, size_t, void *, size_t);
void *mymemcpy(void *, const void *, size_t);
void *mymempcpy(void *, const void *, size_t);
void *mymemccpy(void *, const void *, int, size_t);

void *mymemset(void *, int, size_t);
int mystrword(char *, char *);
void mybzero(void *, size_t); 
int mybcmp(void *, void *, size_t);
void *mymemfrob(void *, size_t);
int myffs(int);
int myffsl(long );
int myffsll(long long );
int mystrcoll_l(const char *, const char *, locale_t loc);
int mystrcoll(const char *, const char *);
size_t mystrxfrm(char *, const char *, size_t);

