#include<stdio.h>

#define max 10000

int main(){
    int arr[max];
    int n;
    int i, j;
    int temp;

    printf("Enter elements of array: ");
    scanf("%d", &n);

    printf("Enter elements of array:\n");
    for(i=0;i<n;i++)
        scanf("%d", &arr[i]);

    // insertion sort
    i = 1;
    while(i<n){
        // printf("\nHello");
        j = i - 1;
        temp = arr[i];

        while(1){
            if (temp >= arr[j] || j==-1){
                arr[j+1] = temp;
                break;
            }
            else{
                arr[j+1] = arr[j];
            }
            j = j - 1;
        }

        i = i + 1;
    }

    printf("The sorted array is: \n");
    for(i=0;i<n;i++){
        printf("%d ", arr[i]);
    }

    return 0;
}