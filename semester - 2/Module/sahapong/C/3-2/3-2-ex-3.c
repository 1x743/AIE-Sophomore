#include <stdio.h>
#include <stdbool.h>

bool isPrime(int num) {
    if (num < 2) return false;
    for (int i = 2; i * i <= num; i++) {
        if (num % i == 0) return false;
    }
    return true;
}

int main() {
    int n;

    printf("Enter a number (n > 1): ");
    scanf("%d", &n);

    printf("Prime numbers less than or equal to %d:\n", n);
    for (int i = 2; i <= n; i++) {
        if (isPrime(i)) {
            printf("%d ", i);
        }
    }
    printf("\n");

    return 0;
}