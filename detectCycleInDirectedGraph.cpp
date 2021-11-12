// https://www.hackerrank.com/contests/target-samsung-13-nov19/challenges/detect-cycle-in-directed-graph

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int n, m;
int adj[11][51], visited[11] = {};
int ans[11] = {}, cur_path[11] = {}, sum = 100;
void dfs(int u) {
    visited[u] = 1;
    cur_path[0]++;
    cur_path[cur_path[0]] = u;
    for(int i=adj[u][0]; i > 0; i--) {
        if(!visited[adj[u][i]]) {
            dfs(adj[u][i]);
        }
        if(visited[adj[u][i]] == 1) {
            // cycle detected
            int temp_sum = 0;
            int pos = cur_path[0];
            while(pos > 0) {
                temp_sum += cur_path[pos];
                if(cur_path[pos] == adj[u][i]) break;
                pos--;
            }
            if(temp_sum < sum) {
                sum = temp_sum;
                ans[0] = 0;
                for( ;pos <= cur_path[0]; pos++) {
                    ans[0]++;
                    ans[ans[0]] = cur_path[pos];
                }
            }
        }
    }
    cur_path[0]--;
    visited[u] = 2;
}

int main() {
    cin >> n >> m;
    for(int i=0; i<=n; i++) adj[i][0] = 0, visited[i] = 0;
    for(int i=0; i<m; i++) {
        int u, v;
        cin >> u >> v;
        adj[u][0]++;
        adj[u][adj[u][0]] = v;
    }
    for(int i=1; i<=n; i++) {
        if(!visited[i]) cur_path[0] = 0, dfs(i);
    }
    sort(ans+1, ans+ans[0]+1);
    for(int i=1; i<=ans[0]; i++) cout<<ans[i]<<" ";
    return 0;
}
