FLAGS=-fno-stack-protector -g

all: main test

main: main.c
	gcc main.c -o main $(FLAGS)

test: test.c
	gcc test.c -o test $(FLAGS)

clean:
	rm -rf *.o main test
