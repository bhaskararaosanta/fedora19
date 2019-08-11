myapp: main.o func.o
	gcc -o myapp main.o func.o

func.o: func.c
	gcc -o func.o -c func.c

main.o: main.c
	gcc -o main.o -c main.c

clean:
	rm *.o

deepClean:
	rm myapp
	rm *.o
