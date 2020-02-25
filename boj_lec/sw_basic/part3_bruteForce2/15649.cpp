/*

    1. 주어진 조건에 맞는 수열을 모두 구하는 문제. => DFS로 구현
    2. 모든 점에 대해 dfs를 진행함.
    2-1. 방문하지 않았으면 방문하고 벡터에 넣고..
    2-2. dfs에서의 depth가 m과 같다면 벡터를 모두 출력해주고 마무리.


    +)
    endl은 시간을 많이 잡아먹는다고.. 그래서 endl 보다는 \n 쓰기를 추천.
    그리고 입력에서의 
    ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
    .. 또한 시간을 줄일 수 있는 tip?

 */

#include <iostream>
#include <vector>
#define MAX 9
using namespace std;

vector<int> v;
bool visit[MAX];

void dfs(int n, int m, int depth) {
    if(depth == m) {
        // 벡터 값들 출력 후 개행
        for(int i=0;i<m;i++) {
            cout << v[i] << " ";
        }
        cout << '\n';
        return;
    }
    
    for(int i=1;i<=n;i++) {
        if(!visit[i]) {
            visit[i] = true;
            v.push_back(i);
            dfs(n,m,depth+1);
            v.pop_back();
            visit[i] = false;
        }
    }
}

void solution (int n,int m) { 
    dfs(n,m,0);
}

int main () {
    int m,n;
    ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
    cin >> n >> m;

    solution(n,m);
    
    return 0;

}