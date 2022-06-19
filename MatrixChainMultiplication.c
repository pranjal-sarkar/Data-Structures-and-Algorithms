// implement matrix chain multiplication using DP
#include<stdio.h>
#include<limits.h>
#include<time.h>
#include<stdlib.h>

// function prototypes
int mat_chain_mul(int*, int);

int main(){
    int n;
    int i;
    int *dimensions;
    int res;
    clock_t start, end;
    double ex_time;

    printf("Enter number of matrices: ");
    scanf("%d", &n);

    dimensions = (int*)malloc((n+1) * sizeof(int));

    printf("Enter the dimensions: ");
    for(i=0;i<=n;i++){
        scanf("%d", &dimensions[i]);
    }

    start = clock();

    res = mat_chain_mul(dimensions, n);

    end = clock();

    printf("res: %d", res);

    ex_time = (double)((end - start)/CLOCKS_PER_SEC);

    printf("\nExecution Time: %lf", ex_time);

    return 0;
}

int mat_chain_mul(int *dimensions, int n){
    int m[n][n], s[n][n];
    int i, j, k, l, q, x;

    for(i=0;i<=n;i++){
        m[i][i] = 0;
    }

    // implementation of the algorithm
    for(l=2;l<=n;l++){
        for(i=1;i<=n-l+1;i++){
            j = i + l -1;
            m[i][j] = INT_MAX;

            for(k=i;k<j;k++){
                q = m[i][k] + m[k+1][j] + dimensions[i-1] * dimensions[k] * dimensions[j];

                if(q < m[i][j]){
                    m[i][j] = q;
                    s[i][j] = k;    
                }
            }
        }
    }

    x = n;

    for(i=2;i<n;i++){
        printf("%d ", s[1][x]);
        x = s[1][x];
    }
    printf("\n");

    return m[1][n];
}