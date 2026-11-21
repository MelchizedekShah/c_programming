#include <stdio.h>

#define MESSAGE_SIZE 100

int main(void) {
    int message[MESSAGE_SIZE];
    int i = 0;
    int c;
    printf("Enter a message: ");
    while ((c = getchar()) != '\n' && c != EOF) {
        if (i < MESSAGE_SIZE) {
            message[i++] = c;
        } else {
            break;
        }
    }

    // Reverse
    for (int k = 0, l = i - 1; k < l; k++, l--) {
        int temp = message[k];
        message[k] = message[l];
        message[l] = temp;
    }

    // Print the message
    printf("Reversal is: ");
    for (int j = 0; j < i; j++) {
        printf("%c", message[j]);
    }
    printf("\n");


    return 0;
}