#include<bits/stdc++.h>
using namespace std;

int recur(int n){
    if (n==0){
        return 0;
    }

    return n + recur(n-1);
}

int main(){
    int n, sum;

    cout<<"Enter a number: ";
    cin>>n;

    sum = recur(n);

    cout<<"The result is : "<< sum;

    return 0;
}