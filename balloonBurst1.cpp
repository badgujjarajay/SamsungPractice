// Here are n balloons and n bullets and each balloon is assigned with a particular number (point). Whenever a particular balloon is shot the no of points increases by
// 1.the multiplication of point assigned to balloon on left and that of right side.
// 2.point assigned to left if no right exists
// 3.point assigned to right if no left exists.
// 4.the point assigned to itself if no other balloon exists.
// You have to output the maximum no of points possible.

// Input Format
// 1.First line contains an integer n denoting number of balloons/bullets
// 2.Next line contains n space seprated integers denoting points written on balloons

// Constraints
// 1<=n<=10
// 1<= points on balloons<=100000
// timelimit 1 Sec
// memory limit 256 MB

// Output Format
// Output Single integer denoting the maximum number of points can be achieved following the above conditins

// Sample Input 0
// 4
// 1  2  3  4
// Sample Output 0
// 20
// Explanation 0
// Following the sequence 3->2->1->4 we will get 20.
// initially points ->0
// burst 3, points = 0+2*4=8(condition 1)
// now burst 2, points = 8+1*4=12(condition 1)
// now burst 1, points =12+4=16( Condition 3)
// now burst 4, points added 16+4=20(alone left condition 4)

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
        int val = (i == 0 and j == n - 1) ? ar[k] : 1;
        int temp = solve(ar, i, k - 1, n) + solve(ar, k + 1, j, n) + left * right * val;
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
    for (int i = 0; i < 11; i++)
    {
        for (int j = 0; j < 11; j++)
            dp[i][j] = -1;
    }
    cout << solve(ar, 0, n - 1, n);
    return 0;
}