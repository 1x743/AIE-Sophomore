#include<stdio.h>
#define L 20 //max length of a string

int main() {
    char character;
    int index, len;
    char string[L+1];
    
    printf("Enter a word: ");
    scanf("%s", string);
    
    index = 0;
    while (string[index] != '\0') index++;
    len = index;

    for (index = 0; index < len; index++) {
        if (string[index] >= 'A' && string[index] <= 'Z') {
            string[index] = string[index] + ('a' - 'A');
        }
    }

    printf("New string = %s\n", string);

    return 0;
}
