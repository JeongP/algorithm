#include <iostream>
#include <vector>
using namespace std;

int N, B, C;
vector<int> v;
int gamdok = 0;

void input() {
    cin >> N;
    // 고사장
    for(int i=0;i<N;i++) {
        int x;
        cin >> x;
        v.push_back(x);
    }
    cin >> B >> C;
}

void solution() {
    // 총 감독 제외
    for(int i=0;i<N;i++) {
        gamdok++;
        if(v[i] - B < 0) {
            v[i] = 0;
        } else {
            v[i] = v[i] - B;
        }
    }

    for(int i=0;i<N;i++) {
        // 나머지가 있다는건 한 명 더 필요
        if(v[i] % C != 0) {
            int moc = v[i] / C;
            gamdok = gamdok + moc + 1;
        } else {
            int moc = v[i] / C;
            gamdok = gamdok + moc;
        }
    }
    
}

int main () {
    input();
    solution();
    cout << gamdok << endl;
}