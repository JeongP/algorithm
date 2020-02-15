/*

    1. dp[n][i] = i로 끝나는 길이가 n짜리 이친수 갯수.
    2. 구하고자 하는 답 dp[n][0] + dp[n][1]
    3. dp[n][0] = dp[n-1][0] + dp[n-1][1]
       dp[n][1] = dp[n-1][0]

 */

#include <iostream>

using namespace std;

const int MAX = 90+1;

int main () {

    long long dp[MAX][2] = {0,};

    // initialize
    dp[1][1] = 1;    
    
    int n;
    cin >> n;

    for(int i=2;i<=n;i++) {
        dp[i][0] = dp[i-1][0] + dp[i-1][1];
        dp[i][1] = dp[i-1][0];
    }

    long long answer = dp[n][0] + dp[n][1];

    cout << answer << endl;
    
}