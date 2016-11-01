
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
 
#ifndef _MYWCHAR_H
#define _MYWCHAR_H
#include <stddef.h>

typedef struct hashtable1{
	int (*p[3])();
	size_t (*q[3])();
	wchar_t *(*r[14])();
}ht1;

size_t mywcslen(wchar_t *);
wchar_t * mywcscpy(wchar_t * , const wchar_t * );
wchar_t *mywcpcpy(wchar_t *, const wchar_t *);
wchar_t * mywcsncpy(wchar_t *, const wchar_t * , size_t );
int mywcscmp(wchar_t *, const wchar_t *);
int mywcsncmp(wchar_t *, const wchar_t *, size_t);
wchar_t *mywcscat(wchar_t *, const wchar_t *);
wchar_t *mywcsncat(wchar_t *, const wchar_t *, size_t );
wchar_t *mywcschr(wchar_t *, wchar_t);
size_t mywcscspn(const wchar_t *, const wchar_t *);
wchar_t *mywcspbrk(const wchar_t *, const wchar_t *);
size_t mywcsspn(const wchar_t *, const wchar_t *);
wchar_t *mywcsstr(wchar_t *, const wchar_t *);
wchar_t *mywmemchr(wchar_t *, wchar_t, size_t);
int mywmemcmp(wchar_t *, wchar_t *, size_t);
wchar_t *mywmemcpy(wchar_t *, const wchar_t *, size_t);
wchar_t *mywmemset(wchar_t *, wchar_t, size_t);
wchar_t *mywcsdup(const wchar_t *);
wchar_t *mywcsrchr(wchar_t *, wchar_t);
wchar_t *mywcstok (wchar_t *, const wchar_t *, wchar_t **);
#endif

