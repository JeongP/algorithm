#include <iostream>
using namespace std;

int main () {
    int t;
    int a, b;
    int max,min;
    int ans;

    cin >> t;

    while(t--) {
        cin >> a >> b;
        cout << a << b << endl;
        // compare A and B
        if(a>=b) {
            max = a;
            min = b;
        }else {
            max = b;
            min = a;
        }

        for(int j=max;;j++) {
            if((j%min==0) && (j%max==0)) {
                ans = j;
                break;
            }
        }

        cout << ans;
    }
}