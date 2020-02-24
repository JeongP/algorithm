/*

    1. d[n][k] = 숫자 k개를 사용하여 n을 만들 수 있는 개수를 담은 배열.
    2. d[0][1] ~ d[n][1] = 1
    3. d[0][0] ~ d[n][0] = 0
    4. d[2][2] = (0,2) (1,1) (2,0) 인데 따지고 보면 1개로 0~2만들 수 있는 것들의 합.
    5. 즉 d[n][k] = d[0][k-1] + ... d[n][k+1];

 */

#include <iostream>
using namespace std;

typedef long long ll;

int N,K;
const ll mod = 1000000000;
const int MAX = 201;
ll dp[MAX][MAX];

int main () {

    cin >> N >> K;
    for(int i=0;i<=N;i++) {
        dp[i][1] = 1;
    }

    for(int n=2;n<=N;n++) {
        for(int k=2;k<=K;k++) {
            for(int j=0;j<=n;j++) {
                dp[n][k] += (dp[j][k-1])%mod;
            }
        }
    }

    cout << dp[N][K] << endl;
    return 0;
}