#include <iostream>
using namespace std;

int main () {
    int n;
    // 각 자리수 변수
    int fn, sn, tn;
    // 차이 변수
    int c1, c2;
    // 카운트
    int cnt;
    
    cin >> n;

    // 두자리 수 일때
    if(n < 100) {
        cnt = n;
    } else {
        cnt = 99;
        // 세자리 수 일때
        for (int i=100; i<=n; i++) {
            fn = i / 100;
            sn = ( i / 10 ) % 10;
            tn = i % 10;

            c1 = fn - sn;
            c2 = sn - tn;

            if(c1 == c2) {
                cnt++;
            }
        }
    }


    cout << cnt;
   
    
}