/*
    dp[n][i] = 끝 자리가 i로 끝나면서 길이가 n인 오르막 수의 개수.
    dp[n][i] = dp[n-1][0] + .. + dp[n-1][i]로 표현 가능.
    구하고자 하는 답은 dp[n][0] + .. + dp[n][9]
 */

#include <iostream>
using namespace std;

const int MAX = 1001;
const int mod = 10007;

int main () {
    
    int dp[MAX][10] = {0,};
    
    for(int i=0;i<=9;i++) {
        dp[1][i] = 1;
    }
    
    int n;
    cin >> n;

    for(int i=2;i<=n;i++) {
        for(int j=0;j<=9;j++) {
            for(int k=0;k<=j;k++) {
                dp[i][j] = (dp[i][j] + dp[i-1][k]) % mod;
            }
        }
    }

    int answer = 0;
    for(int i=0;i<=9;i++) {
        answer = (answer + dp[n][i])%mod;
    }

    cout << answer << endl;
}