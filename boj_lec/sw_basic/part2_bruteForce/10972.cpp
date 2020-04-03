#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N;
vector<int> v;
vector<int> standv;
bool visit[10001];
bool flagVal;

void input() {
    cin >> N;
    for(int i=1;i<=N;i++) {
        int x; cin >> x;
        standv.push_back(x);
    }
}

bool isEqual() {
    for(int i=0;i<N;i++) {
        if(standv[i] != v[i]) return false;
    }
    return true;
}

void prt() {
    for(int i=0;i<N;i++) {
        cout << v[i] << " ";
    }
    cout << endl;
}

void dfs(int depth) {
    
    if(depth == N) {
        if(!flagVal) {
            flagVal = isEqual();
        }else {
            prt();
            exit(0);
        }
    }
    
    for(int i=1;i<=N;i++) {
        if(!visit[i]) {
            visit[i] = true;
            v.push_back(i);
            dfs(depth+1);
            v.pop_back();
            visit[i] = false;
        }
    }
}

bool desc (int a, int b) {
    return a > b;
}

bool isLast() {
    for(int i=1;i<=N;i++) {
        v.push_back(i);
    }
    sort(v.begin(),v.end(),desc);
    if(isEqual()) {
        return true;
    } else {
        while(!v.empty()) {
            v.pop_back();
        }
        return false;
    }
}

void sol() {
    if(isLast()) {
        cout << -1 << endl;
        exit(0);
    }
    for(int i=1;i<=N;i++) {
        visit[i] = true;
        v.push_back(i);
        dfs(1);
        v.pop_back();
        visit[i] = false;
    }
}

int main () {
    input();
    sol();
    return 0;
}
