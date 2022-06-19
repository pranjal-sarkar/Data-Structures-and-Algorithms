// implement djikstra's algorithm
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<limits.h>

#define max 100

// function prototypes
void djikstra(int[max][max], int, int);

int main(){
    int A[max][max], n;
    int i, j;
    int startnode;

    printf("enter number of vertices: ");
    scanf("%d", &n);

    printf("Enter adjacency matrix of the graph: \n");
    for(i=0;i<n;i++){
        for(j=0;j<n;j++){
            scanf("%d", &A[i][j]);
        }
    }

    printf("Enter startnode: ");
    scanf("%d", &startnode);

    djikstra(A, n, startnode);

    return 0;
}

void djikstra(int A[max][max], int n, int startnode){
    int cost[max][max], pred[max], visited[max], distance[max];
    int i, j;
    int count;
    int minDistance, nextnode;

    // copy and adjust adjacency matrix
    for(i=0;i<n;i++){
        for(j=0;j<n;j++){
            if(A[i][j]==0){
                cost[i][j] = INT_MAX;
            }
            else{
                cost[i][j] = A[i][j];
            }
        }
    }

    // maintain distance[] array, pred[] array, visited[] array
    for(i=0;i<n;i++){
        distance[i] = cost[startnode][i];
        pred[i] = startnode;
        visited[i] = 0;
    }

    distance[startnode] = 0;
    visited[startnode] = 1;

    count = 1;
    while(count < n-1){
        minDistance = INT_MAX;
        for(i=0;i<n;i++){
            if(distance[i] < minDistance && visited[i] == 0){
                minDistance = distance[i];
                nextnode = i;
            }
        }
        
        visited[nextnode] = 1;

        for(i=0;i<n;i++){
            if(visited[i]==0){
                if(minDistance + cost[nextnode][i] < distance[i]){
                    distance[i] = minDistance + cost[nextnode][i];
                    pred[i] = nextnode;
                }
            }
        }

        count ++;
    }
    
    // to display the node distances
    for(i=0;i<n;i++){
        printf("\n%d Distance: %d\n", i, distance[i]);
        j=i;
        while(j!=startnode){
            printf("Path->%d ", pred[j]);
            j = pred[j];
        }
    }
}