#include <stdio.h>
#include <stdbool.h>
#include <ctype.h>

#define MESSAGE_SIZE 100



int main(void) {

    int message[MESSAGE_SIZE];
    int i = 0;
    int c;
    printf("Enter a message: ");
    while ((c = getchar()) != '\n' && c != EOF) {
        if (isalpha(c)) {
            if (i == MESSAGE_SIZE) {
                break;
            }
            message[i++] = tolower(c);
        }
    }

    // check for palindrome
    bool is_palindrome = true;

    for (int j = 0, k = i - 1; j < k; j++, k--) {
        if (message[j] != message[k]) {
            is_palindrome = false;
            break;
        }     
    }

    // Print result
    if (is_palindrome) {
        printf("Palindrome");
    } else {
        printf("Not a palindrome");
    }

    return 0;

}