all: semaphore_without semaphore_with semaphore
semaphore_without: semaphore_without.o
	gcc -o semaphore_without semaphore_without.o

semaphore_without.o: semaphore_without.c
	gcc -o semaphore_without.o -c semaphore_without.c

semaphore_with: semaphore_with.o
	gcc -o semaphore_with semaphore_with.o

semaphore_with.o: semaphore_with.c
	gcc -o semaphore_with.o -c semaphore_with.c

semaphore: semaphore.o
	gcc -o semaphore semaphore.o

semaphore.o: semaphore.c
	gcc -o semaphore.o -c semaphore.c

clean:
	rm *.o
	rm semaphore_without
	rm semaphore_with
	rm semaphore
