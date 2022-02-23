#include<stdio.h>

#define max 20

// function prototypes
void MergeSort(int[], int, int);
void Merge(int[], int, int, int);

int main(){
    int arr[max];
    int i, n;

    printf("Enter array size: ");
    scanf("%d", &n);

    printf("Enter array elements:\n");
    for(i=0;i<n;i++){
        scanf("%d", &arr[i]);
    }

    MergeSort(arr, 0, n-1);

    printf("The Sorted Array is:\n");
    for(i=0;i<n;i++){
        printf("%d ", arr[i]);
    }

    return 0;
}

void MergeSort(int arr[], int lb, int ub){
    int mid;

    if(lb < ub){
        mid = (lb + ub)/2;
        MergeSort(arr, lb, mid);
        MergeSort(arr, mid+1, ub);

        Merge(arr, lb, mid, ub);
    }
}

void Merge(int arr[], int lb, int mid, int ub){
    int i = lb;
    int j = mid + 1;
    int k = lb;
    int temp[max];

    while(i<=mid && j<=ub){
        if(arr[i] > arr[j]){
            temp[k++] = arr[j++];
        }
        else{
            temp[k++] = arr[i++];
        }
    }

    while(i<=mid){
        temp[k++] = arr[i++];
    }

    while(j<=ub){
        temp[k++] = arr[j++];
    }

    i = 0;
    while(i<k){
        arr[i] = temp[i];
        i++;
    }
}