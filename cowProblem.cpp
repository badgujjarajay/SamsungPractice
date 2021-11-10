// Aggresive cows SPOJ
// Farmer John has built a new long barn, with N (2 <= N <= 100) stalls. The stalls are located along a straight line at positions x1,...,xN (0 <= xi <= 500).
// His C (2 <= C <= N) cows don't like this barn layout and become aggressive towards each other once put into a stall. To prevent the cows from hurting each other, FJ wants to assign the cows to the stalls, such that the minimum distance between any two of them is as large as possible. What is the largest minimum distance?

// Input Format
// t – the number of test cases, then t test cases follows.
// for every test case
// Line 1: Two space-separated integers: N and C
// Lines 2..N space seprated integers denoting stall location, xi

// Constraints
// (2 <= N <= 100)
// (0 <= xi <= 500)
// timelimit 1 sec..
// memory limit 256 MB

// Output Format
// For each test case output one integer: the largest minimum distance.

// Sample Input 0
// 1
// 5 3
// 1
// 2
// 8
// 4
// 9
// Sample Output 0
// 3

#include <bits/stdc++.h>
using namespace std;


int main() {
    int t;
    cin>>t;
    while(t--) {
        int N, C;
        cin>>N>>C;
        int ar[N];
        for(int i=0; i<N; i++) cin>>ar[i];
        sort(ar, ar+N);
        auto check = [&](int x) {
            int p = 1, cur = ar[0];
            for(int i=1; i<N; i++) {
                if(ar[i] - cur >= x) ++p, cur = ar[i];
            }
            return p >= C;
        };
        int lo = 0, hi = 500, ans = 0;
        while(lo <= hi) {
            int mi = (lo + hi) / 2;
            if(check(mi)) ans = mi, lo = mi + 1;
            else hi = mi - 1;
        }
        
        cout<<ans<<"\n";
    }
    return 0;
}