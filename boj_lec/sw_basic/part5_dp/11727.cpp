#include <iostream>
#include <vector>

using namespace std;

int main () {
    int d[1001] = {0,};
    int n;
    cin >> n;

    d[1] = 1; d[2] = d[1]+2;

    for(int i=3;i<=n;i++) {
        d[i] = (d[i-1] + d[i-2]*2)%10007;
    }

    cout << d[n] << endl;
}