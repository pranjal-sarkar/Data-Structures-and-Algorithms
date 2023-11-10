#include<bits/stdc++.h>
using namespace std;

#define MAX_LENGTH 10

void check_for_palindrome(char *name, int len, int i){
    cout<<"i: "<<i<<endl;
    if (i>len-i-1){
        cout<<"Output: Yes";
        return ;
    }
    if(name[i] != name[len-i-1]){
        cout<<"Output: No";
        return ;
    }
    check_for_palindrome(name, len, i+1);
}

int main(){
    char name[MAX_LENGTH];

    cout<<"Input: ";
    cin>>name;

    // cout<<"j: "<< strlen(name);

    check_for_palindrome(name, strlen(name), 0);

    return 0;
}