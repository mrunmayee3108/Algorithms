#include<stdio.h>
int max(int a, int b){
    return (a>b?a:b);
}
int main(){
    int n, W;
    printf("Enter the number of items: ");
    scanf("%d", &n);
    int p[n], wt[n];
    printf("Enter the profits and weights of each item (space separated):\n");
    for(int i=0; i<n; i++){
        scanf("%d %d",&p[i], &wt[i]);
    }
    printf("Enter the capacity of the knapsack: ");
    scanf("%d", &W);
    
    int dp[n+1][W+1];
    
    // initialising 1st row and 1st column to 0.
    for(int i=0; i<=n; i++){
        for(int j=0; j<=W; j++){
            dp[i][j] = 0;
        }
    }
    
    // filling the dp table
    for(int i=0; i<=n; i++){
        for(int j=0; j<=W;j++){
            if(i==0 || j==0){
                dp[i][j] = 0;
            }
            else if(j<wt[i]){
                dp[i][j] = dp[i-1][j];
            }else{
                dp[i][j] = max(p[i]+dp[i-1][j-wt[i]], dp[i-1][j]);
            }
        }
    }
    printf("Maximum profit: %d", dp[n][W]);
    return 0;
}