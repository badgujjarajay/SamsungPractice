// There is a mobile piece and a stationary piece on the N×M chessboard. The available moves of the mobile piece are the moves of knight in chess. You need to capture the stationary piece by moving the mobile piece with the minimum amount of moves.

// Input Format
// First line contains an integer t denotng number of test cases
// For eachtest case we have two lines
// Contains two space seprated integers n and m denoting length and breadth of board(n*m)
// Contains four space seprated integers r1,c1,r2 and c2 where, r1 -->x coordinate of mobile piece c1 -->y coordinate of mobile piece r2 -->x coordinate of stationary piece c2 -->y coordinate of stationary piece

// Constraints
// 1<=t<=100 1<=n,m<=100 it is guarnteed that knight(mobile piece) and stationary piece lies within chessboard There is no obstacle in movement of knight provided the move is valid Constraint for valid move... knight can move to 8 locations max from a location provided location where knight is intended move lies within the board from position (x,y) knight can move
// dx = [2, 2, -2, -2, 1, 1, -1, -1]
// dy = [1, -1, 1, -1, 2, -2, 2, -2]
// new_x =x+dx[i] 0<=i<8 new_y =y+dy[i]
// time limit 1 sec...
// memory limit 256 MB
// Assume 1 based indexing for board..

// Output Format
// For each test case print two lines Test_case #"test_case no without quotes(see sample for details)" minimum no of moves to reach at stationary piece if destination can't be reached print "None" without quotes ex. Test_case #0 24 Test_case #1 45

// Sample Input 0
// 2
// 25 93
// 6 4 16 54
// 2 29
// 2 18 1 14
// Sample Output 0
// Test_case #0
// 26
// Test_case #1
// None

#include <bits/stdc++.h>
using namespace std;


int main() {
    int T;
    cin>>T;
    for(int t=1; t<=T; t++) {
        int N, M;
        cin >> N >> M;
        int r1, c1, r2, c2;
        cin >> r1 >> c1 >> r2 >> c2;
        int x[] = {2, 2, -2, -2, 1, 1, -1, -1};
        int y[] = {1, -1, 1, -1, 2, -2, 2, -2};
        bool visited[N+1][M+1];
        memset(visited, false, sizeof visited);
        int q[10005][3];
        int l=0, r=0, ans=-1;
        q[0][0] = r1, q[0][1] = c1, q[0][2] = 0;
        visited[r1][c1] = true;
        while(l <= r) {
            int i = q[l][0], j = q[l][1], d = q[l][2];
            l++;
            if(i == r2 && j == c2) {
                ans = d;
                break;
            }
            for(int k=0; k<8; k++) {
                int ni = i + x[k];
                int nj = j + y[k];
                if(ni <= 0 || nj <= 0 || ni > N || nj > M || visited[ni][nj]) continue;
                r++;
                q[r][0] = ni, q[r][1] = nj, q[r][2] = d+1;
                visited[ni][nj] = true;
            }
        }
        cout<<"Test_case #"<<t-1<<"\n";
        if(ans == -1) cout<<"None\n";
        else cout<<ans<<"\n";
    }
    return 0;
}