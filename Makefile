


StrList.o : StrList.c main.o											
	gcc  -c  -Wall  StrList.c 
	
StrList: StrList.o main.o
	gcc -o StrList StrList.o main.o

main.o: main.o StrList.h
	gcc -c -Wall main.c
clean :
	rm -f *.o StrList 
all: StrList
