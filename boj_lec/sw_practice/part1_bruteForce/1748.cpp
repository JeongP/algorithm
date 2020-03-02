/*

    1. 자리수를 구해주는 함수를 통해 1부터 N까지 더한다.
    
 */

#include <iostream>

using namespace std;

int length(int num) {
    int cnt = 0;
    while(num) {
        num/=10;
        cnt++;
    }
    return cnt;
}

int main () {
    int N;
    cin >> N;

    int result = 0;

    for(int i=1;i<=N;i++) {
        result += length(i);
    }

    cout << result << endl;
}