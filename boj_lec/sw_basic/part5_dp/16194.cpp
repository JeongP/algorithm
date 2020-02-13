#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;

const int MAX = 10001;

int main () {
    
    // initialize
    int p[1001] = {0,};
    int dp[1001];

    memset(dp,10001,sizeof(dp));
    

    // input
    int n;
    cin >> n;

    for(int i=1;i<=n;i++) {
        cin >> p[i];
    }


    // solution
    dp[0] = 0;
    dp[1] = p[1];

    for(int i=2;i<=n;i++) {
        for(int j=1;j<=i;j++) {
            dp[i] = min(dp[i], dp[i-j] + p[j]);
        }
    }

    // prt
    cout << dp[n] << endl;

}