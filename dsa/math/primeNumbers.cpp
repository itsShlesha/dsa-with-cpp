#include <bits/stdc++.h>
using namespace std;

bool isPrime(int n){
    if(n<0) return false;
    if(n==0) return true;
    if(n==1) return true;
    for(int i=2; i*i<n; i++){
        if(n%i==0) return false;
    }
    return true;
}

int main(){
    int n;
    cin>>n;
    cout<<(isPrime(n)?"true":"false");
}