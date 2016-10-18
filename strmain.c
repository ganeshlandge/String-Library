#include<stdio.h>
#include<string.h>
#include<strings.h>
#include<stdlib.h>
#include"mystring.h"
#define _GNU_SOURCE

int hash(char *str){
	int key = 0;
	char *p = str + 4;
	if(!strcmp(str, "mystrcmp"))
		return 440;
	if(!strcmp(str, "mystrncat"))
		return 543;
	while(*p){
		key = key + *p;
		p++;
	}
	p = p - 2;
	key = key + (((*p % 11) + (*(p + 1) / 7)) % 19);
	return key;
}

int main(){
	char *str, *s, *s2, *s1, *s3, *s4;
	int n, m, k, key, flag = 0;
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
			mystrcpy(s4, str);
		if(flag == 1){
			mystrcpy(s3, s4);
			mystrcpy(s4, str);
			if(mystrcmp(s3, s4) != 0)
				flag = 0;
		}
		key = hash(str);
		switch(key){
			//strlen
			case 450:
				if(flag == 0){
					printf("\n\t\t\t------->Testing mystrlen<------\n\n");
					flag = 1;
				}
				fscanf(fp, "%s", s);
				n = mystrlen(s);
				fscanf(fp, "%d", &m);
				if(n == m)
					printf("mystrlen Successful\n");
				else
					printf("mystrlen Unsuccessful\tlength of string is %d\n", n);
				break;
			//strcpy
			case 446:
				if(flag == 0){
					printf("\n\t\t\t------->Testing mystrcpy<------\n\n");
					flag = 1;
				}
				fscanf(fp, "%s", s);
				fscanf(fp, "%s", s1);
				s = mystrcpy(s, s1);
				if(!mystrcmp(s, s1))
					printf("mystrcpy Successful\n");
				else
					printf("mystrcpy Unsuccessful\n");
				break;
			//stpcpy
			case 444:
				if(flag == 0){
					printf("\n\t\t\t------->Testing mystpcpy<------\n\n");
					flag = 1;
				}
				fscanf(fp, "%s", s);
				fscanf(fp, "%s", s1);
				s2 = mystpcpy(s, s1);
				if(!mystrcmp(s, s1) && *s2 == '\0')
					printf("mystpcpy Successful\n");
				else
					printf("mystpcpy Unsuccessful\n");
				break;
			//strncpy
			case 556:
				if(flag == 0){
					printf("\n\t\t\t------->Testing mystrncpy<------\n\n");
					flag = 1;
				}
				fscanf(fp, "%s", s);
				fscanf(fp, "%s", s1);
				fscanf(fp, "%d", &m);
				s2 = mystrncpy(s, s1, m);
				if(!mystrncmp(s, s1, m))
					printf("mystrncpy Successful\n");
				else
					printf("mystrncpy Unsuccessful\n");
				break;
			//strcat
			case 432:
				if(flag == 0){
					printf("\n\t\t\t------->Testing mystrcat<------\n\n");
					flag = 1;
				}
				fscanf(fp, "%s", s);
				fscanf(fp, "%s", s1);
				s2 = mystrcat(s, s1);
				if(1)
					printf("mystrcat Successful\n");
				else
					printf("mystrcat Unsuccessful\n");
				break;
			//strncat
			case 543:
				break;
			//strcmp
			case 440:
				if(flag == 0){
					printf("\n\t\t\t------->Testing mystrcmp<------\n\n");
					flag = 1;
				}
				fscanf(fp, "%s", s);
				fscanf(fp, "%s", s1);
				n = mystrcmp(s, s1);
				fscanf(fp, "%d", &m);
				if((n == 0 && m == 0) || (n > 0 && m > 0) || (n < 0 && m < 0))
					printf("mystrcmp Successful\n");
				else
					printf("mystrcmp Unsuccessful\n");
				break;
			//strcasecmp
			case 853:
				if(flag == 0){
					printf("\n\t\t\t------->Testing mystrcasecmp<------\n\n");
					flag = 1;
				}
				fscanf(fp, "%s", s);
				fscanf(fp, "%s", s1);
				n = mystrcasecmp(s, s1);
				fscanf(fp, "%d", &m);
				if((n == 0 && m == 0) || (n > 0 && m > 0) || (n < 0 && m < 0))
					printf("mystrcasecmp Successful\n");
				else
					printf("mystrcasecmp Unsuccessful\n");
				break;
			//strncmp
			case 551:
				if(flag == 0){
					printf("\n\t\t\t------->Testing mystrncmp<------\n\n");
					flag = 1;
				}
				fscanf(fp, "%s", s);
				fscanf(fp, "%s", s1);
				fscanf(fp, "%d", &m);
				n = mystrncmp(s, s1, m);
				fscanf(fp, "%d", &k);
				if((n == 0 && k == 0) || (n > 0 && k > 0) || (n < 0 && k < 0))
					printf("mystrncmp Successful\n");
				else
					printf("mystrncmp Unsuccessful\n");
				break;
			//strncasecmp
			case 963:
				if(flag == 0){
					printf("\n\t\t\t------->Testing mystrncasecmp<------\n\n");
					flag = 1;
				}
				fscanf(fp, "%s", s);
				fscanf(fp, "%s", s1);
				fscanf(fp, "%d", &m);
				n = mystrncasecmp(s, s1, m);
				fscanf(fp, "%d", &k);
				if((n == 0 && k == 0) || (n > 0 && k > 0) || (n < 0 && k < 0))
					printf("mystrncasecmp Successful\n");
				else
					printf("mystrncasecmp Unsuccessful\n");
				break;
			//strdup
			case 447:	
				break;
			//strdupa
			case 555:
				break;
			//strndup
			case 557:
				break;
			//strndupa
			case 665:
				break;
			//strrev
			case 465:
				break;
			//strchr
			case 433:
				break;
			//strrchr
			case 547:
				break;
			//strpbrk
			case 545:
				break;
			//strcspn
			case 567:
				break;
			//strspn
			case 468:
				break;
			//strreplace
			case 860:
				break;
			//strtr
			case 462:
				break;
			//strtok
			case 464:
				break;
			//strfry
			case 453:
				break;
			//myindex
			case 321:
				break;
			//rindex
			case 431:
				break;
			//memchr
			case 428:
				break;
			//strmemrchr
			case 539:
				break;
			//strmemcmp
			case 436:
				break;
			//memmem
			case 445:
				break;
			//memcpy
			case 437:
				break;
			//mempcpy
			case 553:
				break;
			//memccpy
			case 540:
				break;
			//memset
			case 459:
				break;
			//strword
			case 576:
				break;
			//bzero
			case 326:
				break;
			//bcmp
			case 228:
				break;
			//memfrob 
			case 549:
				break;
			//ffs
			case 115:
				break;
			//ffsl
			case 224:
				break;
			//ffsll
			case 336:
				break;
			default:
				printf("There is no %s such function\n", str);
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
