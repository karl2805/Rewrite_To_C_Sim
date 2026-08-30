CC = gcc

CFLAGS = -Wall -Iinclude $(shell pkg-config --cflags glfw3)
LIBS = $(shell pkg-config --libs glfw3) -ldl -lm

OBJ = main.o glad.o

app: $(OBJ)
	$(CC) $(OBJ) -o app $(LIBS)
	rm *.o

main.o: glad.o main.c
	gcc $(CFLAGS) -c main.c -o main.o

glad.o: src/glad.c
	gcc $(CFLAGS) -c src/glad.c -o glad.o

clean:
	rm -rf build app
