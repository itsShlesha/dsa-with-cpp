#include <bits/stdc++.h>

using namespace std;

void pattern1(int n){
    for(int i=0; i<n; i++){
        for (int j=0; j<n; j++){
            cout<<"* ";
        }
        cout<<endl;
    }
}

void pattern2(int n){
    for(int i=0; i<n; i++){
        for(int j=0; j<i+1; j++){
            cout<<"* ";
        }
        cout<<endl;
    }
}

void pattern3(int n){
    for(int i=1; i<n+1; i++){
        for(int j=1; j<i+1; j++){
            cout<<j;
        }
        cout<<endl;
    }
}

void pattern4(int n){
        for(int i=1; i<n+1; i++){
        for(int j=1; j<i+1; j++){
            cout<<i;
        }
        cout<<endl;
    }

}

void pattern5(int n){
    for(int i = n; i>0; i--){
        for(int j = i; j>0; j--){
            cout<<"* ";
        }
        cout<<endl;
    }
}

void pattern6(int n){
    for(int i = n+1; i>0; i--){
        for(int j = 1; j<i; j++){
            cout<<j;
        }
        cout<<endl;
    }
}

void pattern7(int n){
    for(int i = 1; i<=n; i++){
        for(int k=0; k<=n-i; k++){
            cout<<" ";
        }
        for(int j = 1; j<(i*2); j++){
            cout<<"*";
        }
        cout<<endl;
    }
}

void pattern8(int n){
    for(int i = 0; i<=n; i++){
        for(int k=0; k<=i; k++){
            cout<<" ";
        }
        for(int j = 0; j<2*n-(2*i +1); j++){
            cout<<"*";
        }
        cout<<endl;
    }
}

void pattern9(int n){
    pattern7(n); pattern8(n);
}

void pattern10(int n){
    for(int i=1; i<=2*n-1; i++){
        int stars = i;
        if(i>n) stars = 2*n-i;
        for(int j = 1; j<=stars; j++){
            cout<<"*";
        }
        cout<<endl;
    }
}

void pattern11(int n){
    int start = 1;
    for(int i=0; i<n; i++){
        if(i%2==0) start=1;
        else start=0;
        for(int j=0; j<i+1; j++){
            cout<<start; start=1-start;
        }
        cout<<endl;
    }
}

void pattern12(int n){
    for(int i=1; i<=n; i++){
        for(int j = 1; j<=i; j++){
            cout<<j;
        }
         for(int k = 1; k<=2*n - 2*i - 1; k++){
            cout<<" ";
        }
        for(int l=i; l>=1; l--){
            cout<<l;
        }
        cout<<endl;
    }
}

void pattern13(int n){
    int count=1;
    for(int i=0; i<n; i++){
        for(int j=0; j<i+1; j++){
            cout<<count<<" "; count++;
        }
        cout<<endl;
    }
}

void pattern14(int n){
    char arr[] = {'A','B','C','D','E'}; int count=0;
    for(int i=0; i<n; i++){
        for(int j=0; j<i+1; j++){
            cout<<arr[count]; count++;
        }
        count=0;
        cout<<endl;
    }
}

void pattern15(int n){
    char arr[] = {'A','B','C','D','E'}; int count=0;
    for(int i=n; i>0; i--){
        for(int j=i; j>0; j--){
            cout<<arr[count]; count++;
        }
        cout<<endl; count=0;
    }
}

void pattern16(int n){
    char arr[] = {'A','B','C','D','E'}; 
    for(int i=0; i<n; i++){
        for(int j=0; j<i+1; j++){
            cout<<arr[i]; 
        }
        cout<<endl;
    }
}

int main(){
    int n; cin>>n;
    pattern16(n);
}