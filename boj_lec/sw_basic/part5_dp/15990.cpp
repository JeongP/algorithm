#include <iostream>
#include <vector>
using namespace std;

const int mod = 1e9+9;

struct ans {
    long long cnt;
    long long end1, end2, end3;

    ans(long long a, long long b, long long c, long long d) {
        cnt = a;
        end1 = b;
        end2 = c;
        end3 = d;
    }
};

int main () {
    int t,n;
    cin >> t;

    vector<ans> dp;
    dp.push_back(ans(0,0,0,0));
    dp.push_back(ans(1,1,0,0));
    dp.push_back(ans(1,0,1,0));
    dp.push_back(ans(3,1,1,1));

    for(int i=4;i<=100000;i++) {
        long long next_end1 = (dp[i-1].cnt - dp[i-1].end1) % mod;
        long long next_end2 = (dp[i-2].cnt - dp[i-2].end2) % mod;
        long long next_end3 = (dp[i-3].cnt - dp[i-3].end3) % mod;
        
        long long next_cnt = (next_end1 + next_end2 + next_end3)%mod;

        dp.push_back(ans(next_cnt, next_end1, next_end2, next_end3));
    }

    while(t--) {
        cin >> n;
        cout << dp[n].cnt << endl;
    }

}