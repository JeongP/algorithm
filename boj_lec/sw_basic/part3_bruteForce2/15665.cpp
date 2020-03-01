/*

    1. dfs로 나열한다.
    2. 중복조건을 체크해준다.
    2-1. 중복조건을 체크하기위해 출력단계에 있는 벡터들을 문자열로 만들어 set 자료구조에 넣어주고, find 함수로 찾아줌.
    2-2. 벡터의 find는 시간 초과 발생..

 */

#include <iostream>
#include <algorithm>
#include <set>
#include <vector>
#include <string>

using namespace std;

const int MAX = 8;
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

void dfs(int depth) {
    if(depth == m) {
        if(duplicate() == false) {
            prt();
        }
        return;
    }

    for(int i=0;i<n;i++) {
        v.push_back(arr[i]);
        dfs(depth+1);
        v.pop_back();
    }
}


void sol() {
    dfs(0);
}


int main () {
    input();
    sol();
}