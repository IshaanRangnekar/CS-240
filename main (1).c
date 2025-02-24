#include <stdio.h>

// Function to print all divisors of a given number, separated by commas
void print_divisors(int num) {
    int first = 1;  // Flag to indicate if the current divisor is the first printed
    for (int i = 1; i <= num; i++) {
        // Check if i is a divisor of num
        if (num % i == 0) {
            // If this isn't the first divisor, print a comma before printing the next one
            if (!first) {
                printf(",");
            }
            // Print the divisor
            printf("%d", i);
            // Set the flag to 0 after printing the first divisor
            first = 0;
        }
    }
    // Print a newline after listing all divisors
    printf("\n");
}

// Function to compute the Greatest Common Divisor (GCD) using the Euclidean algorithm
int gcd(int a, int b) {
    while (b != 0) {
        int temp = b;
        // Update b to the remainder of a divided by b
        b = a % b;
        // Set a to the old value of b
        a = temp;
    }
    // a now holds the GCD of the original a and b
    return a;
}

// Function to compute the Least Common Multiple (LCM) using the relation LCM(a, b) = (a / GCD(a, b)) * b
int lcm(int a, int b) {
    return (a / gcd(a, b)) * b;
}

int main() {
    int X1, X2;
    
    // Read two positive integers from the user and ensure they meet the criteria:
    // Both must be greater than 0 and less than 1000.
    if (scanf("%d %d", &X1, &X2) != 2 || X1 <= 0 || X2 <= 0 || X1 >= 1000 || X2 >= 1000) {
        // Exit the program with an error code if the input is invalid
        return 1;
    }
    
    // Print the divisors of X1
    print_divisors(X1);
    // Print the divisors of X2
    print_divisors(X2);
    
    // Depending on the relative sizes of X1 and X2, print either their GCD or LCM:
    // - If X1 is greater than X2, print the GCD.
    // - Otherwise, print the LCM.
    if (X1 > X2) {
        printf("%d\n", gcd(X1, X2));
    } else {
        printf("%d\n", lcm(X1, X2));
    }
    
    // Exit the program successfully
    return 0;
}
