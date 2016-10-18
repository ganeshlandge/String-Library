#include <stddef.h>
size_t mywcslen(wchar_t *);
wchar_t * mywcscpy(wchar_t * , const wchar_t * );
wchar_t *mywcpcpy(wchar_t *, const wchar_t *);
wchar_t * mywcsncpy(wchar_t *, const wchar_t * , size_t );
wchar_t * mywcscmp(wchar_t *, const wchar_t *);
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
wchar_t *wcstok (wchar_t *, const wchar_t *, wchar_t **);

