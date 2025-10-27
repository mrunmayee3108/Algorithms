#include<stdio.h>
#define INF 9999
#define MAX 100

int main(){
    int adjmatrix[MAX][MAX], dist[MAX], visited[MAX];
    int n, src, i, j, count, min, u, v;
    printf("Enter the number of vertices: ");
    scanf("%d", &n);
    printf("Enter the adjacency matrix. (0 if no edge): \n");
    for(i=0; i<n; i++){
        for(j=0; j<n; j++){
            scanf("%d", &adjmatrix[i][j]);
        }
    }
    printf("Enter the source vertex(0 to %d): ", n-1);
    scanf("%d", &src);
    for(i=0; i<n; i++){
        dist[i] = INF;
        visited[i] = 0;
    }
    dist[src] = 0;
    for(count=0; count<n-1; count++){
        min = INF;
        for(i=0; i<n; i++){
            if(!visited[i] && dist[i]<min){
                min = dist[i];
                u = i;                     // u stores index of the vertex with minimum distance.
            }
        }
        visited[u] = 1;
        for(v=0; v<n; v++){
            if(!visited[v] && adjmatrix[u][v]!=0 && dist[u]+adjmatrix[u][v]<dist[v]){
                dist[v] = dist[u]+adjmatrix[u][v];
            }
        }
    }
    printf("\nVertex\tDistance from source\n");
    for(i=0; i<n; i++){
        printf("\n%d\t%d", i, dist[i]);
    }
    return 0;

}
