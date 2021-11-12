// https://www.hackerrank.com/contests/target-samsung-13-nov19/challenges/fisherman

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int n, pos[3], man[3];
int ans;

void dfs(int i, int p, int cost) {
    if(p == 3) {
        if(i <= n) ans = min(ans, cost);
        return;
    }
    if(i > n) return;
    dfs(i+1, p, cost);
    for(int k=0; k<man[p]; k++) {
        cost += abs(i+k-pos[p])+1;
    }
    dfs(i+man[p], p+1, cost);
}

int main() {
    cin >> n;
    cin >> pos[0] >> pos[1] >> pos[2];
    cin >> man[0] >> man[1] >> man[2];
    pos[0]--, pos[1]--,pos[2]--;
    ans = 1000000000;
    dfs(0,0,0);
    cout<<ans;
    return 0;
}
