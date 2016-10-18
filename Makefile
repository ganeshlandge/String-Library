all: string wchar
string: string.o strmain.o
	cc string.o strmain.o -o string
string.o: string.c mystring.h
	cc -Wall -c string.c
strmain.o: strmain.c string.c mystring.h
	cc -Wall -c strmain.c
wchar: wchar.o wcharmain.o string.o
	cc wchar.o wcharmain.o string.o -o wchar
wchar.o: wchar.c mywchar.h
	cc -Wall -c wchar.c
wcharmain.o: wcharmain.c wchar.c mywchar.h
	cc -Wall -c wcharmain.c wchar.c
clean:
	rm *.o
