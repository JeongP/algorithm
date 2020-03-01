#include <iostream>
#include <algorithm>
#include <set>
#include <vector>
#include <string>

using namespace std;

const int MAX = 9;
int n,m;
int arr[MAX];
vector<int> v;
set<string> s;

void input () {
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
    if(s.find(tmp) == s.end()) {
        s.insert(tmp);
        return false;
    }else {
        return true;
    }
}


void prt() {
    for(int i=0;i<m;i++) {
        cout << v[i] << " ";
    }

    cout << '\n';
}

void dfs(int idx, int depth) {
    if(depth == m) {
        if(duplicate() == false) {
            prt();
        }
        return;
    }

    for(int i=idx;i<n;i++) {
        v.push_back(arr[i]);
        dfs(i,depth+1);
        v.pop_back();
    }
}


void sol() {
    for(int i=0;i<n;i++) {
        v.push_back(arr[i]);
        dfs(i,1);
        v.pop_back();
    }
}


int main () {
    input();
    sol();
}