#include<stdio.h>
#define L 20 //max length of a string

int main() {
    char string[L+1];
    int index, len;

    printf("size of string = %d bytes\n", sizeof(string));
    printf("Enter a word: ");
    scanf("%s", string);

    index = 0;
    while (string[index] != '\0') index++;
    len = index;

    printf("Length of your word (%s) = %d\n", string, len);

    printf("Print each character: ");
    for (index = 0; index < len; index++) {
        printf(" %c ", string[index]);
    }

    printf("\nPrint each character backward: ");
    for (index = len - 1; index >= 0; index--) {
        printf(" %c ", string[index]);
    }

    printf("\n");
    return 0;
}
