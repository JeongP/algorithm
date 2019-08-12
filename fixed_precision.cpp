#include <iostream>
#include <iomanip>
using namespace std;



int main () {
    double a = 113.1412923;
    // cin >> a;
    cout << fixed; // 소수점 아래로 고정하겠다.
    cout.precision(6); // 두 번째 자리까지.
    cout << a << endl;

    // setpricision의 사용.
    // 출력 범위 지정. fixed가 있으면 정수부 + 소수부, 없으면 소수부만 출력 범위 지정 가능
    cout << fixed << setprecision(6) << a << endl;
    

}