#include <iostream>

using namespace std;

int num = 100;
int a[101];

void primeNumber() {
    
    for (int i = 1; i <= num ; i++ ) {
        a[i] = i;
    }

    for( int i=2; i<=num; i++) {
        if(a[i] == 0) continue;
        for(int j=i+i; j<=num; j=j+i) {
            a[j] = 0;
        }
    }

    for(int i=2;i<=num;i++) {
        if(a[i] != 0)   cout << a[i]<< " ";
    }

}
int main () {
    primeNumber();
    return 0;
}

/*
    1. 배열에 모든 수를 담는다.
    2. 2부터 마지막 수까지 그 수의 배수는 0처리를 해준다.
    3. 0이 아닌 수들을 출력한다.
 */