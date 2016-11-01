
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
 
#include <stdlib.h>
#include <errno.h>

size_t mywcslen(wchar_t *s){
	wchar_t *p;
	p = s;
	size_t i = 0;
	while (*p != L'\0'){
		p++;
		i++;
	}
	return i;
}

wchar_t *mywcscpy(wchar_t *s1, wchar_t *s2){
	wchar_t *cp;
	cp = s1;
	for(; *s2; ++s2, ++cp)
		*cp = *s2;
	*cp = L'\0';
	return (s1);
}

wchar_t *mywcpcpy(wchar_t *dest, const wchar_t *src){
	for(; *src; ++dest, ++src)
		*dest = *src;
	*dest = L'\0';
	return dest;
}

wchar_t *mywcsncpy(wchar_t *s1, const wchar_t *s2, size_t n){
	wchar_t *cp;
	cp = s1;
	int i = 0;
	for(; *s2 && i < n; ++s2, ++cp){
		*cp = *s2;
		i++;
	}
	return (s1);
}

int mywcscmp(wchar_t *s1, const wchar_t *s2){
	while (*s1 == *s2++)
		if (*s1++ == 0)
			return (0);
	return (*(const unsigned int *)s1 - *(const unsigned int *)--s2);
}

int mywcsncmp(wchar_t *s1, const wchar_t *s2, size_t n){
	int i = 0;
	while(*s1 == *s2 && i < n){
		if(*s1 == L'\0')
			return 0;
		i++;
		if(i == n - 1)
			break;
		s1++;
		s2++;
	}
	return (*(unsigned int *)s1 - *(unsigned int *)s2);
}

wchar_t *mywcscat(wchar_t *s1, wchar_t *s2){
	wchar_t *cp;
	cp = s1;
	while (*cp != L'\0')
		cp++;
	for(; *s2; ++s2, ++cp)
		*cp = *s2;
	*s2 = L'\0';
	return (s1);
}

wchar_t *mywcsncat(wchar_t *s1, wchar_t *s2, size_t n){
	wchar_t *cp;
	cp = s1;
	int i = 0;
	while (*cp != L'\0')
		cp++;
	for(; *s2 && i < n; ++s2, ++cp){
		*cp = *s2;
		i++;
	}
	*s2 = L'\0';
	return (s1);
}

wchar_t *mywcschr(wchar_t *str, wchar_t c){
	wchar_t ch = c;
	while(*str != L'\0'){
		if(*str == ch)
			return str;
		str++;
	}
	if(*str == ch)			//for last null (\0) byte if c = '\0'
		return str;
	else
		return NULL;
}

/*The  mywcscspn() function returns the number of wide characters in the longest 
* initial segment of wcs which consists entirely of wide-
* characters not listed in reject.
*/
size_t mywcscspn(const wchar_t *wcs, const wchar_t *reject){
	size_t n = 0;
	const wchar_t *str = reject;
	while(*wcs != L'\0'){
		while(*reject != L'\0' ){
			if(*wcs == *reject)
				return n;
			reject++;
		}
		wcs++;
		n++;
		reject = str;
 	}
 	return n;
}

/* The wcspbrk() function returns a pointer to the first occurrence in wcs
*  of any of the characters listed in accept.  If  wcs  contains  none  of
*  these characters, NULL is returned
*/
wchar_t *mywcspbrk(wchar_t *s, const wchar_t *accept){
	const wchar_t *str = accept;
	while(*s != L'\0'){
		while(*accept != L'\0'){
			if(*s == *accept)
				return s;
			accept++;
		}
		s++;
		accept = str;
 	}
 	return NULL;
}

/*The  mywcsspn()  function  returns  the  number of wide characters in the
* longest initial segment of wcs which consists entirely of  wide-charac‐
* ters  listed in accept.
*/
size_t mywcsspn(const wchar_t *s, const wchar_t *accept){
	size_t n = 0, k;
	const wchar_t *str = accept;
	while(*s != L'\0'){
		k = 0;
		while(*accept != L'\0'){
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

/* The mywcsstr() function returns a pointer to the first occurrence of substr in str.  
 *  It returns NULL if substr does not occur  as a substring in str.
 */
wchar_t *mywcsstr(wchar_t *str, wchar_t *substr){
	int l1, l2, i, j, k, c = 0;	
	l1 = mywcslen(str);
	l2 = mywcslen(substr);
	for(k = 0; k < l1; k++){
		i = k;
		j = 0;
		c = 0;
		while((str[i] == substr[j]) && str[i] != L'\0'){
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

/* The mywmemchr() function returns a pointer to the first occurrence of c among 
 * the n wide characters starting at s, or NULL if  c  does not occur among these
*/
wchar_t *mywmemchr(wchar_t *s, wchar_t c, size_t n){
	wchar_t *str = s;
	while(n != 0){
		if(*str == c)
			return str;
		str++;
		n--;
	}
	if(*str == c)			//for last null (\0) byte if c = L'\0'
		return str;
	else
		return NULL;
}

/* The mywmemcmp() function is the wide-character equivalent of the memcmp(3) function.  
*  It compares the n wide-characters starting at str1 and the n wide-characters starting at str2.
*/
int mywmemcmp(wchar_t *str1, wchar_t *str2, size_t n){
	int i = 0;
	wchar_t *s1 = str1;
	wchar_t *s2 = str2;
	if(n == 0)
		return 0;
	if(n < 0)
		return mywcsncmp(s1, s2, n);
	while(*s1 == *s2 && i < n){
		if(i == (n-1))
			return 0;
		s1++;
		s2++;
		i++;
	}
	return (*s1-*s2);
}

/* The  mywmemcpy()  function  is  the  wide-character  equivalent of the memcpy(3) function. 
*  It copies n wide characters from the array starting at src to the array starting at dest.
*  mywmemcpy() returns dest.
*/
wchar_t *mywmemcpy(wchar_t *dest, const wchar_t *sc, size_t n){
	wchar_t *s = dest;
	const wchar_t *src = sc;
	int i = 0;
	for(; i < n; ++s, ++src){
		*s = *src;
		i++;
	}
	return dest;
}

/* It fills the array of n wide-characters starting
 * at wcs with n copies of the wide character wc.
 * mywmemset() returns wcs.
 */
wchar_t *mywmemset(wchar_t *s, wchar_t c, size_t n){
	wchar_t *str = s;
	while(n != 0){
		*str = c;
		str++;
		n--;
	}
	return s;
}

/*It allocates and returns a new wide-character  string  whose
* initial contents is a duplicate of the wide-character string pointed to
* by s.
*/
wchar_t *mywcsdup(wchar_t *str){
	int l = mywcslen(str);
	wchar_t *s ;
	if(!(s = (wchar_t*) malloc(sizeof(wchar_t) * l)))
		return NULL;
	while(*str != L'\0'){
		*s = *str;
		s++;
		str++;
	}
	return (s - l);
}

/*checks from first to last wide character
*/
wchar_t *mywcsrchr(wchar_t *str, wchar_t c){
	wchar_t ch = c;
	while(*str != L'\0'){
		if(*str == ch)
			return str;
		str++;
	}
	if(*str == ch)			//for last null (\0) byte if c = L'\0'
		return str;
	else
		return NULL;
}

 
/* Parse WCS into tokens separated by characters in DELIM.  If WCS is
*  NULL, the last string wcstok() was called with is used
*/
wchar_t *mywcstok (wchar_t *wcs, const wchar_t *delim, wchar_t **save_ptr){
	wchar_t *result;
 	if (wcs == NULL){
		if (*save_ptr == NULL){
 //   			__set_errno (EINVAL);
       			return NULL;
        	}
      		else
       			wcs = *save_ptr;
      	}
	wcs += mywcsspn (wcs, delim);
	if (*wcs == L'\0'){
	   	 *save_ptr = NULL;
		 return NULL;
	}
	result = wcs;
	wcs = mywcspbrk (result, delim);
	if (wcs == NULL)
		*save_ptr = NULL;
	else{
	  	*wcs = L'\0';
	     	*save_ptr = wcs + 1;
	}
	return result;
}


