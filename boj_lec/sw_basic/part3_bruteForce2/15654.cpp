#include <iostream>
#include <vector>
#include <algorithm>
#define MAX 9
using namespace std;

int N, M;
vector<int> v;
vector<int> inv;
bool visit[MAX];

void input() {
    cin >> N >> M;
    int x;
    for(int i=0;i<N;i++) {
        cin >> x;
        inv.push_back(x); 
    }
    sort(inv.begin(), inv.end());
}

void prt() {
    for(int i=0;i<M;i++) {
        cout << v[i] << " ";
    }
    cout << '\n';
}

void dfs (int depth) {
    if(depth == M) {
        prt();
        return;
    }

    for(int i=0;i<inv.size();i++) {
        int idx = inv[i];
        if(!visit[idx]) {
            visit[idx] = true;
            v.push_back(idx);
            dfs(depth +1);
            v.pop_back();
            visit[idx] = false;
        }
    }
}

void solution() {
    for(int i=0;i<inv.size();i++) {
        int start = inv[i];
        if(!visit[start]) {
            visit[start] = true;
            v.push_back(start);
            dfs(1);
            v.pop_back();
            visit[start] = false;
        }
        
    }
}

int main () {
    input();
    solution();
}