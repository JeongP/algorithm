/*

    1. arr[] = input 수열 담을 배열
    2. 어떤 수를 기점으로 증가하는 수열의 개수를 담을 배열과 감소하는 수열의 개수를 담을 배열을 만든다.
    3. 위의 두 배열을 더한것 중 가장 큰 값이 답.

 */

#include <iostream>
#include <algorithm>

using namespace std;

const int MAX = 1001;
int n;
int arr[MAX];
int up[MAX];
int down[MAX];

int answer =0;

void input() {
    cin >> n;
    for(int i=1;i<=n;i++) {
        cin >> arr[i];
        up[i] = down[i] = 1;
    }
}

void sol() {
    for(int i=1;i<=n;i++) {
        // 증가하는 부분수열
        for(int j=1;j<i;j++) {
            if(arr[j] < arr[i] && up[i] < up[j] + 1) {
                up[i] = up[j] + 1;
            }
        }
    }

    for(int i=n;i>=1;i--) {
        // 감소하는 부분수열
        for(int j=n;j>=i;j--) {
            if(arr[j] < arr[i] && down[i] < down[j] + 1) {
                down[i] = down[j] + 1;
            }
        }
    }

    for(int i=1;i<=n;i++) {
        answer = max(answer, up[i] + down[i]);
    }
}



void prt() {
    cout << answer-1 << endl;
}

int main () {

    input();
    sol();
    prt();
}