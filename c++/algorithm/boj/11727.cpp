#include <iostream>

using namespace std;

int d[1001];

int dp(int x) {
    if(x==1) return d[1] = 1;
    if(x==2) return d[2] = 2;
    if(d[x]) return d[x];
    return d[x] = (dp(x-1) + 2*dp(x-2))%10007;
}


int main () {

    int n;
    cin >> n;
    cout << dp(n) << endl;

}