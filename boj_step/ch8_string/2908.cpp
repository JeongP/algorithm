#include <iostream>
#include <string>
#include <cmath>
using namespace std;

int n,m;

int reverseNum(int n) {
    int digit = 2;
    int num = 0;
    while(n!=0) {
        int x = n%10;
        num += x * pow(10,digit--);
        n = n/10;
    }
    return num;
}

int main () {
    cin >> n >> m;

    // 수 뒤집기
    int a = reverseNum(n);
    int b = reverseNum(m);

    if(a>b) cout << a << endl;
    else cout << b << endl;

    return 0;
}