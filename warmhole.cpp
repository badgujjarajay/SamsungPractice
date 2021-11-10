// There is a source (S) and destination (D) and a spacecraft has to go from S to D. There are N number of wormholes in between which has following properties: 1. Each wormhole has an entry and an exit. 2. Each wormhole is bi-directional i.e. one can enter and exit from any of the ends. 3. The time to cross the wormhole will be given The space craft may or may not use the wormhole to reach D. The time taken to travel outside wormhole between two points (x1, y1) and (x2, y2) is given by a formula |x1 - x2| + |y1 - y2|
// where, (x1, y1) and (x2, y2) are the co-ordinates of two points. The co-ordinates of S and D are given and we have to find the minimum time to reach D from S.
// Note: It’s not mandatory to consider all the wormholes.

// Input Format
// First line contains 4 integer i.e sx, sy,dx,dy where, sx --> x coordinate of Source sy --> y coordinate of Source dx --> x coordinate of destination dy --> y coordinate of destination
// Second line contains an integer n which represents no of wormholes
// next n lines contains 5 integers i.e xs,xy,xd,yd,c where, xs --> x coordinate of first end of wormhole ys --> y coordinate of first end of wormhole xd --> x coordinate of second end of wormhole yd --> y coordinate of second end of wormhole c --> time taken to cross the wormhole from either of two directons available

// Constraints
// 0<=n<=10 (no of wormholes is less than 10)
// Every x and y coordinate given lies between (0,1000) and is integer for sure..
// Timelimit 1sec.
// Memorylimit 256 MB

// Output Format
// Output a single number representing the minimum cost

// Sample Input 0
// 87 862 743 418
// 10
// 525 967 531 262 886
// 565 403 208 829 82
// 997 59 63 518 434
// 507 703 929 858 729
// 383 676 139 538 212
// 191 962 801 381 737
// 357 651 388 885 369
// 961 880 57 329 1000
// 966 400 119 80 423
// 596 899 518 49 610
// Sample Output 0
// 429

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <bits/stdc++.h>
using namespace std;
#define int long long
int ar[11][5];
bool visited[11];
int ans, N;

int calculate_cost(int sx, int sy, int dx, int dy) {
    return abs(sx - dx) + abs(sy - dy);
}

void solve(int sx, int sy, int dx, int dy, int cost) {
    int temp_ans =  cost + calculate_cost(sx, sy, dx, dy);
    ans = min(ans, temp_ans);
    if(cost > ans) return;
    for(int i=0; i<N; i++) {
        if(visited[i]) continue;
        visited[i] = true;
        solve(ar[i][0], ar[i][1], dx, dy, cost + calculate_cost(sx, sy, ar[i][2], ar[i][3]) + ar[i][4]);
        solve(ar[i][2], ar[i][3], dx, dy, cost + calculate_cost(sx, sy, ar[i][0], ar[i][1]) + ar[i][4]);
        visited[i] = false;
    }
}

int32_t main() {
    int sx, sy, dx, dy;
    cin >> sx >> sy >> dx >> dy;
    cin >> N;
    for(int i=0; i<N; i++) {
        for(int j=0; j<5; j++) cin >> ar[i][j];
    }
    ans = 1000000000000;
    for(int i=0; i<N; i++) visited[i] = false;
    solve(sx, sy, dx, dy, 0);
    cout<<ans<<"\n";
    return 0;
}