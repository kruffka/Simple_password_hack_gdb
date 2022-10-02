FLAGS=-fno-stack-protector -g

all: main #test

main: main.c crack_gen
	gcc main.c -o main $(FLAGS)

crack_gen: crack_gen.c
	gcc crack_gen.c -o crack_gen

# test: test.c
# 	gcc test.c -o test $(FLAGS)

clean:
	rm -rf *.o main crack_gen test
