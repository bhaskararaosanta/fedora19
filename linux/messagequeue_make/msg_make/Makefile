all: msgserver msgclient
msgserver: msgserver.o
	gcc -o msgserver msgserver.o

msgserver.o: msgserver.c
	gcc -o msgserver.o -c msgserver.c

msgclient: msgclient.o
	gcc -o msgclient msgclient.o

msgclient.o: msgclient.c
	gcc -o msgclient.o -c msgclient.c

clean:
	rm *.o
	rm msgserver msgclient
