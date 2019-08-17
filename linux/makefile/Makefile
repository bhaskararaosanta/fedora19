final: addnum.o addnumextern.o
	gcc -o final addnum.o addnumextern.o

addnum.o: addnum.c
	gcc -o addnum.o -c addnum.c

addnumextern.o: addnumextern.c
	gcc -o addnumextern.o -c addnumextern.c

clean:
	rm *.o
