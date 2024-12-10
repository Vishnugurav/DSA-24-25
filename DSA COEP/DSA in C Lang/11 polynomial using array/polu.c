#include <stdio.h>
#include <stdlib.h>

typedef struct Term {
    int coeff;  // Coefficient of the term
    int exp;    // Exponent of the term
} Term;

typedef struct poly {
    int n;      // Number of non-zero terms
    Term *t;    // Dynamic array of terms
} poly;

// Function to initialize polynomial with given capacity
void init(poly *p, int capacity) {
    p->n = 0; // No terms initially
    p->t = (Term *)malloc(capacity * sizeof(Term)); // Allocate memory for terms
}

// Function to append a term to the polynomial
void append(poly *p, int coeff, int exp) {
    p->t[p->n].coeff = coeff;  // Add coefficient
    p->t[p->n].exp = exp;      // Add exponent
    p->n++;                    // Increment the number of terms
}

// Function to display a polynomial
void display(poly p) {
    for (int i = 0; i < p.n; i++) {
        printf("%dx^%d", p.t[i].coeff, p.t[i].exp);
        if (i < p.n - 1) {
            printf(" + ");
        }
    }
    printf("\n");
}

// Function to sum two polynomials
poly sum(poly poly1, poly poly2) {
    poly result;
    init(&result, poly1.n + poly2.n); // Initialize result with enough capacity

    int i = 0, j = 0;
    while (i < poly1.n && j < poly2.n) {
        if (poly1.t[i].exp > poly2.t[j].exp) {
            append(&result, poly1.t[i].coeff, poly1.t[i].exp);
            i++;
        } else if (poly1.t[i].exp < poly2.t[j].exp) {
            append(&result, poly2.t[j].coeff, poly2.t[j].exp);
            j++;
        } else {
            append(&result, poly1.t[i].coeff + poly2.t[j].coeff, poly1.t[i].exp);
            i++;
            j++;
        }
    }

    // Copy remaining terms of poly1, if any
    while (i < poly1.n) {
        append(&result, poly1.t[i].coeff, poly1.t[i].exp);
        i++;
    }

    // Copy remaining terms of poly2, if any
    while (j < poly2.n) {
        append(&result, poly2.t[j].coeff, poly2.t[j].exp);
        j++;
    }

    return result;
}

// Function to subtract two polynomials
poly difference(poly poly1, poly poly2) {
    poly result;
    init(&result, poly1.n + poly2.n); // Initialize result with enough capacity

    int i = 0, j = 0;
    while (i < poly1.n && j < poly2.n) {
        if (poly1.t[i].exp > poly2.t[j].exp) {
            append(&result, poly1.t[i].coeff, poly1.t[i].exp);
            i++;
        } else if (poly1.t[i].exp < poly2.t[j].exp) {
            append(&result, -poly2.t[j].coeff, poly2.t[j].exp);
            j++;
        } else {
            append(&result, poly1.t[i].coeff - poly2.t[j].coeff, poly1.t[i].exp);
            i++;
            j++;
        }
    }

    // Copy remaining terms of poly1, if any
    while (i < poly1.n) {
        append(&result, poly1.t[i].coeff, poly1.t[i].exp);
        i++;
    }

    // Copy remaining terms of poly2, if any
    while (j < poly2.n) {
        append(&result, -poly2.t[j].coeff, poly2.t[j].exp);
        j++;
    }

    return result;
}

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
