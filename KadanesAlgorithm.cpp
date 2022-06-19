#include<bits/stdc++.h>
using namespace std;

#define max 1000

int kadane(int arr[], int n){
    int currSum=0;
    int maxSum=0;
    int i;

    for(i=0;i<n;i++){
        currSum += arr[i];

        maxSum = max(maxSum, currSum);

        if(currSum < 0)
            currSum = 0;
    }

    return maxSum;
}

int main(){
    int n;
    int arr[max];
    int i;

    cin>>n;

    for(i=0;i<n;i++){
        cin>>arr[i];
    }

    cout<<kadane(arr, n);

    return 0;
}