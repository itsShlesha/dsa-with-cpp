#include <bits/stdc++.h>
using namespace std;

/*
Problem: Book Allocation Problem
(find the minimum possible value of the maximum pages given to a student)

Idea:
We have to divide books (in order, no splitting) among m students.
The goal is to minimize the maximum pages any student gets.

This is not a direct binary search on array,
it is binary search on the ANSWER.

Why binary search works:
If I can allocate books such that no student gets more than X pages,
then I can definitely do it for any value > X also.
So the answer space is monotonic.

Approach:
1. First handle edge case:
   - if students > books, allocation is not possible.

2. Search space:
   - minimum value = max pages in a single book
     (because a book cannot be split)
   - maximum value = sum of all pages
     (one student reads all books)

3. Binary search on this range.
   - mid = assumed max pages per student

4. Check feasibility using isPossible():
   - assign books one by one
   - keep adding pages to current student
   - if pages exceed mid:
        -> move to next student
   - if students needed > m:
        -> mid is too small

5. If mid is possible:
   - store it as answer
   - try to find a smaller value (left side)

6. Otherwise:
   - search on right side

Finally return the stored answer.

Time Complexity:
O(n log(sum of pages)) where n = no. of students

Space Complexity:
O(1)
*/


bool isPossible(vector<int>& arr, int n, int m, int mid){
    int studentCount = 1;
    int pageSum = 0;

    for(int i=0; i<n; i++){
        if(pageSum + arr[i] <= mid){
            pageSum += arr[i];
        }
        else{
            studentCount++;
            if(studentCount > m || arr[i] > mid){
                return false;
            }
            pageSum = arr[i];
        }
    }
    return true;
}

int allocateBooks(vector<int>& arr, int n, int m){
    if(m>n) return -1;
    int s = *max_element(arr.begin(), arr.end());
    int sum = 0;
    for(int i=0; i<n; i++){
        sum += arr[i];
    }
    int e = sum;
    int ans = -1, mid;
    while(s<=e){
        mid = s+(e-s)/2;
        if(isPossible(arr, n, m, mid)){
            ans = mid;
            e = mid-1;
        }
        else{
            s = mid+1;
        }
    }
    return ans;
}

int main(){

    vector<int> arr = {10,20,30,40};
    int n = arr.size(), m = 2;
    cout<<"The maximum no. of pages allocated to a student is: "<<allocateBooks(arr, n, m)<<endl;

    return 0;
}

/*
Important points / mistakes to avoid:

>> This is binary search on answer, not on index.

>> Lower bound should NOT be 0.
   It should be the maximum element of the array.

>> mid must be calculated inside the while loop.

>> In isPossible():
   - books must be assigned contiguously
   - never split a book

>> If arr[i] > mid, return false immediately.

>> If studentCount > m, mid is invalid.

>> Always do:
   - possible -> e = mid - 1
   - not possible -> s = mid + 1

>> Handle case when m > n separately.
*/
