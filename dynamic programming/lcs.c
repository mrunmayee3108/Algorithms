#include<stdio.h>

int max(int a, int b) {
    return a > b ? a : b;
}

int main() {
    int m, n;
    printf("Enter the number of elements in the first sequence: ");
    scanf("%d", &m);
    printf("Enter the number of elements in the second sequence: ");
    scanf("%d", &n);

    char x[m+1], y[n+1];  
    printf("Enter the elements of the first sequence: ");
    for (int i = 1; i <= m; i++) scanf(" %c", &x[i]);
    printf("Enter the elements of the second sequence: ");
    for (int j = 1; j <= n; j++) scanf(" %c", &y[j]);

    int L[m+1][n+1];

    for (int i = 0; i <= m; i++) {
        for (int j = 0; j <= n; j++) {
            if (i == 0 || j == 0)
                L[i][j] = 0;
            else if (x[i] == y[j])
                L[i][j] = L[i-1][j-1] + 1;
            else
                L[i][j] = max(L[i-1][j], L[i][j-1]);
        }
    }

    int length = L[m][n];
    printf("LCS length: %d\n", length);

    char lcs_str[length+1];
    lcs_str[length] = '\0';
    int i = m, j = n, idx = length - 1;

    while (i > 0 && j > 0) {
        if (x[i] == y[j]) {
            lcs_str[idx--] = x[i];
            i--; j--;
        } else if (L[i-1][j] > L[i][j-1])
            i--;
        else
            j--;
    }

    printf("LCS sequence: %s\n", lcs_str);
    return 0;
}
