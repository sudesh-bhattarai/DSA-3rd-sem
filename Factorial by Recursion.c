#include<stdio.h>
int factorial(int n) {
    //Base case
    if(n == 0)
        return 1;
    //Recursive case
    return n * factorial(n-1);
}
// Sum of natural numbers using recursion
int sum(int n) {
    //Base case
    if(n == 0)
        return 0;
    // Recursive case
    return n + sum(n-1);
}
int main()
{
    int n;
    printf("Enter a number: ");
    scanf("%d", &n);
    printf("\n===Recursion Examples ===\n");
    printf("Factorial of %d = %d\n",n,factorial(n));
    printf("sum of first %d natural numbers = %d\n",n,sum(n));
return 0;
}