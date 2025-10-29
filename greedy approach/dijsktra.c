#include<stdio.h>
#define inf 9999
#define MAX 50
int main(){
    int n, adj[MAX][MAX], src, visited[MAX], dist[MAX], min, u, v;
    printf("Enter the number of vertices: ");
    scanf("%d", &n);
    printf("Enter the adjacency matrix:\n");
    for(int i=0; i<n; i++){
        for(int j=0; j<n;j++){
            scanf("%d", &adj[i][j]);
        }
    }
    printf("Enter the source vertex (0 to %d): ",n-1);
    scanf("%d", &src);
    for(int i=0; i<n; i++){
        visited[i] = 0;
        dist[i] = inf;
    }
    dist[src] = 0;
    
    // finding unvisited vertex with smallest distance
    for(int count=0; count<n-1; count++){
        min = inf;
        for(int i=0; i<n; i++){
            if(!visited[i] && dist[i]<min){
                min = dist[i];
                u = i; // u is the index of the vertex with min dist.
            }
        }
        visited[u] = 1;
        
        // update all distances adjacent of u. 
        for(v=0; v<n; v++){
            if(!visited[v] && adj[u][v]!=0 && dist[u]+adj[u][v]<dist[v]){
                dist[v] = dist[u]+adj[u][v];
            }
        }
    }
    printf("\nVertex\tDistance from source\n");
    for(int i=0; i<n; i++){
        printf("\n%d\t%d", i, dist[i]);
    }
    return 0;
}
