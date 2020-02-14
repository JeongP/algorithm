#include <iostream>

using namespace std;

const int mod = 1e9;
int main () {
    long long dp[101][10] = {0,};

    int n;
    cin >> n;

    for(int i=1;i<=9;i++) {
        dp[1][i] = 1;
    }

    for(int i=2;i<=n;i++) {
        for(int j=0;j<10;j++) {
            if(j==0) {
                dp[i][0] = (dp[i-1][1]) % mod; 
            }else if(j==9) {
                dp[i][9] = (dp[i-1][8]) % mod;
            }else {
                dp[i][j] = (dp[i-1][j-1] + dp[i-1][j+1]) % mod;
            }
        }
    }

    long long answer = 0;
    for(int i=0;i<=9;i++) {
        answer = ( answer + dp[n][i]) % mod;
    }

    cout << answer << endl;
}