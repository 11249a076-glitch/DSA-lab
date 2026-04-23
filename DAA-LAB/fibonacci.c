#include <stdio.h>
int fibonacci_recursive(int n) {
    if (n == 0)
        return 0;
    else if (n == 1)
        return 1;
    else
        return fibonacci_recursive(n - 1) + fibonacci_recursive(n - 2);
}
int main() {
    int n, i;
    printf("Enter the number of terms: ");
    scanf("%d", &n);
    int t1 = 0, t2 = 1, next;
    printf("\nFibonacci Series using Iterative Method:\n");
    for (i = 0; i < n; i++) {
        printf("%d ", t1);
        next = t1 + t2;
        t1 = t2;
        t2 = next;
    }
    printf("\n\nFibonacci Series using Recursive Method:\n");
    for (i = 0; i < n; i++) {
        printf("%d ", fibonacci_recursive(i));
    }
    return 0;
}