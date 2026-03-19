#include <bits/stdc++.h>
using namespace std;

int power(int a, int b){
    if(b==0) return 1; b--;
    
    int half = power(a,b/2);

    if(b%2 == 0) return half*half;
    else return a*half*half;
}

int main(){
    int n,r;
    cin>>n>>r;
    cout<<power(n,r);
}