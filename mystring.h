
/*****************************************************************************
 * Copyright (C) Ganesh Balaji Landge <ganeshlandge936@gmail.com>
 *
 * This program is free software; you can redistribute it and/or modify it
 * under the terms of the GNU Lesser General Public License as published by
 * the Free Software Foundation; either version 2.1 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 * GNU Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public License
 * along with this program; if not, write to the Free Software Foundation,
 * Inc., 51 Franklin Street, Fifth Floor, Boston MA 02110-1301, USA.
 *****************************************************************************/
 
#ifndef _MYSTRING_H
#define _MYSTRING_H

typedef struct hashtable{
	int (*p[14])();
	char *(*q[18])();
	void *(*r[8])();
}ht;

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
char *mystrdupa(const char *);
char *mystrndup(const char *, int);
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
char *mystrtok_r(char *, const char *, char **);
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
#endif
