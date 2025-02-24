#include <stdio.h>


void print_divisors(int num) {
    int first = 1;
    for (int i = 1; i <= num; i++) {
        if (num % i == 0) {
            if (!first) {
                printf(",");
            }
            printf("%d", i);
            first = 0;
        }
    }
    printf("\n");
}


int gcd(int a, int b) {
    while (b != 0) {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}


int lcm(int a, int b) {
    return (a / gcd(a, b)) * b;
}

int main() {
    int X1, X2;
    
    
    if (scanf("%d %d", &X1, &X2) != 2 || X1 <= 0 || X2 <= 0 || X1 >= 1000 || X2 >= 1000) {
        return 1;
    }
    
    
    print_divisors(X1);
    print_divisors(X2);
    
    
    if (X1 > X2) {
        printf("%d\n", gcd(X1, X2));
    } else {
        printf("%d\n", lcm(X1, X2));
    }
    
    return 0;
}
