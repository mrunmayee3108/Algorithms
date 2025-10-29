#include <stdio.h>
#define INF 9999
#define MAX 20
int main() {
    int n, u, v, min, i, j, edgeCount = 0, totalCost = 0;                             
    int adj[MAX][MAX], visited[MAX] = {0};                
    printf("Enter number of vertices: ");
    scanf("%d", &n);
    printf("Enter adjacency matrix (use 0 if no edge):\n");
    for(i=0; i<n; i++) {
        for (j=0; j<n; j++) {
            scanf("%d", &adj[i][j]);
            if(adj[i][j] == 0)
                adj[i][j] = INF;     
        }
    }
    visited[0] = 1;                    
    printf("\nEdge\tWeight\n");
    while(edgeCount<n-1){
        min = INF;
        for(i=0; i<n; i++){
            if(visited[i]){
                for(j=0; j<n; j++){
                    if(!visited[j] && adj[i][j] < min) {
                        min = adj[i][j];
                        u = i;
                        v = j;
                    }
                }
            }
        }
        printf("%d - %d\t%d\n", u, v, min);
        totalCost += min;
        visited[v] = 1;
        edgeCount++;
    }
    printf("\nTotal Cost of MST: %d\n", totalCost);
    return 0;
}
