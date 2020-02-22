#include <iostream>
#include <algorithm>
#include <cstring>
#define MAX 100001

using namespace std;

int main () {
    int n;
    int arr[MAX]={0,};
    int dp[MAX][2];

    memset(dp,0,sizeof(dp));

    cin >> n;
    for(int i=1;i<=n;i++) {
        cin >> arr[i];
    }

    dp[1][0] = arr[1];
    dp[1][1] = 0;

    for(int i=2;i<=n;i++) {
            dp[i][0] = max(arr[i], dp[i-1][0] + arr[i]);
            dp[i][1] = max(dp[i-1][0], dp[i-1][1] + arr[i]);
    }

    int ans = 0;
    for(int i=1;i<=n;i++) {
        for(int j=0;j<=1;j++) {
            ans = max(ans,dp[i][j]);
        }
    }

    cout << ans << endl;
}