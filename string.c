
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
 
#include<stdlib.h>
#include <alloca.h>
#include <errno.h>

int mystrlen(const char *str){
	register const char *s;
	for(s = str; *s; ++s);
	return (s - str);
}

char *mystrcpy(char *dest, const char *src){
	char *s = dest;
	for(; *src; ++s, ++src)
		*s = *src;
	*s = '\0';
	return dest;
}

/*mystpcpy() returns a pointer to the end of the string dest (that is,  
* the address of the terminating null byte) rather than the beginning.
*/
char *mystpcpy(char *dest, const char *src){
	for(; *src; ++dest, ++src)
		*dest = *src;
	*dest = '\0';
	return dest;
}

char *mystrncpy(char *dest, const char *src, int n){
	char *s = dest;
	int i = 0;
	for(; *src && i < n; ++s, ++src){
		*s = *src;
		i++;
	}
	while (i < n) {
		*s++ = '\0';
		i++;
	}
	return dest;
}

char *mystrcat(char *dest, char *src){
	char *s = dest;
	while(*s++);
	s--;
	while(*src){
		*s = *src;
		s++;
		src++;
	}
	*s = '\0';
	return dest;
}

char *mystrncat(char *dest, char *src, int n){
	char *s = dest;
	int i = 0;
	while(*s++);
	while(*src && i < n){
		*s = *src;
		s++;
		src++;
		i++;
	}
	*s = '\0';
	return dest;
}

int mystrcmp(char *s1, char *s2){
	while(*s1 == *s2){
		if(*s1 == '\0' && *s2 == '\0')
			return 0;
		s1++;
		s2++;
	}
	return (*s1 - *s2);
}

int mystrcasecmp(char *s1, char *s2){
	char *p = s1;
	char *q = s2;
	while(*p || *q){
		if(*p >= 'A' && *p <= 'Z')
			*p = *p + 32;
		if(*q >= 'A' && *q <= 'Z')
			*q = *q + 32;
		p++;
		q++;
	}
	while(*s1 == *s2){
		if(*s1 == '\0' && *s2 == '\0')
			return 0;
		s1++;
		s2++;
	}
	return (*s1-*s2);
}

int mystrncmp(char *s1, char *s2, int n){
	if(n < 0)
		return mystrcmp(s1, s2);
	while(n > 0){
		if (*s1 != *s2)
	    		return (*(unsigned char *)s1 - *(unsigned char *)s2);
		else if (*s1 == '\0')
	   		 return 0;
		s1++;
		s2++;
		n--;
	}
	return 0;
}

int mystrncasecmp(char *s1, char *s2, int n){
	int i = 0;
	if(n < 0)
		return mystrcasecmp(s1, s2);
	char *p = s1;
	char *q = s2;
	while(*p || *q){
		if(*p >= 'A' && *p <= 'Z')
			*p = *p + 32;
		if(*q >= 'A' && *q <= 'Z')
			*q = *q + 32;
		p++;
		q++;
	}
	while(*s1 == *s2 && i < n){
		if(i == (n-1))
			return 0;
		s1++;
		s2++;
		i++;
	}
	return (*s1-*s2);
}

/* mystrdup() function returns a pointer to a new string which is a duplicate of the string s.  
*  Memory for the new string is obtained  with malloc(3), and can be freed with free(3)
*  user should free the malloced memory
*/
char *mystrdup(const char *str){
	int l = mystrlen(str);
	char *s ;
	if(!(s = (char*) malloc(sizeof(char) * l)))
		return NULL;
	while(*str){
		*s = *str;
		s++;
		str++;
	}
	return (s - l);
}

/* the mystrdupa()  are  similar to mystrdup  
*  but use alloca(3) to allocate the buffer
*/
char *mystrdupa(const char *str){
	int l = mystrlen(str);
	char *s = (char*) alloca(sizeof(char) * l);
	while(*str){
		*s = *str;
		s++;
		str++;
	}
	return (s - l);
}

/* The mystrndup() function is similar, but copies at most n bytes. If s is longer 
*  than n, only n bytes are copied,  and  a  terminating null byte ('\0') is added.
*  user should free the malloced memory
*/
char *mystrndup(const char *str, int n){
	int i = 0, l = mystrlen(str);
	if(n > l || n < 0)
		return mystrdup(str);
	char *s = (char*) malloc(sizeof(char) * l);
	while(i < n){
		*s = *str;
		s++;
		str++;
		i++;
	}
	return (s - i);
}

char *mystrrev(char *str){
	int n, j, k;
	char ch;
	j = mystrlen(str);
	char *s = str;
	for(n = 0, k = j -1; n < ((j + 1) / 2 ); n++, k--){
		ch = s[n];
		s[n] = s[k];
		s[k] = ch;
	}
	return str;
}

/*checks from first to last character
*/
char *mystrchr(char *str, int c){
	char ch = c;
	while(*str){
		if(*str == ch)
			return str;
		str++;
	}
	if(*str == ch)			//for last null (\0) byte if c = '\0'
		return str;
	else
		return NULL;
}

/*checks from last to first character
*/
char *mystrrchr(char *str, int c){
	char ch = c;
	int l = mystrlen(str);
	while(l >= 0){
		if(*(str + l) == ch)
			return (str + l);
		l--;
	}
	return NULL;
}

/*The  mystrpbrk() function locates the first occurrence in 
* the string s of any of the bytes in the string accept		
*/
char *mystrpbrk(char *s, char *accept){
	char *str = accept;
	while(*s){
		while(*accept){
			if(*s == *accept)
				return s;
			accept++;
		}
		s++;
		accept = str;
 	}
 	return NULL;
}

/* This function calculates the length of the initial segment of s 
*  which consists entirely of bytes not in reject.
*/
int mystrcspn(char *s, char *reject){
	int n = 0;
	char *str = reject;
	while(*s){
		while(*reject){
			if(*s == *reject)
				return n;
			reject++;
		}
		s++;
		n++;
		reject = str;
 	}
 	return n;
}

/* The  mystrspn()  function calculates the length (in bytes) of 
 *  initial segment of s which consists entirely of bytes in accept.
 */
int mystrspn(char *s, char *accept){
	int n = 0, k;
	char *str = accept;
	while(*s){
		k = 0;
		while(*accept){
			if(*s == *accept){
				k++;
				n++;
				break;
			}
			accept++;
		}
		if(k == 0)
			return n;
		s++;
		accept = str;
 	}
 	return n;
}	

/*mystrreplace replaces string orig with string new
* string orig is part of string text
* returns the number of occurence of orig in text
*/
int mystrreplace(char *text, char *orig, char *new){
	int l1, l2, l3, i, t[10], j, k = 0, m = 0, c = 0, count = 0;	
	char tex[128];
	l1 = mystrlen(text);
	l2 = mystrlen(orig);
	l3 = mystrlen(new);
	for(i = 0; i < l1; ){
		j = 0;
		c = 0;
		while((text[i] == orig[j]) && text[i] != '\0'){
			c++;
			i++;
			j++;
		}
		if(c == l2){
			count++;
			t[k] = i - l2;
			k++;
		}
		else if(c == 0)
			i++;
	}
	i = 0;
	k = 0;
	j = 0;
	while(i < (l1 + (count * abs(l3 - l2)))){
		if(i == t[k] ){
			while(m < l3){
				tex[j] =new[m];
				j++;
				m++;
			}			
			k++;
			m = 0;
			i = i +l2;	
		}				
		else{
			tex[j] = text[i];
			i++;
			j++;
		}
	}
	tex[j] = '\0';
	mystrcpy(text, tex);
	return count;
}

/*Find  the first occurrence of the substring substr in the string
* str, returning a pointer to the found substring
* returns NULL otherwise
*/
char *mystrstr(char *str, const char *substr){
	int l1, l2, i, j, k, c = 0;	
	l1 = mystrlen(str);
	l2 = mystrlen(substr);
	for(k = 0; k < l1; k++){
		i = k;
		j = 0;
		c = 0;
		while((str[i] == substr[j]) && str[i] != '\0'){
			c++;
			i++;
			j++;
		}
		if(c == l2){
			return str + k;
		}
	}
	return NULL;
}

/* The  strtok() function breaks a string into a sequence of zero or more nonempty tokens  
*  On the first call to strtok() the string to be parsed should be specified in str.  
*  In each subsequent call that should parse the same string, str must be NULL.
*/
char *mystrtok(char *str, char *del){
	static char *p;
	if(str != NULL) 
		p = str;
	int k = 0; 
	static int l; 
	if(str != NULL) 
		l = mystrlen(str);
	char *d;
	while(*p){
		d = del;
		while(*d){
			if(*d == *p){
				*p = '\0';
				if(k == 0){
					d = del;
					p++;
				}
				else{
					p++;
					return (p - k - 1);
				}
			}
			else
				d++;
		}
		p++;
		k++;			
	}
	if(k != l && k != 0)
		return (p - k);
	else
		return (NULL);
}


/*
 * thread-safe version of strtok
 */
 char *mystrtok_r(char *s, const char *delim, char **lasts){
         const char *spanp;
         int c, sc;
         char *tok;
         if (s == NULL && (s = *lasts) == NULL)
                 return (NULL);
cont:
         c = *s++;
         for (spanp = delim; (sc = *spanp++) != 0;) {
                 if (c == sc)
                         goto cont;
         }
 
         if (c == 0) {           /* no non-delimiter characters */
                *lasts = NULL;
                 return (NULL);
         }
         tok = s - 1;
         for (;;) {
                c = *s++;
                 spanp = delim;
                 do {
                       if ((sc = *spanp++) == c) {
                              if (c == 0)
                                         s = NULL;
                                else
                                       s[-1] = 0;
                                 *lasts = s;
                              return (tok);
                     }
               } while (sc != 0);
       }
}

/*mystrfry()  function  randomizes  the  contents  of  string by using
* rand(3) to randomly swap characters in the string.  The  result  is  an
* anagram of string
*/
char *mystrfry(char *str){
	unsigned int i, j, l, seed = 0;
	char ch;
	l = mystrlen(str);
	srand(seed);
	for(i = 0; i < l - 1; i++){
		j = rand() % l;
		ch = str[i];
		str[i] = str[j];
		str[j] = ch;
	}
	return str; 
}

/*checks from first to last character
*/
char *myindex(char *str, int c){
	char ch = c;
	while(*str){
		if(*str == ch)
			return str;
		str++;
	}
	if(*str == ch)			//for last null (\0) byte if c = '\0'
		return str;
	else
		return NULL;
}

/*checks from last to first character
*/
char *myrindex(char *str, int c){
	char ch = c;
	int l = mystrlen(str);
	while(l >= 0){
		if(*(str + l) == ch)
			return (str + l);
		l--;
	}
	return NULL;
}

/*this functiion searches for the first occurrence of the character c (an unsigned char) 
* in the first n bytes of the string pointed to, by the argument str
*/
void *mymemchr(void *s, int c, size_t n){
	char *str = s;
	while(n != 0){
		if(*str == c)
			return ((void *) str);
		str++;
		n--;
	}
	if(*str == c)			//for last null (\0) byte if c = '\0'
		return ((void *) str);
	else
		return NULL;
}

/*this function is same as memchr but it starts from last byte and searches backward
*/		
void *mymemrchr(void *s, int c, size_t n){
	char *str;
	if(mystrlen((char *)s) > n)
		str = (char *)s + n;
	else{
		str = (char *)s + mystrlen((char *)s);
		n = mystrlen((char *)s);
	}
	while(n != -1){
		if(*(--str) == c)
			return ((void *)str);
		n--;
	}
	return ((void *) 0);
}

/* same as strncmp
*/
int mymemcmp(void *str1, void *str2, size_t n){
	int i = 0;
	char *s1 = str1;
	char *s2 = str2;
	if(n == 0)
		return 0;
	if(n < 0)
		return mystrncmp(s1, s2, n);
	while(*s1 == *s2 && i < n){
		if(i == (n-1))
			return 0;
		s1++;
		s2++;
		i++;
	}
	return (*s1-*s2);
}

/*Find  the first occurrence of the substring substr in the string
* str, returning a pointer to the found substring
* returns NULL otherwise
*/
void *mymemmem(void *s, size_t strlen, void *subs, size_t substrlen){
	char *str = s;
	char *substr = subs;
	int i, j, k, c = 0;	
	for(k = 0; k < strlen; k++){
		i = k;
		j = 0;
		c = 0;
		while((str[i] == substr[j]) && str[i] != '\0'){
			c++;
			i++;
			j++;
		}
		if(c == substrlen){
			return str + k;
		}
	}
	return NULL;
}

/* just like strncpy
*/
void *mymemcpy(void *dest, const void *sc, size_t n){
	char *s = dest;
	const char *src = sc;
	int i = 0;
	for(; i < n; ++s, ++src){
		*s = *src;
		i++;
	}
	return dest;
}

/* just like stpcpy
*/
void *mymempcpy(void *s1, const void *s2, size_t n){
	char *dest = s1;
	const char *src = s2;
	int i = 0;
	for(; i < n; ++dest, ++src){
		*dest = *src;
		i++;
	}
	return (s1 + n);
}

/* The memccpy() function returns a pointer to the next character in dest after c, 
*   or NULL if c was not found in the first n characters of src.
*/
void *mymemccpy(void *s1, const void *s2, int c, size_t n){
	char *dest = s1;
	const char *src = s2;
	int i = 0;
	for(; i < n; ++dest, ++src){
		if(*src == c)
			break;
		*dest = *src;
		i++;
	}
	if(i == n)
		return NULL;
	else
		return (s1 + i + 1);
}

/*The mymemset() function fills the first n bytes of the memory area pointed to by s with the constant byte c.
*/
void *mymemset(void *s, int c, size_t n){
	char *str = s;
	int k = n;
	char *s1;
	s1 = (char *)malloc(64);
	mystrcpy(s1, s);
	while(n != 0){
		*str = c;
		str++;
		n--;
	}
	if(k > mystrlen(s1))
		*str = '\0';
	free(s1);
	return s;
}

/* counts the occurence of substr in str
*/ 
int mystrword(char *str, char *substr){
	int i, c, j, l1, l2, count = 0;
	l1 = mystrlen(str);
	l2 = mystrlen(substr);
	for(i = 0; i < l1; ){
		j = 0;
		c = 0;
		while((str[i] == substr[j]) && str[i] != '\0'){
			c++;
			i++;
			j++;
		}
		if(c == l2)
			count++;
		else if(c == 0)
			i++;
	}
	return count;
}

/* This function sets the first n bytes of the area starting at s to zero (bytes
*  containing '\0')
*/
void mybzero(void *s, size_t n){
	char *str = s;
	while(n != 0){
		*str = '\0';
		str++;
		n--;
	}
} 

/*function compares the two byte sequences s1 and s2 of length n each.  If
* they are equal, and in particular if n is zero, bcmp()  returns  0.   Otherwise,  it
* returns a nonzero result.
*/
int mybcmp(void *str1, void *str2, size_t n){
	int i = 0;
	char *s1 = str1;
	char *s2 = str2;
	if(n == 0)
		return 0;
	if(n < 0)
		return mystrcmp(s1, s2);
	while(*s1 == *s2 && i < n){
		if(i == (n-1))
			return 0;
		s1++;
		s2++;
		i++;
	}
	return (*s1-*s2);
}

/* This function encrypts the first n bytes of the memory area s
*  by exclusive-ORing each character with the number 42.  The  effect  can
*  be reversed by using memfrob() on the encrypted memory area.
*/
void *mymemfrob(void *str, size_t n){
	char *s = str;
	while(n != 0){
		*s = *s ^ 42;
		s++;
		n--;
	}
	return str;
}

/* The myffs() function returns the position of the  
*  first  (least  significant)  bit  set in the word n
*/
int myffs(int n){
	int bit = 1;
	if(n == 0 )
		return 0;
	while(!(n & 1)){
		n = n >> 1;
		bit++;
	}
	return bit;
}

/* same as ffs only accept long type argument
*/
int myffsl(long n){
	int bit = 1;
	if(n == 0 )
		return 0;
	while(!(n & 1)){
		n = n >> 1;
		bit++;
	}
	return bit;
}

/* same as ffs only accept long long type argument
*/
int myffsll(long long  n){
	int bit = 1;
	if(n == 0 )
		return 0;
	while(!(n & 1)){
		n = n >> 1;
		bit++;
	}
	return bit;
}

/* Sets the first n character of str with the character ch 
*/
char *mystrnset(const char *str, char ch, int n){
	char *newstr = str;
	if( n < 0 || n > mystrlen(newstr)) {
		return NULL;
	}
	int i = 0;
	for(; i < n; ++newstr, ++i){
		*newstr = ch;
	}
	return newstr;
}


















