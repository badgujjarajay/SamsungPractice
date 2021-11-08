// Mr Kim has to deliver refrigerators to N customers. From the office, he is going to visit all the customers and then return to his home. Each location of the office, his home, and the customers is given in the form of integer coordinates (x,y) (0≤x≤100, 0≤y≤100). The distance between two arbitrary locations (x1, y1) and (x2, y2) is computed by |x1-x2| + |y1-y2|, where |x| denotes the absolute value of x; for instance, |3|=|-3|=3. The locations of the office, his home, and the customers are all distinct. You should plan an optimal way to visit all the N customers and return to his among all the possibilities. You are given the locations of the office, Mr Kim’s home, and the customers; the number of the customers is in the range of 5 to 10. Write a program that, starting at the office, finds a (the) shortest path visiting all the customers and returning to his home. Your program only has to report the distance of a (the) shortest path.

// Input Format
// By default there 10 test cases. So no need to take test cases as input Each test case consists of two lines 1. The first line has N, the number of the customers, 2. and the N+2 line enumerates the locations of the office, Mr Kim’s home, and the customers in sequence. Each location consists of the coordinates (x,y), which is represented by ‘x y’.

// Constraints
// 5≤N≤10.
// Each location (x,y) is in a bounded grid,
// 0≤x≤100, 0≤y≤100,
// and x, y are integers.
// timelimit 1 sec...
// Memory Limit 256 MB

// Output Format
// Output the 10 answers in 10 lines. Each line outputs the distance of a (the) shortest path. .

// Sample Input 0
// 5
// 28 64
// 4 82
// 76 17
// 27 53
// 15 48
// 27 33
// 41 83
// 9
// 50 14
// 36 6
// 35 86
// 47 1
// 45 36
// 90 60
// 14 50
// 65 31
// 81 15
// 24 7
// 92 34
// 7
// 65 49
// 100 6
// 29 90
// 46 15
// 74 74
// 52 73
// 28 96
// 27 82
// 53 12
// 8
// 12 68
// 61 76
// 93 58
// 63 54
// 87 38
// 33 91
// 8 85
// 77 59
// 87 8
// 42 48
// 9
// 22 3
// 27 2
// 68 93
// 45 91
// 96 87
// 60 22
// 7 68
// 13 60
// 29 22
// 40 82
// 22 33
// 7
// 72 82
// 17 84
// 88 19
// 66 22
// 92 57
// 99 78
// 14 61
// 48 0
// 26 1
// 9
// 58 99
// 61 93
// 9 20
// 63 80
// 68 64
// 77 19
// 52 87
// 90 41
// 33 60
// 31 76
// 80 37
// 5
// 97 50
// 9 86
// 42 32
// 37 95
// 65 90
// 78 51
// 47 11
// 9
// 1 21
// 21 11
// 99 52
// 58 48
// 82 95
// 68 79
// 37 49
// 59 84
// 100 50
// 23 72
// 30 96
// 7
// 70 55
// 53 97
// 84 76
// 44 12
// 53 95
// 18 49
// 84 51
// 34 77
// 98 46
// Sample Output 0
// 260
// 372
// 268
// 305
// 354
// 287
// 317
// 268
// 372
// 313

#include <bits/stdc++.h>
using namespace std;

int dp[1<<12][12];
int N, done;

int solve(int mask, int p, int X[], int Y[]) {
    if(mask == done) return abs(X[N+1]-X[p]) + abs(Y[N+1]-Y[p]);
    if(dp[mask][p] != -1) return dp[mask][p];
    int ans = INT_MAX;
    for(int i=0; i<N+1; i++) {
        if(mask&(1<<i)) continue;
        ans = min(ans, solve(mask|(1<<i), i, X, Y) + abs(X[i]-X[p]) + abs(Y[i]-Y[p]));
    }
    return dp[mask][p] = ans;
}

int main() {
    int t = 10;
    while(t--) {
        cin>>N;
        int X[N+2], Y[N+2];
        cin>>X[0]>>Y[0];
        cin>>X[N+1]>>Y[N+1];
        for(int i=1; i<=N; i++) cin>>X[i]>>Y[i];
        memset(dp, -1, sizeof dp);
        done = (1<<(N+1)) - 1;
        int ans = solve(1, 0, X, Y);
        cout<<ans<<"\n";
    }
    return 0;
}