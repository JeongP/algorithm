#include <iostream>
#include <algorithm>
using namespace std;

int p[1001] = {0,};
int dp[1001] = {0,};
int n;

void input() {
    cin >> n;
    for(int i=1;i<=n;i++) {
        cin >> p[i];
    }
    
}

void solution() {
    dp[1] = p[1];
    for(int i=2;i<=n;i++) {
        for(int j=1;j<=i;j++) {
            dp[i] = max(dp[i], dp[i-j] + p[j]);
        }
    }
}

int main () {
    
    input();
    solution();
    cout << dp[n] << endl;
}