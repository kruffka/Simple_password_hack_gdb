# gdb_simple_pass_hack

To Compile main and crack_gen:
    make main

Compile test:
    make test

Compiling with -fno-stack-protector option to be able modify return addr of function frame

main.c is actual program with simple password check that I'm "hacking" with gdb
Crack_gen.c can write in file 'crack' ascii symbols from given rip addr (addr probably will be different)
and then we can launch program in gdb like "r < crack"

file content: 111111 (1 char ascii = 0x31 hex)

After reading file func frame:
0x7ffffffee0b0:	0x31	0x31	0x31	0x31	0x31	0x31	0x00	0x00
0x7ffffffee0b8:	0xed	0x12	0x00	0x08	0x00	0x00	0x00	0x00
0x7ffffffee0c0:	0xe8	0x12	0x7a	0xff	0xff	0x7f	0x00	0x00
0x7ffffffee0c8:	0xa0	0x12	0x00	0x08	0x00	0x00	0x00	0x00
0x7ffffffee0d0:	0xf0	0xe0	0xfe	0xff	0xff	0x7f	0x00	0x00
0x7ffffffee0d8:	0x57	0x12	0x00	0x08	0x00	0x00	0x00	0x00

saved rbp = 0x7ffffffee0d0
rip (return addr) = 0x7ffffffee0d8

instruction we need to return after function call (password is correct condition):
=> 0x0000000008001260 <+74>:    lea    0xdb4(%rip),%rdi        # 0x800201b

We need to rewrite 32b, then rbp 8b and finally rip 8b to 0x0000000008001260

In crack_gen.c:
unsigned long rip_addr = 0x0000000008001260;

launch gdb, r < crack => done :)

Logs:
gdb_log_cracked.log

test.c program just to see func frames in memory 
![alt text](https://github.com/kruffka/gdb_simple_pass_hack/blob/master/stack_functionframe.png?raw=true)
