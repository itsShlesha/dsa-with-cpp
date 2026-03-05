#include <bits/stdc++.h>
using namespace std;


/*
Segmented Sieve

Problem:
Find all prime numbers in a given range [L, R].

This is useful when R is very large and running a normal
sieve up to R would take too much memory.

Example
L = 10, R = 30
Primes in this range → 11, 13, 17, 19, 23, 29


Approach:
A normal sieve works well if n is small, but if R is very large
(for example 10^12), we cannot create a boolean array of size R.

So instead of sieving the entire range from 0 → R,
we process only the range we care about.

Idea: (Segmented Sieve Algorithm)

1. First find all prime numbers up to √R using a normal sieve.
2. These primes will be used as "base primes".
3. Create a boolean array representing numbers from L → R.
4. For each base prime, mark its multiples inside [L, R].
5. Numbers that remain unmarked are primes.

Time Complexity: O((R-L+1) log log R)
-> We only mark numbers in the given segment instead of
sieving the entire range up to R.

Space Complexity: O(√R + (R-L+1))
-> √R space for base primes
-> (R-L+1) space for the segment itself
*/

vector<int> segmentedSieve(long long L, long long R){
    //S1: finding primes upto sqrt(R)
    long long limit = sqrt(R) + 1;
    vector<bool> prime(limit+1, true);
    vector<int> basePrimes;

    for(long long i = 2; i<=limit; i++){
        if(prime[i]){
            basePrimes.push_back(i);
            for(long long j = i*j; j<=limit; j+=i){
                prime[j]=false;
            }
        }
    }

    //S2: create segment [L,R]
    vector<bool> isPrime(R-L+1, true);
    
    //S3: mark multiples using base primes
    for(long long p: basePrimes){
        long long start = max(p*p,((L+p-1)/p)*p);
        for(long long j = start; j<=R; j+=p){
            isPrime[j-L] = false;
        }
    }

    if(L==1) isPrime[0]=false;

    //s4: collect primes
    vector<int>primes;
    for(int i=0; i<isPrime.size(); i++){
        if(isPrime[i]) primes.push_back(i+L);
    }

    return primes;
}

int main() {

    long long L = 10, R = 30;

    vector<int> primes = segmentedSieve(L, R);

    for(int p : primes) {
        cout << p << " ";
    }
}

/*
Mistakes I Could Make While Solving:

1. Forgetting that the segment array represents numbers
   from L → R, so indexing should be done using (j - L).

2. Incorrectly finding the starting multiple of p in the segment.
   The correct formula is:
   start = max(p*p, ((L+p-1)/p)*p)

3. Not handling the case when L = 1.
   Since 1 is not prime, we must mark it manually.

4. Forgetting that p*p might overflow for large p,
   so using long long is safer.


Key takeaway for myself
-> Normal sieve works when n is reasonably small
-> Segmented sieve is useful when the range is large
-> Instead of storing primes till R, we only process the needed segment
*/