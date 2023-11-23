#include <bits/stdc++.h>
using namespace std;
void printArrayRecursively(int arr[], int n)
{
    // Your code here
    // Use recursion to print array elements from start to end
    static int i;

    if(i==n){
        return ;
    }

    cout<<arr[i++]<<' ';

    printArrayRecursively(arr, n);
}

int main(){
    int arr[] = {1, 2, 3, 4};

    printArrayRecursively(arr, 4);

    return 0;
}