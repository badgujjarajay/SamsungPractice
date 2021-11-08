// We have been given N balloons, each with a number of coins associated with it. On bursting a balloon i, the number of coins gained is equal to A[i-1]*A[i]*A[i+1].
// Also, balloons i-1 and i+1 now become adjacent. Find the maximum possible profit earned after bursting all the balloons. Assume an extra 1 at each boundary.
// where A[i] represents coins of ith ballon.

// Input Format
// First line contain an integer n denoting number of balloons.
// Second line contains n space seprated integers representing coins of each ballon

// Constraints
// 1<=n<=10
// 1<=A[i]<=100000
// timelimit 1sec
// memory limit 256 MB

// Output Format
// output maximum number of coins that can be attained following the above conditions

// Sample Input 0
// 2
// 5 10
// Sample Output 0
// 60
// Explanation 0
// Explanation - First Burst 5, Coins = 1*5*10
//           Then burst 10, Coins+= 1*10*1
//           Total = 60
// Sample Input 1
// 5
// 1 2 3 4 5
// Sample Output 1
// 110

#include <bits/stdc++.h>
using namespace std;

#define int long long

int dp[11][11];

int solve(int ar[], int i, int j, int n)
{
    if (i > j)
        return 0;
    if (dp[i][j] != -1)
        return dp[i][j];
    int ans = INT_MIN;

    for (int k = i; k <= j; k++)
    {
        int left = (i == 0) ? 1 : ar[i - 1];
        int right = (j == n - 1) ? 1 : ar[j + 1];
        int temp = solve(ar, i, k - 1, n) + solve(ar, k + 1, j, n) + left * right * ar[k];
        ans = max(ans, temp);
    }
    return dp[i][j] = ans;
}

signed main()
{
    int n;
    cin >> n;
    int ar[n];
    for (int i = 0; i < n; i++)
        cin >> ar[i];
    memset(dp, -1, sizeof dp);
    cout << solve(ar, 0, n - 1, n) << "\n";
    return 0;
}