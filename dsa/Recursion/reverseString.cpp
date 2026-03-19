#include <bits/stdc++.h>
using namespace std;

void reverseString(int i,string &s){
    if(i>=s.length()/2) return;
    swap(s[i],s[s.length()-i-1]);
    i++; s.length()-i-1;
    reverseString(i,s);
}

int main(){
    string str = "Helloworld"; reverseString(0,str);
    cout<<"This is result: "<<str;
}