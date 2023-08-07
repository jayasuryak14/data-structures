#include <stdio.h>
long long int factorial(int num) {
    long long int result = 1;
    for (int i = 1; i <= num; i++) {
        result *= i;
    }
    return result;
}
int main() {
    int num;
    printf("Enter a number: ");
    scanf("%d", &num);
    if (num < 0) {
        printf("Factorial is not defined for negative numbers.\n");
    } else {
        long long int fact = factorial(num);
        printf("Factorial of %d is %lld\n", num, fact);
    }
    return 0;
}
