
/*
    dp[n][0] = n개의 포도잔 중, 마지막 잔은 먹지 않고 최대로 먹을 수 있는 포도주 양
    dp[n][1] = n개의 포도잔 중, 마지막 잔을 먹고 최대로 먹을 수 있는 포도주 양
    우리가 원하는 답 = max(dp[n][1], dp[n][0])
    dp[n][0] = max(dp[n-2][1], dp[n-1][1])
    dp[n][1] = max(dp[n-2][0]+p[n-1], dp[n-2][1]) + p[n]

 */

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

#define MAX 10001

int dp[MAX][2];

int main () {

    int n;
    vector<int> p;
    p.push_back(0);
    cin >> n;

    // input();
    for(int i=1;i<=n;i++) {
        int x; 
        cin >> x;
        p.push_back(x);
    }

    // initialize
    dp[1][0] = 0; dp[1][1] = p[1];
    dp[2][0] = dp[1][1]; dp[2][1] = p[1]+p[2];


    // dp solution();
    for(int i=3;i<=n;i++) {
        dp[i][0] = max(dp[i-2][1], dp[i-1][1]);
        dp[i][1] = max(dp[i-2][0]+p[i-1], dp[i-2][1]) + p[i];
    }

    // prt answer
    int answer = max(dp[n][1], dp[n][0]);
    cout << answer << endl;

    return 0;
}