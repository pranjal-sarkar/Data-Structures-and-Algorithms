#include<stdio.h>

#define max 25

// function prototypes
void maxterm(int[], int, int*);

int main(){
    int arr[max];
    int n, i;
    int maxNumber;
    int *p;

    printf("Enter array size: ");
    scanf("%d", &n);

    printf("Enter array elements: \n");
    for(i=0;i<n;i++){
        scanf("%d", &arr[i]);
    }

    p = &arr[n];
    maxterm(arr, n, p);

    printf("Max Term is: %d", *p);

    return 0;
}

// void maxterm(int arr[], int n, int *p){
//     if(n<0)
//         return;

//     if(*p > arr[n])
//         *p = arr[n];
//     // else
//     //     *p = arr[n-1];

//     maxterm(arr, n-1, p);
// }

void maxterm(int arr[], int n, int *res){
    if(n < 0) 
        return;
    *res = *res > arr[n] ? *res : arr[n];
    maxterm(arr, n - 1, res);
}