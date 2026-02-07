#include <bits/stdc++.h>
using namespace std;

/*
PROBLEM:
Given two arrays where each array represents a number (each element is a digit),
add the two numbers and return the result as a new array.

APPROACH & WHY:
- Start adding digits from the end of both arrays (just like manual addition).
- Maintain a carry while adding digits.
- If one array becomes shorter, treat its digit as 0.
- Store result digits in reverse order and finally reverse the result.

This approach works because addition naturally proceeds from least significant
digit to most significant digit.

TIME COMPLEXITY:
O(max(n, m)) where n and m are sizes of the two arrays.
SPACE COMPLEXITY:
O(max(n, m)) for storing the result.
*/

vector<int> sumArrays(vector<int>&arr1, vector<int>&arr2){
    int n = arr1.size(), m = arr2.size(), carry = 0;
    vector<int> sumOfArrays; 
    int i = n-1, j = m-1;
    while(i>=0 || j>=0 || carry){
        int val1 = (i>=0)? arr1[i]:0;
        int val2 = (j>=0)? arr2[j]:0;

        int sum = val1 + val2 + carry;
        carry = sum/10;
        sumOfArrays.push_back(sum%10);

        i--; j--;
    }

    reverse(sumOfArrays.begin(), sumOfArrays.end());

    return sumOfArrays;
}

int main(){
    vector<int> arr1 = {4,1,6,0};
    vector<int> arr2 = {3,9,6};

    vector<int> result = sumArrays(arr1,arr2);
    for(int x:result){
        cout<<x<<" ";
    }
    return 0;
}

/*
COMMON MISTAKES TO AVOID:
- Forgetting to decrement i and j inside the loop, leading to infinite loops.
- Using the wrong index for the second array (arr2[i] instead of arr2[j]).
- Not handling carry after both arrays are exhausted.
- Pre-allocating result size incorrectly and then using push_back().
- Forgetting to reverse the result since digits are added from right to left.
*/