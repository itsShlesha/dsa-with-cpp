#include <bits/stdc++.h>
using namespace std;

bool checkPalindrome(int i, int j,string s){
    if(i>=j) return true;
    if(s[i]!=s[j]) return false;
    return checkPalindrome(i++,j++,s);
}

int main(){
    string str = "Shlesha";
    cout<<(checkPalindrome(0,str.length()-1,str)?"true":"false");
}