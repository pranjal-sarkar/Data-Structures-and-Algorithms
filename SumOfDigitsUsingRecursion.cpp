#include<bits/stdc++.h>
using namespace std;

long sum_recursion(long number){
    int rem, quo;

    if(number == 0){
        return 0;
    }

    rem = number % 10;
    quo = number / 10;

    return rem + sum_recursion(quo);
}

int main(){
    long number, sum;

    cout<<"Enter a number: ";
    cin>>number;

    sum = sum_recursion(number);

    cout<<"sum: "<<sum;

    return 0;
}