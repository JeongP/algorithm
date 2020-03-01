#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
#include <set>

#define MAX 9
using namespace std;

int n,m;
int arr[MAX];
bool visit[MAX];
vector<int> v;
set<string> s;


void input() {
    cin >> n >> m;
    for(int i=0;i<n;i++) {
        cin >> arr[i];
    }
    sort(arr, arr+n);
}

bool duplicate() {
    string tmp;
    for(int i=0;i<v.size();i++) {
        char a = v[i] + '0';
        tmp += a;
    }
    // set에서 찾을 수 없다면.. (중복 x)
    if(s.find(tmp) == s.end()) {
        s.insert(tmp);
        return false;
    }else {
        return true;
    }
}

void prt() {
    for(int i=0;i<v.size();i++) {
        cout << v[i] << " ";
    }
    cout << endl;
}

void dfs(int idx, int depth) {
    if(depth == m) {
        if(duplicate() == false) {
            prt();
        }
        return;
    }

    for(int i=idx;i<n;i++) {
        if(!visit[i]) {
            visit[i] = true;
            v.push_back(arr[i]);
            dfs(i,depth+1);
            v.pop_back();
            visit[i] = false;
        }
    }
}


void sol () {
    for(int i=0;i<n;i++) {
        visit[i] = true;
        v.push_back(arr[i]);
        dfs(i,1);
        v.pop_back();
        visit[i] = false;
    }
}

int main () {
    input();
    sol();
}