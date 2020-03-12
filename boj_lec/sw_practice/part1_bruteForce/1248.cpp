#include <iostream>
#include <string>
#include <vector>
using namespace std;

int N;
string s;
vector<int> v;
bool end;

void input() {
    cin >> N >> s;
}

void prt() {
    for(int i=0;i<v.size();i++) {
        cout << v[i] << " ";
    }
}

void dfs(int before_num, int idx) {
    // cout << N*(N+1)/2;
    if(idx == N*(N+1)/2) {
        // 마지막 연산자까지 다 했을 경우 벡터 출력.
        prt();
        exit(0);
    }
    
    for(int i=-10;i<=10;i++) {
        if(s[idx] == '-') {
            if(before_num + i < 0) {
                // cout << i << " ";
                v.push_back(i);
                dfs(i,idx+1);
                v.pop_back();
            }
        } 
        else if(s[idx] == '+') {
            if(before_num + i > 0) {
                v.push_back(i);
                dfs(i,idx+1);
                v.pop_back();
            }
        } 
        else {
            if(before_num + i == 0) {
                v.push_back(i);
                dfs(i,idx+1);
                v.pop_back();
            }
        }
    }
}

void sol() {
    for(int i=-10;i==-10;i++) {
        // cout << i << " ";
        v.push_back(i);
        dfs(i,0);
        v.pop_back();
    }
}

int main () {
    input();
    sol();
}