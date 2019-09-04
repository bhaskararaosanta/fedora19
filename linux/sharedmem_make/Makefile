all: shmserver2 shmclient2
shmserver2: shmserver2.o
	gcc -o shmserver2 shmserver2.o

shmserver2.o: shmserver2.c
	gcc -o shmserver2.o -c shmserver2.c

shmclient2: shmclient2.o
	gcc -o shmclient2 shmclient2.o

shmclient2.o: shmclient2.c
	gcc -o shmclient2.o -c shmclient2.c


#all: shmserver1 shmclient1
#shmserver1: shmserver1.o
#	gcc -o shmserver1 shmserver1.o
#
#shmserver1.o: shmserver1.c
#	gcc -o shmserver1.o -c shmserver1.c
#
#shmclient1: shmclient1.o
#	gcc -o shmclient1 shmclient1.o
#
#shmclient1.o: shmclient1.c
#	gcc -o shmclient1.o -c shmclient1.c


#all: shmserver shmclient
#shmserver: shmserver.o
#	gcc -o shmserver shmserver.o
#
#shmserver.o: shmserver.c
#	gcc -o shmserver.o -c shmserver.c
#
#shmclient: shmclient.o
#	gcc -o shmclient shmclient.o
#
#shmclient.o: shmclient.c
#	gcc -o shmclient.o -c shmclient.c
#
clean:
	rm *.o
	rm shmserver shmclient
	rm shmserver1 shmclient1
