#include <iostream>

using namespace std;

long long d[1000001] = {0,};

void memoization() {
    d[1] = 1;
    d[2] = 2;
    d[3] = 4;

    for(int i=4;i<=1000000;i++) {
        d[i] = (d[i-1] + d[i-2] + d[i-3])%1000000009;
    }
}

int main () {
    int t;
    cin >> t;

    int n;
    
    memoization();
    while(t--) {
        cin >> n;
        cout << d[n] << endl;
    }
}
