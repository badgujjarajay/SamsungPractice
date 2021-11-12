// https://www.hackerrank.com/contests/target-samsung-13-nov19/challenges/sum-of-nodes-in-kth-level

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    int k; cin >> k;
    string s; cin >> s;
    int i = 0, n = s.length(), cnt = 0, ans = 0;
    while(i < n) {
        if(s[i] =='(') cnt++, i++;
        else if(s[i] ==')') cnt--, i++;
        else {
            string temp;
            while(s[i] != '(' and s[i] != ')') temp += s[i++];
            if(cnt == k+1) ans += stoi(temp);
        }
    }
    cout<< ans;
    return 0;
}
