#include <bits/stdc++.h>
using namespace std;

void DigitsInWords(int n){
    string numwords[] = {"zero","one","two","three","four","five","six","seven","eight","nine"};
    if(n==0) return;

    int digit = n%10;
    n=n/10;

    DigitsInWords(n);

    cout<<numwords[digit]<<" ";
}

int main(){
    int n;
    cin>>n;
    DigitsInWords(n);

    return 0;
}