#include<stdio.h>
#include<wchar.h>
#include"mywchar.h"
#include"mystring.h"
#include <stddef.h>
#include<stdlib.h>

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

int main(){
	wchar_t w[16], w1[16];
	char *str, s[16], *s1, s3[16], s4[16];
	int n, m, key, flag = 0;
	s1 = (char*) malloc(128);
	str = (char*) malloc(128);
	FILE *fp;
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
//		wprintf(L"key=  %d\n", key);
		switch(key){
			case 434:
				if(flag == 0){
					wprintf(L"\n\t\t\t------->Testing mywcslen<------\n\n");
					flag = 1;
				}	
				fscanf(fp, "%s", s);
				fscanf(fp, "%d", &m);
				mbstowcs (w, s, 16);
//				fputws(s, stdout);
				n = mywcslen(w);
//				wprintf(L"%d\n", n);
				if(n == m)
					wprintf(L"mywcslen Successful\n");
				else
					wprintf(L"mywcslen Unsuccessful\tlength of string is %d\n", n);
				break;
			case 447:
				if(flag == 0){
					wprintf(L"\n\t\t\t------->Testing mywcscpy<------\n\n");
					flag = 1;
				}
				fscanf(fp, "%s", s);
				mbstowcs (w, s, 16);
				fscanf(fp, "%s", s1);
				mbstowcs (w1, s1, 16);
				mywcscpy(w, w1);
				if(!mywcscmp(w, w1))
					wprintf(L"mywcscpy Successful\n");
				else
					wprintf(L"mywcscpy Unsuccessful\n");
				break;
		}
	}
	fclose(fp);
	free(s1);
	free(str);
}
