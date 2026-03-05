#include <bits/stdc++.h>
using namespace std;

/*
LeetCode 204 — Count Primes
Problem:
Given an integer n, return the number of prime numbers strictly less than n.

Prime number → a number greater than 1 that has exactly two factors:
1 and itself.

Example
n = 10
Primes less than 10 → 2, 3, 5, 7
Answer = 4

Approach:
The brute force way would be:
for every number from 2 to n-1, check if it's prime.

But that would take too long because checking a prime itself
takes O(√n), so overall complexity becomes large.

Instead we use the Sieve of Eratosthenes.

Idea: (Sieve of Erastosthenes Algorithm)
Instead of checking if a number is prime,
we eliminate numbers that are definitely NOT prime.

Steps:

1. Assume every number is prime initially.
2. Start from the first prime number → 2
3. Mark all multiples of 2 as not prime.
4. Move to the next number that is still marked prime.
5. Mark its multiples.
6. Continue this process.

Time Complexity: O(n log log n)
-> This is because each prime marks its multiples,
but the total amount of marking decreases rapidly.
-> It's much faster than checking each number individually.

Space Complexity: O(n)
-> We keep a boolean array of size n to track which numbers
are still considered prime.
*/

int countPrimes(int n) {
         if(n <= 2) return 0;

        int count = 0;
        vector<bool> primes(n, true);

        primes[0] = primes[1] = false;

        for(int i = 2; i < n; i++){
            if(primes[i]) {
                count++;

                for(long long j = 1LL*i*i; j < n; j += i){
                    primes[j] = false;
                }
            }
        }

        return count;
    }

int main(){
    int n;
    cin>>n;
    cout<<countPrimes(n);
}
/*
Mistakes I Made While Solving:
1. At first I wasn't actually checking primes.
   I just looped until √n and incremented count,
   which obviously doesn't give the number of primes.

2. I started marking multiples from 2*i.
   That works, but it's inefficient.
   i*i is better because smaller multiples were already handled.

3. I didn't handle small values of n properly,
   which caused runtime errors with vector indexing.

4. I didn't understand initially why we only go till √n.



Key takeaway for myself
-> Checking if ONE number is prime → O(√n)
-> Counting primes in a range → use Sieve of Eratosthenes
*/