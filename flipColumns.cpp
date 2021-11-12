// https://www.hackerrank.com/contests/target-samsung-13-nov19/challenges/flip-columns

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int m, n;
int a[15][15];
int ans = 0;

void dfs(int col, int k) {
    if(col == m) return;
    if(k < 0) return;
    if(k == 0) {
        int v = 0;
        for(int i=0; i<n; i++) {
            bool flag = true;
            for(int j=0; j<m; j++) {
                if(a[i][j] == 0) {
                    flag = false;
                    break;
                }
            }
            if(flag) v++;
        }
        ans = max(ans, v);
    } 
    dfs(col+1, k);
    for(int i=0; i<n; i++) a[i][col] = !a[i][col];
    dfs(col, k-1);
    for(int i=0; i<n; i++) a[i][col] = !a[i][col];
}

int main() {
    int k;
    cin >> n >> m >> k;
    for(int i=0; i<n; i++) for(int j=0; j<m; j++) cin>>a[i][j];
    dfs(0, k);
    cout<<ans;
    return 0;
}
