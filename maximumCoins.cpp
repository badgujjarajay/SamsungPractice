// Given an NxM (N rows and M columns) integer matrix with non-negative values. What is the maximum sum from going top left (0, 0) to bottom right (N-1, M-1)? The condition is that when you're at the point (p, q), you can only move to either right (p, q+1) or down (p+1, q).

// Input Format
// First line contains two space sepreated integers denoting N and M.
// Next N lines contains M space seprated integers each forming matrix

// Constraints
// 1<= N,M <= 10
// 0<= Value of each matrix element <=100
// Time Limit 1 sec..
// Memory Limit 256 MB

// Output Format
// Output a single integers denoting maximum number of coins under given conditions

// Sample Input 0
// 2 6
// 59 20 36 8 1 82 
// 69 67 16 7 48 83 
// Sample Output 0
// 349

#include <bits/stdc++.h>
using namespace std;


int main() {
    int N, M;
    cin>>N>>M;
    int mat[N+1][M+1];
    memset(mat, 0, sizeof mat);
    for(int i=1; i<=N; i++) {
        for(int j=1; j<=M; j++) {
            cin>>mat[i][j];
            mat[i][j] += max(mat[i-1][j], mat[i][j-1]);
        }
    }
    cout<<mat[N][M];
    return 0;
}