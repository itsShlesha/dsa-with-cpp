#include <bits/stdc++.h>
using namespace std;

/*
COUNT SMALLER ELEMENTS ON RIGHT (GFG STYLE)
Using Merge Sort + Counting

Idea:
- Use merge sort
- While merging, if left[i] > right[j]:
    → all elements from right[j] to right[end] are smaller
    → count = (end - j + 1)

Store:
- vector<pair<int,int>> → {value, original_index}
- ans[i] → count of smaller elements on right of arr[i]

Time: O(n log n)
Space: O(n)
*/

// Merges two sorted halves AND counts smaller elements
void merge(vector<pair<int,int>>& v, vector<int>& ans, int s, int e){

    vector<pair<int,int>> t;   // temporary array

    int mid = s + (e - s) / 2;

    int index1 = s;           // pointer for left half
    int index2 = mid + 1;     // pointer for right half

    /*
    MERGE + COUNT LOGIC
    */
    while(index1 <= mid && index2 <= e){

        // If left element is greater → inversion-like case
        if(v[index1].first > v[index2].first){

            /*
            Since right side is sorted,
            all elements from index2 to e are smaller than v[index1]

            So we add:
            (number of remaining elements in right half)
            */
            ans[v[index1].second] += (e - index2 + 1);

            // Insert smaller element to maintain sorted order
            t.push_back(v[index2++]);

        } else {
            // Normal merge (no count update)
            t.push_back(v[index1++]);
        }
    }

    /*
    COPY REMAINING ELEMENTS
    (only one loop will run)
    */

    // Remaining left elements
    while(index1 <= mid)
        t.push_back(v[index1++]);

    // Remaining right elements
    while(index2 <= e)
        t.push_back(v[index2++]);

    //COPY BACK TO ORIGINAL ARRAY

    for(int k = 0; k < t.size(); k++){
        v[s + k] = t[k];
    }
}

void mergeSort(vector<pair<int,int>>& v, vector<int>& ans, int s, int e){

    // Base case: single element
    if(s >= e) return;

    int mid = s + (e - s) / 2;

    // Sort left half
    mergeSort(v, ans, s, mid);

    // Sort right half
    mergeSort(v, ans, mid + 1, e);

    // Merge both halves and count
    merge(v, ans, s, e);
}

vector<int> constructLowerArray(vector<int>& arr){

    int n = arr.size();

    /*
    Store value + original index
    because positions change during sorting
    */
    vector<pair<int,int>> v;
    for(int i = 0; i < n; i++){
        v.push_back({arr[i], i});
    }

    // Answer array initialized to 0
    vector<int> ans(n, 0);

    // Apply merge sort
    mergeSort(v, ans, 0, n - 1);

    return ans;
}

int main(){

    vector<int> arr = {12, 1, 2, 3, 0, 11, 4};

    vector<int> ans = constructLowerArray(arr);

    // Print result
    for(int x : ans) cout << x << " ";
}