#include <iostream>
#include <vector>
#include <algorithm>
#define MAX 9
using namespace std;

int n,m;
vector<int> v;
vector<int> inv;
bool visit[MAX];

void input() {
    cin >> n >> m;
    int x;
    for(int i=0;i<n;i++) {
        cin >> x;
        inv.push_back(x);
    }
    sort(inv.begin(), inv.end());
}

void prt() {
    for(int i=0;i<v.size();i++) {
        cout << v[i] << " ";
    }
    cout << '\n';
}

void dfs(int idx, int depth) {
    if(depth == m) {
        prt();
        return;
    }
    for(int i=idx;i<n;i++) {
        if(!visit[i]) {
            visit[i] = true;
            v.push_back(inv[i]);
            dfs(i, depth+1);
            v.pop_back();
            visit[i] = false;
        }
    }
}


void solution() {
    for(int i=0;i<n;i++) {
        int start = inv[i];
        visit[i] = true;
        v.push_back(start);
        dfs(i, 1);
        v.pop_back();
        visit[i] = false;
    }
}



int main () {
    input();
    solution();
}