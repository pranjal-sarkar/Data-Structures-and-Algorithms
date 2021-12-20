#include<stdio.h>

#define max 1000

int main(){
    int arr[max];
    int n;
    int i, j;
    int temp, flag;

    printf("Enter array size: ");
    scanf("%d", &n);

    printf("Enter elements of array:\n");
    for(i=0;i<n;i++)
        scanf("%d", &arr[i]);
    
    // bubble sort
    for(i=0;i<n;i++){
        flag = 0;
        for(j=0;j<n-i-1;j++){
            if(arr[j] > arr[j+1]){
                temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
                flag = 1;
            }
        }

        if(flag == 0)
            break;
    }

    printf("The sorted array:\n");
    for(i=0;i<n;i++)
        printf("%d ", arr[i]);

    return 0;
}