// Implementing Quick Sort algorithm
#include<stdio.h>
#include<stdlib.h>

#define max 25

// function prototypes
void quicksort(int*, int , int);
int partition(int*, int, int);

int main(){
    int *a;
    int n, i;

    printf("Enter array size: ");
    scanf("%d", &n);

    a = (int *)malloc(n * sizeof(int));

    printf("Enter array elemnents: ");
    for(i=0;i<n;i++)
        scanf("%d", &a[i]);

    quicksort(a, 0, n-1);

    printf("The sorted array is: ");
    for(i=0;i<n;i++)
        printf("%d ", a[i]);

    return 0;
}

void quicksort(int *a, int lb, int ub){
    int mid;

    if(lb < ub){
        mid = partition(a, lb, ub);
        quicksort(a, lb, mid-1);
        quicksort(a, mid+1, ub);    
    }
}

int partition(int *a, int lb, int ub){
    int pivot = a[lb];
    int temp;

    int i=lb, j=ub;

    while(1){
        while(a[i] < pivot){
            i = i + 1;
        }

        while(a[j] > pivot){
            j = j - 1;
        }

        if(i < j){
            temp = a[j];
            a[j] = a[i];
            a[i] = temp;
        }
        else{
            return j;
        }
    }
}