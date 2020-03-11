#include <iostream>
using namespace std;

const int MAX = 10;
int N,K;
int arr[MAX];
int cnt = 0;
void input() {
    cin >> N >> K;
    for(int i=0;i<N;i++) {
        cin >> arr[i];
    }
}

void sol() {
    // 가장 큰 금액서부터 돌면서 개수를 채워나감..
    for(int i=N-1;i>=0;i--) {
        if(K==0) {
            break;
        }
        if(K/arr[i] == 0) continue;
        
        int mok = K / arr[i];
        cnt += mok;
        K -= mok * arr[i];
    }
    
    cout << cnt << endl;
}

int main () {
    input();
    sol();
    return 0;
}