/*
    
    dp[n][i] = i행 n열의 값을 포함한 스티커 점수의 최댓값
    answer = max(dp[n][1], dp[n][2]);
    dp[n][i] = max(dp[n-1][3-i], dp[n-2][3-i])

 */

#include <iostream>
#include <algorithm>

using namespace std;

#define MAX 100001

int dp[MAX][3];
int st[3][MAX];
int n;


int main () {
    int tc;
    cin >> tc;

    int n;
    while(tc--) {
        cin >> n;
        // fill up sticker
        for(int i=1;i<=2;i++) {
            for(int j=1;j<=n;j++) {
                cin >> st[i][j];
            }
        }

        // initialize
        dp[1][1] = st[1][1]; dp[1][2] = st[2][1];
        dp[2][1] = st[2][1] + st[1][2]; dp[2][2] = st[1][1] + st[2][2];
        
        // dp solution
        for(int i=3;i<=n;i++) {
            dp[i][1] = max(dp[i-1][2], dp[i-2][2]) + st[1][i];
            dp[i][2] = max(dp[i-1][1], dp[i-2][1]) + st[2][i];
        }
        
        // prt answer
        int answer = max(dp[n][1], dp[n][2]);
        cout << answer << endl;
    }
    return 0;
}