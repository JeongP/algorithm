/*
    1. dp[n][i] = i로 끝나고 1,2,3으로 n을 만들 수 있는 방법의 수.
    2. answer = (dp[n][1] + dp[n][2] + dp[n][3]) % mod
    3. dp[n][1] = dp[n-1][2] + dp[n-1][3]
       dp[n][2] = dp[n-2][1] + dp[n-2][3]
       dp[n][3] = dp[n-3][1] + dp[n-3][2]
 */

#include <iostream>

using namespace std;

const int mod = 1e9 + 9;
const int MAX = 100001;

int main () {

    long long dp[MAX][4] = {0,};

    int t,n;
    cin >> t;

    dp[1][1] = dp[2][2] = dp[3][1] = dp[3][2] = dp[3][3] = 1;
    for(int i=4;i<=100000;i++) {
        dp[i][1] = (dp[i-1][2] + dp[i-1][3]) % mod;
        dp[i][2] = (dp[i-2][1] + dp[i-2][3]) % mod;
        dp[i][3] = (dp[i-3][1] + dp[i-3][2]) % mod;
    }

    while(t--) {
        cin >> n;
        int answer = (dp[n][1] + dp[n][2] + dp[n][3]) % mod;
        cout << answer << endl;
    }

}