all:
	gcc -o snake src/*.c -Iinclude $(shell sdl2-config --cflags --libs) -Wall

clean:
	rm -f snake *.o