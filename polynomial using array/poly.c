#include <stdio.h>
#include <stdlib.h>

typedef struct Term {
    int coeff;
    int exp;
} Term;

typedef struct poly {
    int n;      // num of non-zero terms
    Term *t;
}poly;

// Function prototypes
void init(poly *p,int capacity);
void create(poly *p);
poly sum(poly poly1, poly poly2);
poly difference(poly poly1, poly poly2);
void display(poly p);

int main() {
    // Initialize polynomials
    poly poly1;
     init(&poly1,5);
    poly poly2; 
    init(&poly2,5);

    // Create polynomials
    printf("Enter details for Polynomial 1:\n");
    create(&poly1);

    printf("\nEnter details for Polynomial 2:\n");
    create(&poly2);

    // Display original polynomials
    printf("\nPolynomial 1:\n");
    display(poly1);
    printf("\nPolynomial 2:\n");
    display(poly2);

    // Perform addition and subtraction
    poly resultSum = sum(poly1, poly2);
    poly resultDifference = difference(poly1, poly2);

    // Display results
    printf("\nAddition Result:\n");
    display(resultSum);

    printf("\nSubtraction Result:\n");
    display(resultDifference);

    // Free memory
    free(poly1.t);
    free(poly2.t);
    free(resultSum.t);
    free(resultDifference.t);

    return 0;
}

void init(poly *p,int capacity) {
    
    p->n = 0;
    p->t = (Term *)malloc(capacity * sizeof(Term));
    
}

void create(poly *p) {
    printf("Enter the number of terms in the polynomial: ");
    scanf("%d", &(p->n));

    printf("Enter the coefficients and exponents for each term:\n");
    for (int i = 0; i < p->n; ++i) {
        printf("Term %d:\n", i + 1);
        printf("Coefficient: ");
        scanf("%d", &(p->t[i].coeff)); 
        printf("Exponent: ");
        scanf("%d", &(p->t[i].exp));
    }
}

poly sum(poly poly1, poly poly2) {
    poly result;
    init(&result, poly1.n + poly2.n);

    int i = 0, j = 0, k = 0;  

    while (i < poly1.n && j < poly2.n) {
        if (poly1.t[i].exp > poly2.t[j].exp) {
            result.t[k++] = poly1.t[i++];
        } else if (poly1.t[i].exp < poly2.t[j].exp) {
            result.t[k++] = poly2.t[j++];
        } else {
            // Coefficients with the same exponent, add them
            result.t[k].exp = poly1.t[i].exp;
            result.t[k++].coeff = poly1.t[i++].coeff + poly2.t[j++].coeff;
        }
    }    

    // Copy any remaining terms from poly1
    while (i < poly1.n) {
        result.t[k++] = poly1.t[i++];
    }

    // Copy any remaining terms from poly2
    while (j < poly2.n) {
        result.t[k++] = poly2.t[j++];
    }

    result.n = k; // Update the number of terms in the result polynomial
    return result;
}

poly difference(poly poly1, poly poly2) {
    poly result;
    init(&result, poly1.n + poly2.n);

    int i = 0, j = 0, k = 0;

    while (i < poly1.n   && j < poly2.n) {
        if (poly1.t[i].exp > poly2.t[j].exp) {
            result.t[k++] = poly1.t[i++];
        } else if (poly1.t[i].exp < poly2.t[j].exp) {
            result.t[k].exp = poly2.t[j].exp;
            result.t[k++].coeff = -poly2.t[j++].coeff; // Subtract the coefficient
        } else {
            // Coefficients with the same exponent, subtract them
            result.t[k].exp = poly1.t[i].exp;
            result.t[k++].coeff = poly1.t[i++].coeff - poly2.t[j++].coeff;
        }
    }

    // Copy any remaining terms from poly1
    while (i < poly1.n) {
        result.t[k++] = poly1.t[i++];
    }

    // Copy any remaining terms from poly2 with negation
    while (j < poly2.n) {
        result.t[k].exp = poly2.t[j].exp;
        result.t[k++].coeff = -poly2.t[j++].coeff; // Negate the coefficient
    }

    result.n = k; // Update the number of terms in the result polynomial
    return result;
}

void display(poly p) {
    printf("Number of Terms: %d\n", p.n);
    printf("Polynomial Terms:\n");
    for (int i = 0; i < p.n; ++i) {
        printf("Term %d: Coefficient = %d, Exponent = %d\n", i+1 , p.t[i].coeff, p.t[i].exp);
    }
}