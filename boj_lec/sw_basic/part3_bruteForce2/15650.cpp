/*

    1. 주어진 조건에 맞는 수열. -> DFS
    2. 15659의 문제와 비슷하지만 수열을 진행함에 있어 이전 수가 다음수보다 큰지 조건을 넣어주면 됨.

 */


#include <iostream>
#include <vector>
#define MAX 9
using namespace std;

int n,m;
vector<int> v;
bool visit[MAX];

void dfs(int idx, int depth) {
    if(depth == m) {
        
        for(int i=0;i<m;i++) {
            cout << v[i] << " ";
        }
        cout << '\n';
        return;
    }

    for(int i=idx;i<=n;i++) {
        if(!visit[i]) {
            visit[i] = true;
            v.push_back(i);
            dfs(i, depth+1);
            v.pop_back();
            visit[i] = false;
        }
    }
}

int main () {

    ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

    cin >> n >> m;
    for(int i=1;i<=n-m+1;i++) {
        if(!visit[i]) {
            visit[i] = true;
            v.push_back(i);
            dfs(i,1);
            v.pop_back();
            visit[i] = false;
        }
    }
    
    return 0;
    
}