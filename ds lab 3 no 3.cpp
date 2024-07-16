#include <stdio.h>

// Function to print truth values
void print_truth_values(int P, int Q, int P_imp_Q, int not_Q, int not_P) {
    printf("P: %d, Q: %d, P->Q: %d, !Q: %d, !P: %d\n", P, Q, P_imp_Q, not_Q, not_P);
}

int main() {
    int P, Q;
    int P_imp_Q, not_Q, not_P;

    // Print header
    printf("Verifying Modus Tollens using truth table:\n\n");

    // Truth table for P and Q
    printf("P Q P->Q !Q !P\n");
    printf("-------------\n");

    for (P = 0; P <= 1; P++) {
        for (Q = 0; Q <= 1; Q++) {
            // Implication: P -> Q is equivalent to !P || Q
            P_imp_Q = (!P || Q);
            // Not Q
            not_Q = !Q;
            // Not P
            not_P = !P;

            // Print the current truth values
            print_truth_values(P, Q, P_imp_Q, not_Q, not_P);

            // Verify Modus Tollens: if P -> Q and !Q are true, then !P must be true
            if (P_imp_Q && not_Q && !not_P) {
                printf("Modus Tollens is not verified for P = %d, Q = %d\n", P, Q);
                return 1;
            }
        }
    }

    printf("\nModus Tollens is verified for all cases.\n");

    return 0;
}

