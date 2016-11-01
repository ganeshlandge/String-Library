
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
 
#include<stdio.h>
#include<stdlib.h>
#include"mystring.h"

const ht h =  { { mystrlen, mystrcmp, mystrcasecmp, mystrncmp, mystrncasecmp, mystrcspn, mystrspn, mystrreplace, mymemcmp, mystrword, 				mybcmp, myffs, myffsl, myffsll },
		{ mystrcpy, mystpcpy, mystrncpy, mystrcat, mystrncat, mystrdup, mystrdupa, mystrndup, mystrrev, mystrchr, 				mystrrchr, mystrpbrk, mystrstr, mystrtok, mystrtok_r, mystrfry, myindex, myrindex }, 
		{ mymemchr, mymemrchr, mymemmem, mymemcpy, mymempcpy, mymemccpy, mymemset, mymemfrob }
	      };

int hash(char *str){
	int key = 0;
	char *p = str + 4;
	if(!h.p[1](str, "mystrcmp"))
		return 440;
	if(!h.p[1](str, "mystrncat"))
		return 543;
	if(!h.p[1](str, "mystrtok_r"))
		return 1;
	while(*p){
		key = key + *p;
		p++;
	}
	p = p - 2;
	key = key + (((*p % 11) + (*(p + 1) / 7)) % 19);
	return key;
}

void checkstrlen(FILE *fp){
	int m, n;
	char *s = (char *) malloc(128); 
	fscanf(fp, "%s", s);
	if(!mystrcmp(s, "0"))
		mystrcpy(s, "\0");
	n = h.p[0](s);
	fscanf(fp, "%d", &m);
	if(n == m)
		printf("mystrlen Successful\n");
	else
		printf("mystrlen Unsuccessful\tlength of string is %d\n", n);
	free(s);
}

void checkstrcpy(FILE *fp){
   	char s[16], s1[16];
	fscanf(fp, "%s", s);
	if(!mystrcmp(s, "0"))
		mystrcpy(s, "\0");
	fscanf(fp, "%s", s1);
	if(!mystrcmp(s1, "0"))
		mystrcpy(s1, "\0");
	h.q[0](s, s1);
	if(!h.p[1](s, s1))
		printf("mystrcpy Successful\n");
	else
		printf("mystrcpy Unsuccessful\n");
}

void checkstpcpy(FILE *fp){
	char s[16], s1[16];
	char *s2;
	fscanf(fp, "%s", s);
	if(!mystrcmp(s, "0"))
		mystrcpy(s, "\0");
	fscanf(fp, "%s", s1);
	if(!mystrcmp(s1, "0"))
		mystrcpy(s1, "\0");
	s2 = h.q[1](s, s1);
	if(!h.p[1](s, s1) && *s2 == '\0')
		printf("mystpcpy Successful\n");
	else
		printf("mystpcpy Unsuccessful\n");
}

void checkstrncpy(FILE *fp){
	char s[16], s1[16];
	int m;
	fscanf(fp, "%s", s);
	if(!mystrcmp(s, "0"))
		mystrcpy(s, "\0");
	fscanf(fp, "%s", s1);
	if(!mystrcmp(s1, "0"))
		mystrcpy(s1, "\0");
	fscanf(fp, "%d", &m);
	h.q[2](s, s1, m);
	if(!h.p[3](s, s1, m))
		printf("mystrncpy Successful\n");
	else
		printf("mystrncpy Unsuccessful\t%d bytes of string %s can't be copied to string %s\n", m, s1, s);
}

void checkstrcat(FILE *fp){
	char s[16], s1[16];
	fscanf(fp, "%s", s);
	if(!mystrcmp(s, "0"))
		mystrcpy(s, "\0");
	fscanf(fp, "%s", s1);
	if(!mystrcmp(s1, "0"))
		mystrcpy(s1, "\0");
	h.q[3](s, s1);
	if(1)
		printf("mystrcat Successful\n");
	else
		printf("mystrcat Unsuccessful\n");
}

void checkstrncat(FILE *fp){
	char s[16], s1[16];
	int m;
	fscanf(fp, "%s", s);
	if(!mystrcmp(s, "0"))
		mystrcpy(s, "\0");
	fscanf(fp, "%s", s1);
	if(!mystrcmp(s1, "0"))
		mystrcpy(s1, "\0");
	fscanf(fp, "%d", &m);
	h.q[4](s, s1, m);
	if(1)
		printf("mystrcat Successful\n");
	else
		printf("mystrcat Unsuccessful\n");
}

void checkstrcmp(FILE *fp){
	char s[16], s1[16];
	int n, m;
	fscanf(fp, "%s", s);
	if(!mystrcmp(s, "0"))
		mystrcpy(s, "\0");
	fscanf(fp, "%s", s1);
	if(!mystrcmp(s1, "0"))
		mystrcpy(s1, "\0");
	n = h.p[1](s, s1);
	fscanf(fp, "%d", &m);
	if((n == 0 && m == 0) || (n > 0 && m > 0) || (n < 0 && m < 0))
		printf("mystrcmp Successful\n");
	else if(n > 0 && m < 0)
		printf("mystrcmp Unsuccessful\t%s is bigger than %s\n", s, s1);
	else if(n < 0 && m > 0)
		printf("mystrcmp Unsuccessful\t%s is smaller than %s\n", s, s1);
	else if( n == 0 && m != 0)
		printf("mystrcmp Unsuccessful\t%s is equal to %s\n", s, s1);
}

void checkstrcasecmp(FILE *fp){
	char s[16], s1[16];
	int n, m;
	fscanf(fp, "%s", s);
	if(!mystrcmp(s, "0"))
		mystrcpy(s, "\0");
	fscanf(fp, "%s", s1);
	if(!mystrcmp(s1, "0"))
		mystrcpy(s1, "\0");
	n = h.p[2](s, s1);
	fscanf(fp, "%d", &m);
	if((n == 0 && m == 0) || (n > 0 && m > 0) || (n < 0 && m < 0))
		printf("mystrcasecmp Successful\n");
	else if(n > 0 && m < 0)
		printf("mystrcasecmp Unsuccessful\t%s is bigger than %s\n", s, s1);
	else if(n < 0 && m > 0)
		printf("mystrcasecmp Unsuccessful\t%s is smaller than %s\n", s, s1);
	else if( n == 0 && m != 0)
		printf("mystrcmp Unsuccessful\t%s is equal to %s\n", s, s1);
}

void checkstrncmp(FILE *fp){
	char s[16], s1[16];
	int n, m,  k;
	fscanf(fp, "%s", s);
	if(!mystrcmp(s, "0"))
		mystrcpy(s, "\0");
	fscanf(fp, "%s", s1);
	if(!mystrcmp(s1, "0"))
		mystrcpy(s1, "\0");
	fscanf(fp, "%d", &m);
	n = h.p[3](s, s1, m);
	fscanf(fp, "%d", &k);
	if((n == 0 && k == 0) || (n > 0 && k > 0) || (n < 0 && k < 0))
		printf("mystrncmp Successful\n");
	else if(n > 0 && k < 0)
		printf("mystrncmp Unsuccessful\t%s is bigger than %s\n", s, s1);
	else if(n < 0 && m > 0)
		printf("mystrncmp Unsuccessful\t%s is smaller than %s\n", s, s1);
	else if( n == 0 && m != 0)
		printf("mystrcmp Unsuccessful\t%s is equal to %s\n", s, s1);
}

void checkstrncasecmp(FILE *fp){
	char s[16], s1[16];
	int n, m, k;
	fscanf(fp, "%s", s);
	if(!mystrcmp(s, "0"))
		mystrcpy(s, "\0");
	fscanf(fp, "%s", s1);
	if(!mystrcmp(s1, "0"))
		mystrcpy(s1, "\0");
	fscanf(fp, "%d", &m);
	n = h.p[3](s, s1, m);
	fscanf(fp, "%d", &k);
	if((n == 0 && k == 0) || (n > 0 && k > 0) || (n < 0 && k < 0))
		printf("mystrncasecmp Successful\n");
	else if(n > 0 && k < 0)
		printf("mystrncasecmp Unsuccessful\t%s is bigger than %s\n", s, s1);
	else if(n < 0 && m > 0)
		printf("mystrncasecmp Unsuccessful\t%s is smaller than %s\n", s, s1);
	else if( n == 0 && m != 0)
		printf("mystrcmp Unsuccessful\t%s is equal to %s\n", s, s1);
}

void checkstrdup(FILE *fp){
	char s[16], s1[16];
	char *s2 = (char*) malloc(16);
	fscanf(fp, "%s", s);
	if(!mystrcmp(s, "0"))
		mystrcpy(s, "\0");
	fscanf(fp, "%s", s1);
	if(!mystrcmp(s1, "0"))
		mystrcpy(s1, "\0");
	s2 = h.q[5](s);
	if(!h.p[1](s2, s1))
		printf("mystrdup Successful\n");
	else
		printf("mystrdup Unsuccessful\tstrings %s and %s are different\n", s, s1);
	free(s2);
}

void checkstrdupa(FILE *fp){
	char s[16], s1[16];
	char *s2;
	fscanf(fp, "%s", s);
	if(!mystrcmp(s, "0"))
		mystrcpy(s, "\0");
	fscanf(fp, "%s", s1);
	if(!mystrcmp(s1, "0"))
		mystrcpy(s1, "\0");
	s2 = h.q[6](s);
	if(!h.p[3](s1, s2, h.p[0](s)))
		printf("mystrdupa Successful\n");
	else
		printf("mystrdupa Unsuccessful\tstrings %s and %s are different\n", s2, s1);
}

void checkstrndup(FILE *fp){
	char s[16], s1[16];
	int m;
	char *s2 = (char*) malloc(16);
	fscanf(fp, "%s", s);
	if(!mystrcmp(s, "0"))
		mystrcpy(s, "\0");
	fscanf(fp, "%d", &m);
	fscanf(fp, "%s", s1);
	if(!mystrcmp(s1, "0"))
		mystrcpy(s1, "\0");
	s2 = h.q[7](s, m);
	if(!h.p[1](s2,  s1))
		printf("mystrndup Successful\n");
	else
		printf("mystrndup Unsuccessful\tstrings %s and %s are different\n", s, s1);
	free(s2);
}

void checkstrrev(FILE *fp){
	char s[16], s1[16];	
	fscanf(fp, "%s", s);
	if(!mystrcmp(s, "0"))
		mystrcpy(s, "\0");
	fscanf(fp, "%s", s1);
	if(!mystrcmp(s1, "0"))
		mystrcpy(s1, "\0");
	h.q[8](s);
	if(!h.p[1](s,s1))
		printf("mystrrev Successful\n");
	else
		printf("mystrrev Unsuccessful\treversed string is %s\n", s);
}

void checkstrchr(FILE *fp){
	char *s, ch[1], *s1;
	s = (char*) malloc(16);
	fscanf(fp, "%s", s);
	if(!mystrcmp(s, "0"))
		mystrcpy(s, "\0");
	fscanf(fp, "%s", ch);
	if(!mystrcmp(ch, "0"))
		mystrcpy(ch, "\0");
	s1 = h.q[9](s, ch[0]);
	if(s1 != NULL)
		printf("mystrchr Successful\n");
	else
		printf("mystrchr Unsuccessful\tcharacter %c is not found in given string\n", ch[0]);
	free(s);
}

void checkstrrchr(FILE *fp){
	char *s, ch[1], *s1;
	s = (char*) malloc(16);
	fscanf(fp, "%s", s);
	if(!mystrcmp(s, "0"))
		mystrcpy(s, "\0");
	fscanf(fp, "%s", ch);
	if(!mystrcmp(ch, "0"))
		mystrcpy(ch, "\0");
	s1 = h.q[10](s, ch[0]);
	if(s1 != NULL)
		printf("mystrrchr Successful\n");
	else
		printf("mystrrchr Unsuccessful\tcharacter %c is not found in given string\n", ch[0]);
	free(s);
}

void checkstrpbrk(FILE *fp){
	char *s, s1[16];
	char *s2;
	s = (char *) malloc(16);	
	fscanf(fp, "%s", s);
	if(!mystrcmp(s, "0"))
		mystrcpy(s, "\0");
	fscanf(fp, "%s", s1);
	if(!mystrcmp(s1, "0"))
		mystrcpy(s1, "\0");
	s2 = h.q[11](s, s1);
	if(s2 != NULL)
		printf("mystrpbrk Successful\tthe character '%c' in string %s is found in string %s\n", s2[0], s1, s);
	else
		printf("mystrpbrk Successful\tthe string %s does not contain any bytes in string %s\n", s, s1);
	free(s);	 
}

void checkstrcspn(FILE *fp){
	char s[16], s1[16];
	int m, n;	
	fscanf(fp, "%s", s);
	if(!mystrcmp(s, "0"))
		mystrcpy(s, "\0");
	fscanf(fp, "%s", s1);
	if(!mystrcmp(s1, "0"))
		mystrcpy(s1, "\0");
	fscanf(fp, "%d", &n);
	m = h.p[5](s, s1);
	if(n == m)
		printf("mystrcspn Successful\n");
	else
		printf("mystrcspn Unsuccessful\tthere are %d bytes in string %s which are not in string %s\n", m, s, s1);
}

void checkstrspn(FILE *fp){
	char s[128], s1[128];
	int m, n;	
	fscanf(fp, "%s", s);
	if(!mystrcmp(s, "0"))
		mystrcpy(s, "\0");
	fscanf(fp, "%s", s1);
	if(!mystrcmp(s1, "0"))
		mystrcpy(s1, "\0");
	fscanf(fp, "%d", &n);
	m = h.p[6](s, s1);
	if(n == m)
		printf("mystrspn Successful\n");
	else
		printf("mystrspn Unsuccessful\tthere are %d bytes in string %s which are in string %s\n", m, s, s1);
}

void checkstrreplace(FILE *fp){
	char s[128], s1[64], s2[64];
	int m, n;	
	fscanf(fp, "%s", s);
	if(!mystrcmp(s, "0"))
		mystrcpy(s, "\0");
	fscanf(fp, "%s", s1);
	if(!mystrcmp(s1, "0"))
		mystrcpy(s1, "\0");
	fscanf(fp, "%s", s2);
	if(!mystrcmp(s2, "0"))
		mystrcpy(s2, "\0");
	fscanf(fp, "%d", &n);
	m = h.p[7](s, s1, s2);
	if(m == 0 && n == 0)
		printf("mystrreplace Successful\t         string %s does not contain string %s\n", s, s1);
	else if(n == m)
		printf("mystrreplace Successful\t         replaced string is %s\n", s);
	else
		printf("mystrreplace Unsuccessful\t string %s occure %d times in string %s\n", s2, m, s);
}

void checkstrword(FILE *fp){
	char s[128], s1[64];
	int m, n;	
	fscanf(fp, "%s", s);
	if(!mystrcmp(s, "0"))
		mystrcpy(s, "\0");
	fscanf(fp, "%s", s1);
	if(!mystrcmp(s1, "0"))
		mystrcpy(s1, "\0");
	fscanf(fp, "%d", &n);
	m = h.p[9](s, s1);
	if(n == m)
		printf("mystrword Successful\n");
	else
		printf("mystrword Unsuccessful\t string %s occure %d times in string %s\n", s1, m, s);
}

void checkstrstr(FILE *fp){
	char s[128], s1[64];
	char *s2;	
	fscanf(fp, "%s", s);
	if(!mystrcmp(s, "0"))
		mystrcpy(s, "\0");
	fscanf(fp, "%s", s1);
	if(!mystrcmp(s1, "0"))
		mystrcpy(s1, "\0");
	s2 = h.q[12](s, s1);
	if(s2 != NULL)
		printf("mystrstr Successful\n");
	else
		printf("mystrstr Unsuccessful\t string %s not found in string %s\n", s1, s);
}


void checkstrtok(FILE *fp){
	char *s, s1[32];
	char *s2;
	s = (char *) malloc(128);	
	fscanf(fp, "%s", s);
	if(!mystrcmp(s, "0"))
		mystrcpy(s, "\0");
	fscanf(fp, "%s", s1);
	if(!mystrcmp(s1, "0"))
		mystrcpy(s1, "\0");
	s2 = h.q[13](s, s1);
	printf("mystrtok Successful\t");
	printf("seperated strings are ");
	while(s2 != NULL){
		printf("'%s' ", s2);
		s2 = h.q[13](NULL, s1);
	}
	printf("\n");
	free(s);
}


void checkstrtok_r(FILE *fp){
	char *s, s1[32];
	char *s2, *tmp;
	s = (char *) malloc(128);	
	fscanf(fp, "%s", s);
	if(!mystrcmp(s, "0"))
		mystrcpy(s, "\0");
	fscanf(fp, "%s", s1);
	if(!mystrcmp(s1, "0"))
		mystrcpy(s1, "\0");
	s2 = h.q[14](s, s1, &tmp);
	printf("mystrtok_r Successful\t");
	printf("seperated strings are ");
	while(s2 != NULL){
		printf("'%s' ", s2);
		s2 = h.q[14](NULL, s1, &tmp);
	}
	printf("\n");
	free(s);
}


void checkstrfry(FILE *fp){
	char s[16], s1[16];
	fscanf(fp, "%s", s);
	h.q[1](s1, s);
	if(!mystrcmp(s, "0"))
		mystrcpy(s, "\0");
	h.q[15](s);
	printf("Successful anagram of string %s is %s\n", s1, s);
}

void checkindex(FILE *fp){
	char *s, ch[1], *s1;
	s = (char*) malloc(16);
	fscanf(fp, "%s", s);
	if(!mystrcmp(s, "0"))
		mystrcpy(s, "\0");
	fscanf(fp, "%s", ch);
	if(!mystrcmp(ch, "0"))
		mystrcpy(ch, "\0");
	s1 = h.q[15](s, ch[0]);
	if(s1 != NULL)
		printf("myindex Successful\n");
	else
		printf("myindex Unsuccessful\tcharacter %c is not found in given string\n", ch[0]);
	free(s);
}

void checkrindex(FILE *fp){
	char *s, ch[1], *s1;
	s = (char*) malloc(16);
	fscanf(fp, "%s", s);
	if(!mystrcmp(s, "0"))
		mystrcpy(s, "\0");
	fscanf(fp, "%s", ch);
	if(!mystrcmp(ch, "0"))
		mystrcpy(ch, "\0");
	s1 = h.q[16](s, ch[0]);
	if(s1 != NULL)
		printf("myrindex Successful\n");
	else
		printf("myrindex Unsuccessful\tcharacter %c is not found in given string\n", ch[0]);
	free(s);
}

void checkmemchr(FILE *fp){
	char *s, ch[1], *s1;
	int n;
	s = (char*) malloc(16);
	fscanf(fp, "%s", s);
	if(!mystrcmp(s, "0"))
		mystrcpy(s, "\0");
	fscanf(fp, "%s", ch);
	if(!mystrcmp(ch, "0"))
		mystrcpy(ch, "\0");
	fscanf(fp, "%d", &n);
	s1 = (char *)h.r[1](s, ch[0]);
	if(s1 != NULL)
		printf("mymemchr Successful\n");
	else
		printf("mymemchr Unsuccessful\tcharacter %c is not found in given string\n", ch[0]);
	free(s);
}

void checkmemrchr(FILE *fp){
	char *s, ch[1], *s1;
	int n;
	s = (char*) malloc(16);
	fscanf(fp, "%s", s);
	if(!mystrcmp(s, "0"))
		mystrcpy(s, "\0");
	fscanf(fp, "%s", ch);
	if(!mystrcmp(ch, "0"))
		mystrcpy(ch, "\0");
	fscanf(fp, "%d", &n);
	s1 = (char *)h.r[1](s, ch[0], n);
	if(s1 != NULL)
		printf("mymemrchr Successful\n");
	else
		printf("mymemrchr Unsuccessful\tcharacter %c is not found in given string\n", ch[0]);
	free(s);
}

void checkmemcmp(FILE *fp){
	char s[16], s1[16];
	int n, m, k;
	fscanf(fp, "%s", s);
	if(!mystrcmp(s, "0"))
		mystrcpy(s, "\0");
	fscanf(fp, "%s", s1);
	if(!mystrcmp(s1, "0"))
		mystrcpy(s1, "\0");
	fscanf(fp, "%d", &k);
	n = h.p[8](s, s1, k);
	fscanf(fp, "%d", &m);
	if((n == 0 && m == 0) || (n > 0 && m > 0) || (n < 0 && m < 0))
		printf("mymemcmp Successful\n");
	else if(n > 0 && m < 0)
		printf("mymemcmp Unsuccessful\t%s is bigger than %s\n", s, s1);
	else
		printf("mymemcmp Unsuccessful\t%s is smaller than %s\n", s, s1);
}

void checkmemmem(FILE *fp){
	char *s, ch[64], *s1;
	int m, n;
	s = (char*) malloc(16);
	fscanf(fp, "%s", s);
	if(!mystrcmp(s, "0"))
		mystrcpy(s, "\0");
	fscanf(fp, "%d", &n);
	fscanf(fp, "%s", ch);
	if(!mystrcmp(ch, "0"))
		mystrcpy(ch, "\0");
	fscanf(fp, "%d", &m);
	s1 = h.r[2](s, n, ch, m);
	if(s1 != NULL)
		printf("mymemmem Successful\n");
	else
		printf("mymemmem Unsuccessful\tstring %s is not found in given string %s\n", ch, s);
}

void checkmemcpy(FILE *fp){
	char s[16], s1[16];
	int m;
	fscanf(fp, "%s", s);
	if(!mystrcmp(s, "0"))
		mystrcpy(s, "\0");
	fscanf(fp, "%s", s1);
	if(!mystrcmp(s1, "0"))
		mystrcpy(s1, "\0");
	fscanf(fp, "%d", &m);
	h.r[3](s, s1, m);
	if(!h.p[3](s, s1, m))
		printf("mymemcpy Successful\n");
	else
		printf("mymemcpy Unsuccessful\n");
}

void checkmempcpy(FILE *fp){
	char s[16], s1[16];
	int m;
	fscanf(fp, "%s", s);
	if(!mystrcmp(s, "0"))
		mystrcpy(s, "\0");
	fscanf(fp, "%s", s1);
	if(!mystrcmp(s1, "0"))
		mystrcpy(s1, "\0");
	fscanf(fp, "%d", &m);
	h.r[4](s, s1, m);
	if(!h.p[3](s, s1, m))
		printf("mystpcpy Successful\n");
	else
		printf("mystpcpy Unsuccessful\n");
}

void checkmemccpy(FILE *fp){
	char s[16], s1[16], s2[1];
	int m;
	fscanf(fp, "%s", s);
	if(!mystrcmp(s, "0"))
		mystrcpy(s, "\0");
	fscanf(fp, "%s", s1);
	if(!mystrcmp(s1, "0"))
		mystrcpy(s1, "\0");
	fscanf(fp, "%s", s2);
	if(!mystrcmp(s2, "0"))
		mystrcpy(s2, "\0");
	fscanf(fp, "%d", &m);
	h.r[5](s, s1, s2[0], m);
	if(1)
		printf("mymemccpy Successful\n");
	else
		printf("mymemccpy Successful\n");
}

void checkmemset(FILE *fp){
	char *s, s1[1];
	int m;
	s = (char *)malloc(64);
	fscanf(fp, "%s", s);
	if(!mystrcmp(s, "0"))
		mystrcpy(s, "\0");
	fscanf(fp, "%s", s1);
	if(!mystrcmp(s1, "0"))
		mystrcpy(s1, "\0");
	fscanf(fp, "%d", &m);
	h.r[6](s, s1[0], m);
	if(1)
		printf("mymemset Successful\tcopied string is %s\n", s);
	else
		printf("mymemset Unsuccessful\n");
	free(s);
}

void checkbcmp(FILE *fp){
	char s[16], s1[16];
	int n, m,  k;
	fscanf(fp, "%s", s);
	if(!mystrcmp(s, "0"))
		mystrcpy(s, "\0");
	fscanf(fp, "%s", s1);
	if(!mystrcmp(s1, "0"))
		mystrcpy(s1, "\0");
	fscanf(fp, "%d", &m);
	n = h.p[10](s, s1, m);
	fscanf(fp, "%d", &k);
	if((n == 0 && k == 0) || (n > 0 && k > 0) || (n < 0 && k < 0))
		printf("mybcmp Successful\n");
	else if(n > 0 && k < 0)
		printf("mybcmp Unsuccessful\t%s is bigger than %s\n", s, s1);
	else
		printf("mybcmp Unsuccessful\t%s is smaller than %s\n", s, s1);
}

void checkmemfrob(FILE *fp){
	char *s, *s1;
	int n;
	s = (char*) malloc(64);
	s1 = (char*) malloc(64);
	fscanf(fp, "%s", s);
	if(!mystrcmp(s, "0"))
		mystrcpy(s, "\0");
	fscanf(fp, "%d", &n);
	h.q[0](s1, s);
	h.r[7](s, n);
	if(!h.p[1](s1, h.r[7](s, n)))
		printf("mymemfrob Successful\t encrypted string is %s\n", (char *)h.r[7](s, n));
	else
		printf("mymemfrob Unsuccessful\n");
	free(s);
	free(s1);
}

void checkffs(FILE *fp){
	int m, n, k;
	fscanf(fp, "%d%d", &m, &n);
	k = myffs(m);
	if(k == n)
		printf("myffs Successful\n");
	else
		printf("myffs Unsuccessful\t least signicant bit position is %d\n", k);
}

void checkffsl(FILE *fp){
	long int a;
	int m, k;
	fscanf(fp, "%ld%d", &a, &m);
	k = myffsl(a);
	if(k == m)
		printf("myffsl Successful\n");
	else
		printf("myffsl Unsuccessful\t least signicant bit position is %d\n", k);
}

void checkffsll(FILE *fp){
	long long int b;
	int m, k;
	fscanf(fp, "%lld%d", &b, &m);
	k = myffsll(b);
	if(k == m)
		printf("myffsll Successful\n");
	else
		printf("myffsll Unsuccessful\t least signicant bit position is %d\n", k);
}

int main(){
	char *str, *s, *s1, *s3, *s4;
	int  key, flag = 0;
	FILE *fp;
	str = (char*) malloc(128);
	s = (char*) malloc(128);
	s1 = (char*) malloc(128);
	s3 = (char*) malloc(128);
	s4 = (char*) malloc(128);
	fp = fopen("strdata.txt", "r");
	if(fp == NULL)
		return 0;
	while(!feof(fp)){
		fscanf(fp, "%s", str);
		if(flag == 0)
			h.q[0](s4, str);
		if(flag == 1){
			h.q[0](s3, s4);
			h.q[0](s4, str);
			if(h.p[1](s3, s4) != 0)
				flag = 0;
		}
		key = hash(str);
		if(!feof(fp)){
			switch(key){
				//strlen
				case 450:
					if(flag == 0){
						printf("\n\t\t\t------->Testing mystrlen<------\n\n");
						flag = 1;
					}
					checkstrlen(fp);
					break;
				//strcpy
				case 446:
					if(flag == 0){
						printf("\n\t\t\t------->Testing mystrcpy<------\n\n");
						flag = 1;
					}
					checkstrcpy(fp);
					break;
				//stpcpy
				case 444:
					if(flag == 0){
						printf("\n\t\t\t------->Testing mystpcpy<------\n\n");
						flag = 1;
					}
					checkstpcpy(fp);
					break;
				//strncpy
				case 556:
					if(flag == 0){
						printf("\n\t\t\t------->Testing mystrncpy<------\n\n");
						flag = 1;
					}
					checkstrncpy(fp);
					break;
				//strcat
				case 432:
					if(flag == 0){
						printf("\n\t\t\t------->Testing mystrcat<------\n\n");
						flag = 1;
					}
					checkstrcat(fp);
					break;
				//strncat
				case 543:
					if(flag == 0){
						printf("\n\t\t\t------->Testing mystrncat<------\n\n");
						flag = 1;
					}
					checkstrncat(fp);
					break;
				//strcmp
				case 440:
					if(flag == 0){
						printf("\n\t\t\t------->Testing mystrcmp<------\n\n");
						flag = 1;
					}
					checkstrcmp(fp);
					break;
				//strcasecmp
				case 853:
					if(flag == 0){
						printf("\n\t\t\t------->Testing mystrcasecmp<------\n\n");
						flag = 1;
					}
					checkstrcasecmp(fp);
					break;
				//strncmp
				case 551:
					if(flag == 0){
						printf("\n\t\t\t------->Testing mystrncmp<------\n\n");
						flag = 1;
					}
					checkstrncmp(fp);
					break;
				//strncasecmp
				case 963:
					if(flag == 0){
						printf("\n\t\t\t------->Testing mystrncasecmp<------\n\n");
						flag = 1;
					}
					checkstrncasecmp(fp);
					break;
				//strdup
				case 447:
					if(flag == 0){
						printf("\n\t\t\t------->Testing mystrdup<------\n\n");
						flag = 1;
					}
					checkstrdup(fp);	
					break;
				//mystrdupa
				case 555:
					if(flag == 0){
						printf("\n\t\t\t------->Testing mystrdupa<------\n\n");
						flag = 1;
					}
					checkstrdupa(fp);
					break;
				//strndup
				case 557:
					if(flag == 0){
						printf("\n\t\t\t------->Testing mystrndup<------\n\n");
						flag = 1;
					}
					checkstrndup(fp);
					break;
				//strndupa
				case 665:
					if(flag == 0){
						printf("\n\t\t\t------->Testing mystrndupa<------\n\n");
						flag = 1;
					}
					break;
				//mystrrev
				case 465:
					if(flag == 0){
						printf("\n\t\t\t------->Testing mystrrev<------\n\n");
						flag = 1;
					}
					checkstrrev(fp);
					break;
				//mystrchr
				case 433:
					if(flag == 0){
						printf("\n\t\t\t------->Testing mystrchr<------\n\n");
						flag = 1;
					}
					checkstrchr(fp);
					break;
				//strrchr
				case 547:
					if(flag == 0){
						printf("\n\t\t\t------->Testing mystrrchr<------\n\n");
						flag = 1;
					}
					checkstrrchr(fp);
					break;
				//strpbrk
				case 545:
					if(flag == 0){
						printf("\n\t\t\t------->Testing mystrpbrk<------\n\n");
						flag = 1;
					}
					checkstrpbrk(fp);
					break;
				//strcspn
				case 567:
					if(flag == 0){
						printf("\n\t\t\t------->Testing mystrcspn<------\n\n");
						flag = 1;
					}
					checkstrcspn(fp);
					break;
				//strspn
				case 468:
					if(flag == 0){
						printf("\n\t\t\t------->Testing mystrspn<------\n\n");
						flag = 1;
					}
					checkstrspn(fp);
					break;
				//strreplace
				case 860:
					if(flag == 0){
						printf("\n\t\t\t------->Testing mystrreplace<------\n\n");
						flag = 1;
					}
					checkstrreplace(fp);
					break;
				//strstr
				case 462:
					if(flag == 0){
						printf("\n\t\t\t------->Testing mystrstr<------\n\n");
						flag = 1;
					}
					checkstrstr(fp);
					break;
				//strtok
				case 464:
					if(flag == 0){
						printf("\n\t\t\t------->Testing mystrtok<------\n\n");
						flag = 1;
					}
					checkstrtok(fp);
					break;
				//strtok_r
				case 1:
					if(flag == 0){
						printf("\n\t\t\t------->Testing mystrtok_r<------\n\n");
						flag = 1;
					}
					checkstrtok_r(fp);
					break;
				//strfry
				case 453:
					if(flag == 0){
						printf("\n\t\t\t------->Testing mystrfry<------\n\n");
						flag = 1;
					}
					checkstrfry(fp);
					break;
				//myindex
				case 321:
					if(flag == 0){
						printf("\n\t\t\t------->Testing myindex<------\n\n");
						flag = 1;
					}
					checkindex(fp);
					break;
				//rindex
				case 431:
					if(flag == 0){
						printf("\n\t\t\t------->Testing myrindex<------\n\n");
						flag = 1;
					}
					checkrindex(fp);
					break;
				//memchr
				case 428:
					if(flag == 0){
						printf("\n\t\t\t------->Testing mymemchr<------\n\n");
						flag = 1;
					}
					checkmemchr(fp);
					break;
				//memrchr
				case 542:
					if(flag == 0){
						printf("\n\t\t\t------->Testing mymemrchr<------\n\n");
						flag = 1;
					}
					checkmemrchr(fp);
					break;
				//memcmp
				case 436:
					if(flag == 0){
						printf("\n\t\t\t------->Testing mymemcmp<------\n\n");
						flag = 1;
					}
					checkmemcmp(fp);
					break;
				//memmem
				case 445:
					if(flag == 0){
						printf("\n\t\t\t------->Testing mymemmem<------\n\n");
						flag = 1;
					}
					checkmemmem(fp);
					break;
				//memcpy
				case 441:
					if(flag == 0){
						printf("\n\t\t\t------->Testing mymemcpy<------\n\n");
						flag = 1;
					}
					checkmemcpy(fp);
					break;
				//mempcpy
				case 553:
					if(flag == 0){
						printf("\n\t\t\t------->Testing mymempcpy<------\n\n");
						flag = 1;
					}
					checkmempcpy(fp);
					break;
				//memccpy
				case 540:
					if(flag == 0){
						printf("\n\t\t\t------->Testing mymemccpy<------\n\n");
						flag = 1;
					}
					checkmemccpy(fp);
					break;
				//memset
				case 459:
					if(flag == 0){
						printf("\n\t\t\t------->Testing mymemset<------\n\n");
						flag = 1;
					}
					checkmemset(fp);
					break;
				//strword
				case 576:
					if(flag == 0){
						printf("\n\t\t\t------->Testing mystrword<------\n\n");
						flag = 1;
					}
					checkstrword(fp);
					break;
				//bzero
				case 326:
					if(flag == 0){
						printf("\n\t\t\t------->Testing mybzero<------\n\n");
						flag = 1;
					}
					break;
				//bcmp
				case 228:
					if(flag == 0){
						printf("\n\t\t\t------->Testing mybcmp<------\n\n");
						flag = 1;
					}
					checkbcmp(fp);
					break;
				//memfrob 
				case 549:
					if(flag == 0){
						printf("\n\t\t\t------->Testing mymemfrob<------\n\n");
						flag = 1;
					}
					checkmemfrob(fp);
					break;
				//myffs
				case 115:
					if(flag == 0){
						printf("\n\t\t\t------->Testing myffs<------\n\n");
						flag = 1;
					}
					checkffs(fp);
					break;
				//myffsl
				case 224:
					if(flag == 0){
						printf("\n\t\t\t------->Testing myffsl<------\n\n");
						flag = 1;
					}
					checkffsl(fp);
					break;
				//ffsll
				case 336:
					if(flag == 0){
						printf("\n\t\t\t------->Testing myffsll<------\n\n");
						flag = 1;
					}
					checkffsll(fp);
					break;
				default:
					printf("There is no such %s function in my library\n", str);
			}
		}
	}
	fclose(fp);
	free(s3);
	free(s4);
	free(s);
	free(s1);
	free(str);
	return 0;
}
