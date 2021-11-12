// https://www.hackerrank.com/contests/target-samsung-13-nov19/challenges/rock-climbing

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <bits/stdc++.h>
using namespace std;

int n, m, a[10][10];
int ans = INT_MAX;
bool visited[10][10];

bool check(int i, int j) {
    return i >=0 and i < n and j >= 0 and j < m;
}

void dfs(int i, int j, int cur, int cur_ans) {
    visited[i][j] = true;
    if(a[i][j] == 1) {
        cur_ans = max(cur_ans, cur);
        if(check(i+1, j) and !visited[i+1][j]) dfs(i+1, j, 1, cur_ans);
        if(check(i-1, j) and !visited[i-1][j]) dfs(i-1, j, 1, cur_ans);
        if(check(i, j+1) and !visited[i][j+1] and a[i][j+1] != 0) dfs(i, j+1, 0, cur_ans);
        if(check(i, j-1) and !visited[i][j-1] and a[i][j-1] != 0) dfs(i, j-1, 0, cur_ans);
    } else if(a[i][j] == 0) {
        if(check(i+1, j) and !visited[i+1][j]) dfs(i+1, j, cur+1, cur_ans);
        if(check(i-1, j) and !visited[i-1][j]) dfs(i-1, j, cur+1, cur_ans);
    } else {
        cur_ans = max(cur_ans, cur);
        ans = min(ans, cur_ans);
    }
    visited[i][j] = false;
}

int main() {
    cin >> n >> m;
    for(int i=0; i<n; i++) {
        for(int j=0; j<m; j++) cin >> a[i][j];
    }
    memset(visited, false, sizeof visited);
    dfs(n-1, 0, 0, 0);
    cout<<ans;
    return 0;
}
