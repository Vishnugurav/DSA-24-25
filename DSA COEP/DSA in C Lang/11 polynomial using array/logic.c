#include<stdio.h>
#include<stdlib.h>
#include"header.h"

void init(poly *p, int capacity){
    p->n =0;
    p->t = (term*)malloc(sizeof(term) * capacity);
    return;
}

void append(poly *p, int coeff, int expo) {
    p->t[p->n].coeff = coeff;
    p->t[p->n].expo = expo;      
    p->n++;  // Increment the number of terms
    return;                   
}

void display(poly p) {
    for (int i = 0; i < p.n; i++) {
        printf("%dx^%d", p.t[i].coeff, p.t[i].expo);
        if (i < p.n - 1) {
            printf(" + ");
        }
    }
    printf("\n");
}

poly sum(poly poly1, poly poly2) {
    poly result;
    init(&result, poly1.n + poly2.n); // Initialize result with enough capacity

    int i = 0, j = 0;
    while (i < poly1.n && j < poly2.n) {
        if (poly1.t[i].expo > poly2.t[j].expo) {
            append(&result, poly1.t[i].coeff, poly1.t[i].expo);
            i++;
        } else if (poly1.t[i].expo < poly2.t[j].expo) {
            append(&result, poly2.t[j].coeff, poly2.t[j].expo);
            j++;
        } else {
            append(&result, poly1.t[i].coeff + poly2.t[j].coeff, poly1.t[i].expo);
            i++;
            j++;
        }
    }

    // Copy remaining terms of poly1, if any
    while (i < poly1.n) {
        append(&result, poly1.t[i].coeff, poly1.t[i].expo);
        i++;
    }

    // Copy remaining terms of poly2, if any
    while (j < poly2.n) {
        append(&result, poly2.t[j].coeff, poly2.t[j].expo);
        j++;
    }

    return result;
}


poly difference(poly poly1, poly poly2) {
    poly result;
    init(&result, poly1.n + poly2.n); // Initialize result with enough capacity

    int i = 0, j = 0;
    while (i < poly1.n && j < poly2.n) {
        if (poly1.t[i].expo > poly2.t[j].expo) {
            append(&result, poly1.t[i].coeff, poly1.t[i].expo);
            i++;
        } else if (poly1.t[i].expo < poly2.t[j].expo) {
            append(&result, -poly2.t[j].coeff, poly2.t[j].expo);
            j++;
        } else {
            append(&result, poly1.t[i].coeff - poly2.t[j].coeff, poly1.t[i].expo);
            i++;
            j++;
        }
    }

    // Copy remaining terms of poly1, if any
    while (i < poly1.n) {
        append(&result, poly1.t[i].coeff, poly1.t[i].expo);
        i++;
    }

    // Copy remaining terms of poly2, if any
    while (j < poly2.n) {
        append(&result, -poly2.t[j].coeff, poly2.t[j].expo);
        j++;
    }

    return result;
}


