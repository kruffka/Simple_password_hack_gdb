#include <stdio.h>
#include <string.h>
#include <unistd.h>

int pass_check(char *correct_enc_pass) {

    char password[20];
    scanf("%s", password);
    // printf("%s\n", password);

    if (strcmp(correct_enc_pass, password) == 0)
        return 1;

    return 0;
}

int main() {

    int correct = 0;
    char correct_enc_pass[] = "qwerty"; // encrypted key to unlock program

    printf("Input password:");
    correct = pass_check(correct_enc_pass);

    if (correct) {
        printf("Password is correct!\n");

        while (1) {
            printf("Program running..\n");
            sleep(1);
        }

    } else {
        printf("Incorrect password. Try again.\n");
    }


    return 0;
}