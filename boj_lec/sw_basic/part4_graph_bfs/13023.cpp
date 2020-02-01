// 다섯명 이상이 친구인지를 보는 문제라고 생각해야함.

#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

const int MAX = 2000;
int N, M;
vector<int> v[MAX];
bool isVisited[MAX];
bool result = false;

void input() {
    int a, b;
    cin >> N >> M;
    for(int i=0;i<M;i++) {
        cin >> a >> b;
        v[a].push_back(b);
        v[b].push_back(a);
    }
}

void dfs(int idx, int cnt) {
    if(cnt == 5) {
        result = true;
        return;
    }
    for(int i=0; i<v[idx].size();i++) {
        int n_idx = v[idx][i];
        if(!isVisited[n_idx]) {
            isVisited[n_idx] = true;
            dfs(n_idx, cnt+1);
            isVisited[n_idx] = false;
        }
    }
}

void sol() {

    for(int fri_idx=0;fri_idx<N;fri_idx++) {
        memset(isVisited, false, sizeof(isVisited));
        isVisited[fri_idx] = true;
        dfs(fri_idx,1);
        isVisited[fri_idx] = false;
        if(result) break;    
    }
    if(result) cout << 1 << endl;
    else cout << 0 << endl;
}



int main () {
    input();
    sol();
}