all:
	gcc -o snake *.c $(shell sdl2-config --cflags --libs) -Wall

clean:
	rm -f snake *.o