object= linkedlist.o main.o
link:$(object)
	gcc -o link linkedlist.o main.o

linkedlist.o: linkedlist.c linkedlist.h
	gcc -o linkedlist.o -c linkedlist.c

main.o: main.c linkedlist.h
	gcc -o main.o -c main.c

clean:
	rm *.o
