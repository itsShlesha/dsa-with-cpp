#include <bits/stdc++.h>
using namespace std;

int length(string s){
    int count = 0;
    for(char ch:s){
        count++;
    }
    return count;
}

bool palindrome(string s){
    int start = 0;
    int end = length(s)-1;
    while(start<end){
        if(s[start]!=s[end]) return false;
        start++;end--;
    }
    return true;
}

string reverse(string s){
    int start = 0; 
    int end = length(s)-1;
    while(start<end){
        swap(s[start],s[end]);
        start++;end--;
    }
    return s;
}

int main(){
    string str;
    cout<<"Enter a string: "<<endl;
    cin>>str;
    cout<<"The length of string: "<<length(str)<<endl;
    cout<<"Is it a palindrome? "<<(palindrome(str)?"true":"false")<<endl;
    cout<<"The reversed string is: "<<reverse(str)<<endl;
}