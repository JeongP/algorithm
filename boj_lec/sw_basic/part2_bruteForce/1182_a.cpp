#include <iostream>
#include <vector>

using namespace std;

int N,S;
vector<int> v;
int result = 0;

void input() {
    cin >> N >> S;
    v.resize(N);
    
    for(int i=0;i<N;i++) {
        cin >> v[i];
    }
}

void dfs(int i ,int sum) {
    sum += v[i];
    if(i>N) return;
    if(sum == S) result++;
    dfs(i+1,sum);
    dfs(i+1,sum-v[i]);
}

void prt() {
    cout << result;
}

int main () {
    input();
    dfs(0,0);
    prt();
}


/*
    1. 입력받기
    2. 전체 수 체크
    2-1. 전체 수를 어떻게 볼 수 있을지
    2-2. o x o x 로 모든 숫자 확인 가능.
 */