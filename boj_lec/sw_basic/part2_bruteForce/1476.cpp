// 날짜 계산
#include <iostream>
using namespace std;

int main () {
    // 입력받는 세 수
    int e, s, m;
    cin >> e >> s >> m;

    // 비교할 수
    int x = 0;
    int y = 0;
    int z = 0;

    // 결과를 담을 곳
    int result;

    for(int i=1;i<=7980;i++) {
        x++; y++; z++;
        // 조건 체크
        if(x>15) x=1;
        if(y>28) y=1;
        if(z>19) z=1;

        // 입력받은 수와 비교
        if(e==x && s == y && m == z) {
            result = i;
            break;
        }
    }

    cout << result << endl;
}