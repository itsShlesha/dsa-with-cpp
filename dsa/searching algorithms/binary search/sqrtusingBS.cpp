#include <bits/stdc++.h>
using namespace std;

/*
Problem: Integer Square Root (floor of √x)

Key idea:
We want the largest integer `k` such that k*k ≤ x.
Binary search works because the function f(k) = k*k is monotonically increasing.

Approach:
1. Set search space: low = 0, high = x.
2. While search space is valid:
    - mid = low + (high - low)/2
    - if mid*mid <= x:
        - mid is a valid candidate
        - store mid as current answer
        - move right to find possibly larger valid mid (low = mid + 1)
    - else:
        - mid is too big
        - move left (high = mid - 1)
3. Return last stored valid mid as the answer.

Time Complexity: O(log x)
Space Complexity: O(1)
*/

int integerSqrt(int x){
    int low = 0, high = x, ans = 0; long long mid;
    while(low<=high){
        mid = low + (high-low)/2;
        if((mid*mid) <= x){
            low = mid+1; ans = mid;
        }
        else if((mid*mid) > x) high = mid-1;
    }
    return ans;
}

//to make it more fun 
double morePrecision(int n, int precision, int tempSol){
    double factor = 1; double ans = tempSol;
    for(int i=0; i<precision; i++){
        factor = factor/10;
        for(double j=tempSol; j*j<n; j=j+factor){
            ans = j;
        }
    }
    return ans;
}

int main(){

    int x;
    cout<<"Enter a number to find its sqrt: "<<endl;
    cin>>x;
    cout<<integerSqrt(x)<<endl;;

    int tempSol = integerSqrt(x);
    cout<< "More Precision: "<<morePrecision(x,3,tempSol);
    return 0;
}

/*
Mistakes to avoid / key insights:

>> Never assign low = mid (in inclusive binary search), must do low = mid+1 to shrink range.
>> Do not return mid blindly; always return the last valid candidate.
>> Be careful of integer overflow:
   - mid*mid may overflow int for large x
   - use long long for mid, or compare using division: mid <= x / mid
>> Handle non-perfect squares properly:
   - mid*mid == x may never happen
   - solution should still return floor(sqrt(x))
>> Initial ans should be defined (ans = 0) to avoid undefined behavior.
>> Shadowing standard sqrt function is bad practice; rename function to integerSqrt or floorSqrt.
*/
