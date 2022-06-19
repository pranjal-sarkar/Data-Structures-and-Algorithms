// selection sort
#include<stdio.h>
#include<stdlib.h>

// function prototypes
void selectionsort(int *a, int n);

int main(){
    int *a;
    int i, n, j;
    int pos, min, temp;
    
    printf("Enter array length: ");
    scanf("%d", &n);

    a=(int*)malloc(n*sizeof(int));
    
    printf("Enter array elements: \n");
    for(i=0;i<n;i++){
        scanf("%d", &a[i]);
    }

    selectionsort(a, n);

    return 0;
}
 
 void selectionsort(int *a, int n) {
    int i, j;
    int pos, min, temp;

    for(i=0;i<n-1;i++){
        min = a[i];
        
        for(j=i+1;j<n;j++){
            if(a[j] < min){
                min = a[j];
                pos = j;
            }
        }

        if(min < a[i]){
            temp = a[pos];
            a[pos] = a[i];
            a[i] = temp;
        }
    }
    
    printf("The sorted array: \n");
    for(i=0;i<n;i++){
        printf("%d ", a[i]);
    }
}