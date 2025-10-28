#include <stdio.h>

int n, m, h, p = 0, t0 = 0, d = 256, q = 13, i, s;

void rabin_karp(char T[], char P[]) {
    h = 1;
    for (i = 1; i <= m - 1; i++)
        h = (h * d) % q;

    p = 0; t0 = 0;
    for (i = 1; i <= m; i++) {
        p = (d * p + P[i]) % q;
        t0 = (d * t0 + T[i]) % q;
    }

    for (s = 0; s <= n - m; s++) {
        if (p == t0) {
            for (i = 1; i <= m; i++)
                if (P[i] != T[s + i])
                    break;
            if (i > m)
                printf("Pattern found at index %d and in shift %d (1 based indexing)", s + 1, s); 
        }
        if (s < n - m) {
            t0 = (d * (t0 - T[s + 1] * h) + T[s + m + 1]) % q;
            if (t0 < 0) t0 = t0 + q;
        }
    }
}

int main() {
    printf("Enter length of text: ");
    scanf("%d", &n);
    printf("Enter length of pattern: ");
    scanf("%d", &m);

    char T[500], P[500];   

    printf("Enter text (no spaces): ");
    scanf("%s", T + 1);    
    printf("Enter pattern (no spaces): ");
    scanf("%s", P + 1);    
    rabin_karp(T, P);
    return 0;
}
