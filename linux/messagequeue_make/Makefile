all: msgserver1 msgclient1
msgserver1: msgserver1.o
	gcc -o msgserver1 msgserver1.o

msgserver1.o: msgserver1.c
	gcc -o msgserver1.o -c msgserver1.c

msgclient1: msgclient1.o
	gcc -o msgclient1 msgclient1.o

msgclient1.o: msgclient1.c
	gcc -o msgclient1.o -c msgclient1.c


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
