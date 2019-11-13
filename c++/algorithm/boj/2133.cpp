// 타일 채우기

#include <iostream>
using namespace std;

int d[31];

int dp(int n) {
    if(n==1) return;
    if(n==2) return 3;
    if(n==3) return 0;
    if(d[n] != 0) return d[n];
    for (int i=0;i<=n;i++) {

    }
}


int main () {
    int n;
    cin >> n;

    cout << dp(n) << endl;
}