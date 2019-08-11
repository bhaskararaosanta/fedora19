objects= main.o func.o
myapp: $(objects)
	gcc -o myapp $(objects)

func.o: func.c
	gcc -o func.o -c func.c

main.o: main.c
	gcc -o main.o -c main.c

clean:
	rm $(objects)

deepClean:
	rm myapp
	rm $(objects)
