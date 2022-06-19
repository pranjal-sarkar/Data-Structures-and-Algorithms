// implement knapsack problem

#include<stdio.h>
#include<stdlib.h>
#include<time.h>

// structure definition
typedef struct s{
    int weight;
    int cost;
    int fraction_taken;
    float ratio;
}node;

// function prototypes
void input(node*, int);
int knapsack(node*, int, float*, int);

int main(){
    int n;
    int i;
    float cost;
    int capacity;
    float *solution;
    clock_t start, end;
    double ex_time;
    node *a;

    printf("Enter number of weights: ");
    scanf("%d", &n);

    printf("Enter capacity of the knapsack: ");
    scanf("%d", capacity);

    a = (node*)malloc(n * sizeof(node));
    
    solution = (float*)malloc(n * sizeof(float));

    input(a, n);

    start = clock();

    cost = knapsack(a, n, solution, capacity);

    end = clock();

    ex_time = (double)((end - start)/CLOCKS_PER_SEC);

    printf("Execution Time: %lf\n", ex_time);

    printf("Optimum Cost: %d", cost);

    return 0;
}

void input(node* a, int n){
    int i;

    printf("Enter weights: ");
    for(i=0;i<n;i++){
        scanf("%d", &a[i].weight);
    }

    printf("Enter prices for each weight: ");
    for(i=0;i<n;i++){
        scanf("%d", &a[i].cost);
    }
}

int knapsack(node *a, int n, float *solution, int capacity){
    int i;
    int k;
    int weightGiven=0;
    float price=0.0;
    node temp;

    for(i=0;i<n;i++){
        a[i].ratio = a[i].cost/a[i].weight;
    }

    // bubble sort the array in desc order acc. to ratio(=cost/weight)
    for(i=0;i<n-1;i++){
        for(k=0;k<n-i;k++){
            if(a[k].ratio < a[k+1].ratio){
                temp = a[k];
                a[k] = a[k+1];
                a[k+1] = temp;
            }
        }
    }
     
    i = 0;
    while(i<n && weightGiven<capacity){
        if(a[i].weight+weightGiven <= capacity){
            solution[i] = 1;
        }
        else{
            solution[i] = (capacity-weightGiven)/a[i].weight;
        }

        weightGiven = weightGiven + solution[i] * a[i].weight;
        price = price + solution[i] * a[i].cost;

        i++;
    }

    return price;
}