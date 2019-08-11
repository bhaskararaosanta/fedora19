shmserver: shmserver.o
	gcc -o shmserver shmserver.o

shmserver.o: shmserver.c
	gcc -o shmserver.o -c shmserver.c

#shmclient: shmclient.o
#	gcc -o shmclient shmclient.o

#shmclient.o: shmclient.c
#	gcc -o shmclient.o -c shmclient.c

clean:
	rm *.o
	rm shmserver shmclient
