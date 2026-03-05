#include <bits/stdc++.h>
using namespace std;

const long long MOD = 1000000007;

long long factorial(long long n){
    long long ans = 1;
    for(long long i = 2; i <= n; i++){
        ans = (ans * i) % MOD;
    }
    return ans;
}

int main(){
    long long n;
    cin >> n;
    cout << factorial(n);
}