# gdb_simple_pass_hack

Compile:
    make main

To compile test:
    make test

Compiling with -fno-stack-protector option to be able modify return addr of function frame

main.c is actual program with simple password check that im "hacking" with gdb

test.c program just to see func frames in memory 

![alt text](https://github.com/kruffka/gdb_simple_pass_hack/master/stack_functionframe.png?raw=true)
