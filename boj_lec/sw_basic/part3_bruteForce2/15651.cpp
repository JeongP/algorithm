/*

    1. 깊이우선탐색.
    2. 이전과 다른점은 방문여부를 따져주지 않고 방문한것도 또 방문해도 됨.

 */

#include <iostream>
#include <vector>
#define MAX 8
using namespace std;

int N,M;
vector<int> v;

void input() {
    cin >> N >> M;
}

void prt() {
    for(int i=0;i<v.size();i++) {
        cout << v[i] << " ";
    }
    cout << '\n';
}


void dfs(int depth) {
    if(depth == M) {
        prt();
        return;
    }

    for(int i=1;i<=N;i++) {
        v.push_back(i);
        dfs(depth+1);
        v.pop_back();
    }
}

void solution() {
    dfs(0);
}

int main () {
    input();
    solution();
}