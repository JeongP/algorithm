/*

    1. dfs
    2. 같은 수 여러번 -> 방문처리 x
    3. 비내림차순 -> 같거나 큰 부분에서만 dfs 진행

 */

#include <iostream>
#include <vector>
#define MAX 9
using namespace std;

int n,m;
vector<int> v;

void input () {
    cin >> n >> m;
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

    for(int i=idx;i<=n;i++) {
        v.push_back(i);
        dfs(i,depth+1);
        v.pop_back();
    }

}
void solution () {
    for(int i=1;i<=n;i++) {
        v.push_back(i);
        dfs(i,1);
        v.pop_back();
    }
}

int main () {
    input();
    solution();    
}