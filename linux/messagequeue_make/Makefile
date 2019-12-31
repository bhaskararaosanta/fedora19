all: msgserver3 msgclient3
msgserver3: msgserver3.o
	gcc -o msgserver3 msgserver3.o

msgserver3.o: msgserver3.c
	gcc -o msgserver3.o -c msgserver3.c

msgclient3: msgclient3.o
	gcc -o msgclient3 msgclient3.o

msgclient3.o: msgclient3.c
	gcc -o msgclient3.o -c msgclient3.c


#all: msgserver msgclient
#msgserver: msgserver.o
#	gcc -o msgserver msgserver.o
#
#msgserver.o: msgserver.c
#	gcc -o msgserver.o -c msgserver.c
#
#msgclient: msgclient.o
#	gcc -o msgclient msgclient.o
#
#msgclient.o: msgclient.c
#	gcc -o msgclient.o -c msgclient.c
#
clean:
	rm *.o
	rm msgserver msgclient
