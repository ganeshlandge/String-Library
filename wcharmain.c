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
#include"mywchar.h"
#include"mystring.h"
#include<stdlib.h>
#include <locale.h>

const ht1 h = { { mywcscmp, mywcsncmp, mywmemcmp}, { mywcslen, mywcscspn, mywcsspn },
	       { mywcscpy, mywcpcpy, mywcsncpy, mywcscat, mywcsncat, mywcschr, mywcspbrk, mywcsstr, mywmemchr, mywmemcpy, 		         mywmemset, mywcsdup, mywcsrchr, mywcstok }
	     };
		
int hash(char *str){
	int key = 0;
	char *p = str;
	p = str + 4;
	while(*p){
		key = key + *p;
		p++;
	}
	p-=1;
	key = key + ((*p) % 11);
	return key;
}

void checkmywcslen(FILE *fp){
	int m, n;
	wchar_t w[128];
	fscanf(fp, "%ls", w);
	fscanf(fp, "%d", &m);
	n = h.q[0](w);
	if(n == m)
		printf("mywcslen Successful\n");
	else
		printf("mywcslen Unsuccessful\tlength of string %ls is %d\n", w, n);
}

void checkmywcscmp(FILE *fp){
	wchar_t s[16], s1[16];
	int n, m;
	fscanf(fp, "%ls", s);
	fscanf(fp, "%ls", s1);
	n = h.p[0](s, s1);
	fscanf(fp, "%d", &m);
	if((n == 0 && m == 0) || (n > 0 && m > 0) || (n < 0 && m < 0))
		printf("mywcscmp Successful\n");
	else if(n > 0 && m < 0)
		printf("mywcscmp Unsuccessful\t%ls is bigger than %ls\n", s, s1);
	else
		printf("mywcscmp Unsuccessful\t%ls is smaller than %ls\n", s, s1);
}

void checkmywcsncmp(FILE *fp){
	wchar_t s[16], s1[16];
	int n, m,  k;
	fscanf(fp, "%ls", s);
	fscanf(fp, "%ls", s1);
	fscanf(fp, "%d", &m);
	n = h.p[1](s, s1, m);
	fscanf(fp, "%d", &k);
	if((n == 0 && k == 0) || (n > 0 && k > 0) || (n < 0 && k < 0))
		printf("mywcsncmp Successful\n");
	else if(n > 0 && k < 0)
		printf("mywcsncmp Unsuccessful\t%ls is bigger than %ls\n", s, s1);
	else
		printf("mywcsncmp Unsuccessful\t%ls is smaller than %ls\n", s, s1);
}

void checkmywcscspn(FILE *fp){
	wchar_t s[16], s1[16];
	int m, n;	
	fscanf(fp, "%ls", s);
	fscanf(fp, "%ls", s1);
	fscanf(fp, "%d", &n);
	m = h.q[1](s, s1);
	if(n == m)
		printf("mywcscspn Successful\n");
	else
		printf("mywcscspn Unsuccessful\tthere are %d bytes in string %ls which are not in string %ls\n", m, s, s1);
}

void checkmywcsspn(FILE *fp){
	wchar_t s[16], s1[16];
	int m, n;	
	fscanf(fp, "%ls", s);
	fscanf(fp, "%ls", s1);
	fscanf(fp, "%d", &n);
	m = h.q[2](s, s1);
	if(n == m)
		printf("mywcsspn Successful\n");
	else
		printf("mywcsspn Unsuccessful\tthere are %d bytes in string %ls which are in string %ls\n", m, s, s1);
}

void checkmywmemcmp(FILE *fp){
	wchar_t s[16], s1[16];
	int n, m, k;
	fscanf(fp, "%ls", s);
	fscanf(fp, "%ls", s1);
	fscanf(fp, "%d", &k);
	n = h.p[2](s, s1, k);
	fscanf(fp, "%d", &m);
	if((n == 0 && m == 0) || (n > 0 && m > 0) || (n < 0 && m < 0))
		printf("mywmemcmp Successful\n");
	else if(n > 0 && m < 0)
		printf("mywmemcmp Unsuccessful\t%ls is bigger than %ls\n", s, s1);
	else
		printf("mywmemcmp Unsuccessful\t%ls is smaller than %ls\n", s, s1);
}

void checkmywcscpy(FILE *fp){
	wchar_t w[16], w1[16];
	fscanf(fp, "%ls", w);
	fscanf(fp, "%ls", w1);
	h.r[0](w, w1);
	if(!h.p[0](w, w1))
		printf("mywcscpy Successful\n");
	else
		printf("mywcscpy Unsuccessful\n");

}

void checkmywcpcpy(FILE *fp){
	wchar_t s[16], s1[16];
	wchar_t *s2;
	fscanf(fp, "%ls", s);
	fscanf(fp, "%ls", s1);
	s2 = h.r[1](s, s1);
	if(!h.p[0](s, s1) && *s2 == L'\0')
		printf("mystpcpy Successful\n");
	else
		printf("mystpcpy Unsuccessful\n");
}

void checkmywcsncpy(FILE *fp){
	wchar_t s[16], s1[16];
	int m;
	fscanf(fp, "%ls", s);
	fscanf(fp, "%ls", s1);
	fscanf(fp, "%d", &m);
	h.r[2](s, s1, m);
	if(!h.p[1](s, s1, m))
		printf("mywcsncpy Successful\n");
	else
		printf("mywcsncpy Unsuccessful\t%d bytes of string %ls can't be copied to string %ls\n", m, s1, s);
}

void checkmywcscat(FILE *fp){
	wchar_t s[16], s1[16];
	fscanf(fp, "%ls", s);
	fscanf(fp, "%ls", s1);
	h.r[3](s, s1);
	if(1)
		printf("mystrcat Successful\n");
	else
		printf("mystrcat Unsuccessful\n");
}

void checkmywcsncat(FILE *fp){
	wchar_t s[16], s1[16];
	int m;
	fscanf(fp, "%ls", s);
	fscanf(fp, "%ls", s1);
	fscanf(fp, "%d", &m);
	h.r[4](s, s1, m);
	if(1)
		printf("mywcsncat Successful\n");
	else
		printf("mywcsncat Unsuccessful\n");
}

void checkmywcschr(FILE *fp){
	wchar_t s[16], ch[1], *s1;
	fscanf(fp, "%ls", s);
	fscanf(fp, "%ls", ch);
	s1 = h.r[5](s, ch[0]);
	if(s1 != NULL)
		printf("mywcschr Successful\n");
	else
		printf("mywcschr Unsuccessful\tcharacter %c is not found in given string\n", ch[0]);
}

void checkmywcspbrk(FILE *fp){
	wchar_t s[128], s1[128];
	wchar_t *s2;	
	fscanf(fp, "%ls", s);
	fscanf(fp, "%ls", s1);
	s2 = h.r[6](s, s1);
	if(s2 != NULL)
		printf("mywcspbrk Successful\tthe character '%lc' in string %ls is found in string %ls\n", s2[0], s1, s);
	else
		printf("mywcspbrk Successful\tthe string %ls does not contain any bytes in string %ls\n", s, s1);
}

void checkmywcsstr(FILE *fp){
	wchar_t s[128], s1[128];
	wchar_t *s2;	
	fscanf(fp, "%ls", s);
	fscanf(fp, "%ls", s1);
	s2 = h.r[7](s, s1);
	if(s2 != NULL)
		printf("mywcsstr Successful\n");
	else
		printf("mywcsstr Unsuccessful\t string %ls not found in string %ls\n", s1, s);
}

void checkmywmemchr(FILE *fp){
	wchar_t s[128], ch[1], *s1;
	int n;
	fscanf(fp, "%ls", s);
	fscanf(fp, "%ls", ch);
	fscanf(fp, "%d", &n);
	s1 = (wchar_t *)h.r[8](s, ch[0], n);
	if(s1 != NULL)
		printf("mywmemchr Successful\n");
	else
		printf("mywmemchr Unsuccessful\tcharacter %lc is not found in given string\n", ch[0]);
}

void checkmywmemcpy(FILE *fp){
	wchar_t s[128], s1[128];
	int m;
	fscanf(fp, "%ls", s);
	fscanf(fp, "%ls", s1);
	fscanf(fp, "%d", &m);
	h.r[9](s, s1, m);
	if(!h.p[1](s, s1, m))
		printf("mywmemcpy Successful\n");
	else
		printf("mywmemcpy Unsuccessful\n");
}

void checkmywmemset(FILE *fp){
	wchar_t s[128], s1[1];
	int m;
	fscanf(fp, "%ls", s);
	fscanf(fp, "%ls", s1);
	fscanf(fp, "%d", &m);
	h.r[10](s, s1[0], m);
	if(1)
		printf("mywmemset Successful\tcopied string is %ls\n", s);
	else
		printf("mywmemset Unsuccessful\n");
}

void checkmywcsdup(FILE *fp){
	wchar_t s[128], s1[128];
	wchar_t *s2;
	fscanf(fp, "%ls", s);
	fscanf(fp, "%ls", s1);
	s2 = h.r[11](s);
	if(!h.p[0](s2, s1))
		printf("mywcsdup Successful\n");
	else
		printf("mywcsdup Unsuccessful\tstrings %ls and %ls are different\n", s, s1);
}

void checkmywcsrchr(FILE *fp){
	wchar_t s[128], ch[1], *s1;
	fscanf(fp, "%ls", s);
	fscanf(fp, "%ls", ch);
	s1 = h.r[12](s, ch[0]);
	if(s1 != NULL)
		printf("mywcsrchr Successful\n");
	else
		printf("mywcsrchr Unsuccessful\tcharacter %lc is not found in given string\n", ch[0]);
}

void checkwcstok(FILE *fp){
	wchar_t s[128], s1[128];
	wchar_t *s2, *s3;	
	fscanf(fp, "%ls", s);
	fscanf(fp, "%ls", s1);
	s2 = h.r[13](s, s1, &s3);
	printf("mywcstok Successful\t");
	printf("seperated strings are ");
	while(s2 != NULL){
		printf("'%ls' ", s2);
		s2 = h.r[13](NULL, s1, &s3);
	}
	printf("\n");
}

int main(){
	char *str, *s1, s3[128], s4[128];
	int key, flag = 0;
	s1 = (char*) malloc(128);
	str = (char*) malloc(128);
	FILE *fp;
	setlocale(LC_ALL, "");
	fp = fopen("wchardata.txt", "r");
	if(fp == NULL)
		return 0;
	while(!feof(fp)){
		fscanf(fp, "%s", str);
		if(flag == 0)
			mystrcpy(s4, str);
		if(flag == 1){
			mystrcpy(s3, s4);
			mystrcpy(s4, str);
			if(mystrcmp(s3, s4) != 0)
				flag = 0;
		}
		key = hash(str);
		if(!feof(fp)){
			switch(key){
				//mywcslen
				case 434:
					if(flag == 0){
						printf("\n\t\t\t------->Testing mywcslen<------\n\n");
						flag = 1;
					}
					checkmywcslen(fp);
					break;
				//mywcscpy
				case 447:
					if(flag == 0){
						printf("\n\t\t\t------->Testing mywcscpy<------\n\n");
						flag = 1;
					}
					checkmywcscpy(fp);
					break;
				//mywcpcpy
				case 444:
					if(flag == 0){
						printf("\n\t\t\t------->Testing mywcpcpy<------\n\n");
						flag = 1;
					}
					checkmywcpcpy(fp);
					break;
				//mywcsncpy
				case 557:
					if(flag == 0){
						printf("\n\t\t\t------->Testing mywcsncpy<------\n\n");
						flag = 1;
					}
					checkmywcsncpy(fp);
					break;
				//mywcscmp
				case 437:
					if(flag == 0){
						printf("\n\t\t\t------->Testing mywcscmp<------\n\n");
						flag = 1;
					}
					checkmywcscmp(fp);
					break;
				//mywcsncmp
				case 547:
					if(flag == 0){
						printf("\n\t\t\t------->Testing mywcsncmp<------\n\n");
						flag = 1;
					}
					checkmywcsncmp(fp);
					break;
				//mywcscat
				case 433:
					if(flag == 0){
						printf("\n\t\t\t------->Testing mywcscat<------\n\n");
						flag = 1;
					}
					checkmywcscat(fp);
					break;
				//mywcsncat	
				case 543:
					if(flag == 0){
						printf("\n\t\t\t------->Testing mywcsncat<------\n\n");
						flag = 1;
					}
					checkmywcsncat(fp);
					break;
				//mywcschr
				case 436:
					if(flag == 0){
						printf("\n\t\t\t------->Testing mywcschr<------\n\n");
						flag = 1;
					}
					checkmywcschr(fp);
					break;
				//mywcscspn
				case 551:
					if(flag == 0){
						printf("\n\t\t\t------->Testing mywcscspn<------\n\n");
						flag = 1;
					}
					checkmywcscspn(fp);
					break;
				//mywcspbrk
				case 554:
					if(flag == 0){
						printf("\n\t\t\t------->Testing mywcspbrk<------\n\n");
						flag = 1;
					}
					checkmywcspbrk(fp);
					break;
				//mywcsspn
				case 452:
					if(flag == 0){
						printf("\n\t\t\t------->Testing mywcsspn<------\n\n");
						flag = 1;
					}
					checkmywcsspn(fp);
					break;
				//mywcsstr
				case 464:
					if(flag == 0){
						printf("\n\t\t\t------->Testing mywcsstr<------\n\n");
						flag = 1;
					}
					checkmywcsstr(fp);
					break;
				//mywmemchr
				case 531:
					if(flag == 0){
						printf("\n\t\t\t------->Testing mywmemchr<------\n\n");
						flag = 1;
					}
					checkmywmemchr(fp);
					break;
				//mywmemcmp
				case 532:
					if(flag == 0){
						printf("\n\t\t\t------->Testing mywmemcmp<------\n\n");
						flag = 1;
					}
					checkmywmemcmp(fp);
					break;
				//mywmemcpy 
				case 542:
					if(flag == 0){
						printf("\n\t\t\t------->Testing mywmemcpy<------\n\n");
						flag = 1;
					}
					checkmywmemcpy(fp);
					break;
				//mywmemset 
				case 548:
					if(flag == 0){
						printf("\n\t\t\t------->Testing mywmemset<------\n\n");
						flag = 1;
					}
					checkmywmemset(fp);
					break;
				//mywcsdup
				case 446:
					if(flag == 0){
						printf("\n\t\t\t------->Testing mywcsdup<------\n\n");
						flag = 1;
					}
					checkmywcsdup(fp);
					break;
				//mywcsrchr
				case 550:
					if(flag == 0){
						printf("\n\t\t\t------->Testing mywcsrchr<------\n\n");
						flag = 1;
					}
					checkmywcsrchr(fp);
					break;
				//wcstok 
				case 457:
					if(flag == 0){
						printf("\n\t\t\t------->Testing wcstok<------\n\n");
						flag = 1;
					}
					checkwcstok(fp);
					break;
				default:
					printf("There is no such %s function in my library\n", str);	
			}
		}
	}
	fclose(fp);
	free(s1);
	free(str);
}
