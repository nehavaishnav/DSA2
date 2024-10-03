#include <stdio.h>
#include <stdlib.h>

// Define the structure for a polynomial term node
struct Node {
    int coefficient;
    int exponent;
    struct Node* next;
};

// Function to create a new node with given coefficient and exponent
struct Node* createNode(int coefficient, int exponent) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->coefficient = coefficient;
    newNode->exponent = exponent;
    newNode->next = NULL;
    return newNode;
}

// Function to insert a new term in the polynomial linked list in sorted order

void insertTerm(struct Node** header, int coefficient, int exponent) {
    struct Node* newNode = createNode(coefficient, exponent);
    if (*header == NULL || (*header)->exponent < exponent) {
        newNode->next = *header;
        *header = newNode;
    } else {
        struct Node* temp = *header;
        while (temp->next != NULL && temp->next->exponent > exponent) {
            temp = temp->next;
        }
        if (temp->next != NULL && temp->next->exponent == exponent) {
            temp->next->coefficient += coefficient;
            free(newNode);
        } else {
            newNode->next = temp->next;
            temp->next = newNode;
        }
    }
}

// Function to display a polynomial linked list
void displayPolynomial(struct Node* header) {
    struct Node* temp = header;
    if (temp == NULL) {
        printf("Polynomial is empty.\n");
        return;
    }

    while (temp != NULL) {
        printf("%d*x^%d", temp->coefficient, temp->exponent);
        if (temp->next != NULL)
            printf(" + ");
        temp = temp->next;
    }
    printf("\n");
}

// Function to add two polynomials and return the result
struct Node* sum(struct Node* header1, struct Node* header2) {
    struct Node* result = NULL;
    struct Node* temp1 = header1;
    struct Node* temp2 = header2;

    while (temp1 != NULL && temp2 != NULL) {
        if (temp1->exponent > temp2->exponent) {
            insertTerm(&result, temp1->coefficient, temp1->exponent);
            temp1 = temp1->next;
        } else if (temp1->exponent < temp2->exponent) {
            insertTerm(&result, temp2->coefficient, temp2->exponent);
            temp2 = temp2->next;
        } else {
            int sumCoeff = temp1->coefficient + temp2->coefficient;
            if (sumCoeff != 0)
                insertTerm(&result, sumCoeff, temp1->exponent);
            temp1 = temp1->next;
            temp2 = temp2->next;
        }
    }

    while (temp1 != NULL) {
        insertTerm(&result, temp1->coefficient, temp1->exponent);
        temp1 = temp1->next;
    }
    while (temp2 != NULL) {
        insertTerm(&result, temp2->coefficient, temp2->exponent);
        temp2 = temp2->next;
    }

    return result;
}

int main() {
    struct Node* header1 = NULL;
    struct Node* header2 = NULL;

    // Create the first polynomial: 4x^3 + 3x^2 + 5x^1 + 2
    insertTerm(&header1, 4, 3);  
    insertTerm(&header1, 3, 2);  
    insertTerm(&header1, 5, 1);  
    insertTerm(&header1, 2, 0);

    // Create the second polynomial: 3x^2 + 4x^1 + 1
    insertTerm(&header2, 3, 2);
    insertTerm(&header2, 4, 1);
    insertTerm(&header2, 1, 0);

    printf("Polynomial 1: ");
    displayPolynomial(header1);
    
    printf("Polynomial 2: ");
    displayPolynomial(header2);

    // Sum of both polynomials
    struct Node* result = sum(header1, header2);
    printf("Sum of polynomials: ");
    displayPolynomial(result);

    return 0;
}
