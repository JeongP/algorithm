#include <iostream>

using namespace std;

bool isDecimal(int n, int m) {
    int cnt1 = 0;
    for(int i=2;i<=n;i++) {
        if(n%i == 0) cnt1++;
    }
    int cnt2 = 0;
    for(int i=2;i<=m;i++) {
        if(m%i == 0) cnt2++;
    }

    if(cnt1 == 1 && cnt2 == 1) return true;
    else return false;
}

int main () {
    int n;
    
    while(cin >> n) {
        if(n==0) return 0;
        int i = n-1;
        for(i;i>=n/2;i-=2) {
            // check the decimal from back of number
            int m = n-i;
            if(isDecimal(i,m)) {
                cout << n << " = " << m << " + " << i << endl;
                // printf("%d = %d + %d\n",n,m,i);
                break;
            }
        }
        // wrong case
        if(i < n/2) {
            cout << "Goldbach's conjecture is wrong." << endl;
        }
    }
    
}

