#include <stdio.h>
#include <stdbool.h>

int main() {
    printf(" p     q     r     段    p?段  p?段?r  殆    殆?r  (p?段?r)?(殆?r)  (p?段?r)?(殆?r)\n");

    for (int i = 0; i < 2; ++i) {
        for (int j = 0; j < 2; ++j) {
            for (int k = 0; k < 2; ++k) {
                bool p = i, q = j, r = k;
                bool not_q = !q;
                bool p_and_not_q = p && not_q;
                bool p_and_not_q_or_r = p_and_not_q || r;
                bool not_p = !p;
                bool not_p_or_r = not_p || r;
                bool implication = !p_and_not_q_or_r || not_p_or_r;
                bool equivalence = p_and_not_q_or_r == not_p_or_r;

                printf(" %-5s %-5s %-5s %-5s %-5s %-7s %-5s %-5s %-13s %-13s\n",
                    p ? "T" : "F", q ? "T" : "F", r ? "T" : "F", not_q ? "T" : "F",
                    p_and_not_q ? "T" : "F", p_and_not_q_or_r ? "T" : "F", not_p ? "T" : "F",
                    not_p_or_r ? "T" : "F", implication ? "T" : "F", equivalence ? "T" : "F");
            }
        }
    }
    return 0;
}

