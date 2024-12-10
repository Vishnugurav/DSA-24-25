#include<stdio.h>
#include<stdlib.h>
#include "logic.c"

// Main function to demonstrate polynomial operations
int main() {
    poly p1, p2, p3, p4;

    // Initialize polynomials with capacity for 3 terms
    init(&p1, 3);
    init(&p2, 3);

    // Append terms to polynomial 1: 3x^2 + 5x^1 + 6
    append(&p1, 3, 4);
    append(&p1, 5, 1);
    append(&p1, 6, 0);

    // Append terms to polynomial 2: 2x^2 + 3x^1 + 4
    append(&p2, 2, 2);
    append(&p2, 3, 1);
    append(&p2, 4, 0);

    // Display polynomials
    printf("Polynomial 1: ");
    display(p1);
    printf("Polynomial 2: ");
    display(p2);

    // Perform sum
    p3 = sum(p1, p2);
    printf("Sum of polynomials: ");
    display(p3);

    // Perform difference
    p4 = difference(p1, p2);
    printf("Difference of polynomials: ");
    display(p4);

    return 0;
}