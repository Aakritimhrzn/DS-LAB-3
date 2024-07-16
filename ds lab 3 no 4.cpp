#include <stdio.h>

// Function to compute the implication (P -> Q)
int implication(int P, int Q) {
    return !P || Q;
}

int main() {
    int P, Q, R;

    printf("P\tQ\tR\tP->Q\tQ->R\tP->R\t(P->Q) && (Q->R) -> (P->R)\n");
    printf("-----------------------------------------------------------\n");

    // Loop through all possible truth values (0 or 1)
    for (P = 0; P <= 1; P++) {
        for (Q = 0; Q <= 1; Q++) {
            for (R = 0; R <= 1; R++) {
                int PQ = implication(P, Q);
                int QR = implication(Q, R);
                int PR = implication(P, R);
                int result = implication(PQ && QR, PR);
                
                // Print the truth table row
                printf("%d\t%d\t%d\t%d\t%d\t%d\t%d\n", P, Q, R, PQ, QR, PR, result);
            }
        }
    }

    return 0;
}

