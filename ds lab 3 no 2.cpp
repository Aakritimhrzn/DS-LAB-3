#include <stdio.h>

// Function to print truth values
void print_truth_values(int P, int Q, int P_imp_Q) {
    printf("P: %d, Q: %d, P->Q: %d\n", P, Q, P_imp_Q);
}

int main() {
    int P, Q;
    int P_imp_Q;

    // Print header
    printf("Verifying Modus Ponens using truth table:\n\n");

    // Truth table for P and Q
    printf("P Q P->Q\n");
    printf("--------\n");

    for (P = 0; P <= 1; P++) {
        for (Q = 0; Q <= 1; Q++) {
            // Implication: P -> Q is equivalent to !P || Q
            P_imp_Q = (!P || Q);

            // Print the current truth values
            print_truth_values(P, Q, P_imp_Q);

            // Verify Modus Ponens: if P and P -> Q are true, then Q must be true
            if (P && P_imp_Q && !Q) {
                printf("Modus Ponens is not verified for P = %d, Q = %d\n", P, Q);
                return 1;
            }
        }
    }

    printf("\nModus Ponens is verified for all cases.\n");

    return 0;
}

