#include<bits/stdc++.h>
using namespace std;

   int GCD(int a,int b)
    {        if((b%a) == 0)
            return a;
            
        if(a == 0)
            return b;
        
        return GCD(b%a, a);
    }

int main(){
    cout<<GCD(7, 8);

    return 0;
}