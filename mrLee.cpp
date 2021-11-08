// Mr. Lee has to travel various offices abroad to assist branches of each place. But he has a problem. The airfare would be real high as all offices he has to visit are in foreign countries. He wants to visit every location only one time and return to hometown office with the lowest expense. Help this company-caring man calculate the lowest expense.

// Input Format
// First line contains a single integer t denoting number of testcases.
// For every test case there are following inputs
// a) Single integer n denoting number of total locations(including hometown office location)
// b) next n lines conatains n space seprated integers which results in the formation of n*n matrix for every test case
// Note: The matrix created above represent cost i.e mat[i][j] represents cost of moving from ith location to jth location.
// First line represent the hometown office
// and trajectory is... person will start from hometown office and then visit rest n-1 office and then return to hometown office.

// Constraints
// 1 <= n <= 12
// 1 <= t <= 30
// If it is impossible to move between two cities then cost is represented as zero.
// Time limit 1 sec
// Memory Limit 256MB

// Output Format
// for each test case output a single integer in seprate line denoting the required airfare cost

// Sample Input 0
// 2
// 5
// 0 14 4 10 20
// 14 0 7 8 7
// 4 5 0 7 16
// 11 7 9 0 2
// 18 7 17 4 0
// 5
// 9 9 2 9 5
// 6 3 5 1 5
// 1 8 3 3 3
// 6 0 9 6 8
// 6 6 9 4 8
// Sample Output 0
// 30
// 18

#include <bits/stdc++.h>
using namespace std;

int N, done, fare[12][12], dp[1<<12][12];

int solve(int mask, int p) {
    if(mask == done) return fare[p][0];
    if(dp[mask][p] != -1) return dp[mask][p];
    
    int ans = INT_MAX;
    for(int i=0; i<N; i++) {
        if(mask&(1<<i)) continue;
        int f = fare[p][i];
        if(f == 0) f = 9999;
        ans = min(ans, f + solve(mask|(1<<i), i));
    }
    return dp[mask][p] = ans;
}

int main() {
    int t;
    cin>>t;
    while(t--) {
        cin>>N;
        for(int i=0; i<N; i++) for(int j=0; j<N; j++) cin>>fare[i][j];
        memset(dp, -1, sizeof dp);
        done = (1<<N)-1;
        int ans = solve(1, 0);
        cout<<ans<<"\n";
    }
    return 0;
}