//                    0 1 0 2 0 --> Non highlighted part                       
//                    0 2 2 2 1                      
//                    0 2 1 1 1                       
//                    1 0 1 0 0                       
//                    0 0 1 2 2                      
//                    1 1 0 0 1                      
//                    x x S x x  -->highlighted yellow
// In the grid above,
// 1: This cell has a coin.
// 2: This cell has an enemy.
// 0: It contains nothing.
// The highlighted zone is the control zone. S is a spaceship that we need to control so that we can get maximum coins. Now, S’s initial position will be at the center and we can only move it right or left by one cell or do not move. At each time, the non-highlighted part of the grid will move down by one unit.
// We can also use a bomb but only once. If we use that, all the enemies in the 5×5 region above the control zone will be killed.
// If we use a bomb at the very beginning, the grid will look like this:
//                         0 1 0 2 0  --> Non highlighted part                         
//                         0 0 0 0 1                           
//                         0 0 1 1 1                           
//                         1 0 1 0 0                           
//                         0 0 1 0 0                           
//                         1 1 0 0 1                            
//                         x x S x x  --> highlighted yellow
// As soon as, the spaceship encounters an enemy or the entire grid has come down, the game ends.
// For example,
// At the very first instance, if we want to collect a coin we should move left ( coins=1).
// This is because when the grid comes down by 1 unit we have a coin on the second position and by moving left we can collect that coin. Next, we should move right to collect another coin ( coins=2) .
// After this, remain at the same position ( coins=4). This is the current situation after collecting 4 coins.
// 0 1 0 2 0 0 1 0 0 0 0 2 2 2 1 -->after using 0 0 0 0 1 x x S x x -->bomb x x S x x
// Now, we can use the bomb to get out of this situation. After this, we can collect at most 1 coin. So maximum coins=5.

// Input Format
// First line contains an integer n denoting number of rows(No of columns is always fixed to 5)
// Next n lines contain 5 space seprated integers(either 0,1,2) and last line i.e x x S x x is self understood so it is not given in input

// Constraints
// 1<=n<=10
// values in matrix will be from the set {0,1,2}
// timelimit 1 sec
// Memory limit 256 MB

// Output Format
// print the maximum coins that can be obtained till the game ends

// Sample Input 0
// 6
// 0 1 0 2 0 
// 0 2 2 2 1
// 0 2 1 1 1
// 1 0 1 0 0
// 0 0 1 2 2
// 1 1 0 0 1
// Sample Output 0
// 5

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int ar[11][5];

int dfs(int x, int y, bool isBomb = 1, int lasts = 10) {
    if(x == 0) return 0;
    
    int ans = 0;
    for(int i = -1; i < 2; i++) {
        if(y+i < 0 or y+i > 4) continue;
        int temp = 0;
        if(ar[x-1][y+i] == 0) temp = dfs(x-1, y+i, isBomb, lasts);
        else if(ar[x-1][y+i] == 1) temp = 1 + dfs(x-1, y+i, isBomb, lasts);
        else if(isBomb) temp = dfs(x-1, y+i, false, x-1-5);
        else if(x-1 > lasts) temp = dfs(x-1, y+i, false, lasts);
        ans = max(ans, temp);
    }
    return ans;
}

int main() {
    int N;
    cin >> N;
    for(int i=0; i<N; i++) {
        for(int j=0; j<5; j++) cin>>ar[i][j];
    }
    int ans = dfs(N, 2);
    cout<<ans<<"\n";
    return 0;
}