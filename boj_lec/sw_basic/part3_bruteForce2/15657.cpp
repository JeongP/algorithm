#include <iostream>
#include <vector>
#include <algorithm>
#define MAX 8
using namespace std;

int n,m;
vector<int> v;
vector<int> inv;

void input() {
    cin >> n >> m;
    int x;
    for(int i=0;i<n;i++) {
        cin >> x;
        inv.push_back(x);
    }
    sort(inv.begin(),inv.end());
}

void prt() {
    for(int i=0;i<m;i++) {
        cout << v[i] << " ";
    }
    cout << '\n';
}

void dfs(int idx,int depth) {
    if( depth == m ) {
        prt();
        return;
    }
    
    for(int i=idx;i<n;i++) {
        v.push_back(inv[i]);
        dfs(i,depth+1);
        v.pop_back();
    }
}


void sol() {
    for(int i=0;i<n;i++) {
        v.push_back(inv[i]);
        dfs(i,1);
        v.pop_back();
    }
}


int main () {
    input();
    sol();
}