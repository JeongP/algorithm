/*

    1. arr[] = 수열 입력 받을 배열
    2. d[] = 각 원소에서 가질 수 있는 감소하는 부분 수열 갯수
    3. 각 원소(n)에 대해, 앞 원소들(i)과 비교하여 크기가 작고, d[n] < d[i] + 1 이라면 교체 해줌.

 */


#include <iostream>

using namespace std;

const int MAX = 1001;

int n;
int arr[MAX];
int d[MAX];
int answer = 0;

void input() {
    cin >> n;
    for(int i=1;i<=n;i++) {
        cin >> arr[i];
    }
    for(int i=1;i<=n;i++) {
        d[i] = 1;
    }
}

void solution() {
    
    for(int i=1;i<=n;i++) {
        for(int j=1;j<i;j++) {
            if(arr[i] < arr[j] && d[i] < d[j] + 1) {
                d[i] = d[j] + 1;
            }
        }
        if(d[i] > answer) {
            answer = d[i];
        }
    }
}

void prt() {
    cout << answer << endl;
}


int main () {

    input();
    solution();
    prt();
    
}