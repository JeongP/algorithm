#include <iostream>
#include <vector>
#include <cstring>
#include <queue>
#include <algorithm>

using namespace std;

const int MAX = 1001;
int N,M,V;
bool isVisited[MAX];

vector<int> v[MAX];
vector<int> dfs_v;
vector<int> bfs_v;
vector<int> dfs_v_result;
queue<int> q;
bool breaker;

void input() {
    cin >> N >> M >> V;
    int a, b;
    for(int i=0;i<M;i++) {
        cin >> a >> b;
        v[a].push_back(b);
        v[b].push_back(a);
    }
}

void dfs(int idx, int depth) {
    // 모든 점을 다 돌았거나 간선의 개수만큼 다 돌았거나
    if(depth == M || depth == N-1) {
        for(int i=0;i<dfs_v.size();i++) {
            dfs_v_result.push_back(dfs_v[i]);
        }
        breaker = true;
        return;
    };
    if(breaker == false) {
        for(int i=0;i<v[idx].size();i++) {
            int n_idx = v[idx][i];
            if(!isVisited[n_idx]) {
                isVisited[n_idx] = true;
                dfs_v.push_back(n_idx);
                dfs(n_idx, depth+1);
                dfs_v.pop_back();
                isVisited[n_idx] = false;
            }
        }
    }
    
}

void bfs(int idx) {
    
    while(!q.empty()) {
        int x = q.front();
        bfs_v.push_back(x);
        q.pop();

        for(int i=0;i<v[x].size();i++) {
            int n_idx = v[x][i];
            if(!isVisited[n_idx]) {
                isVisited[n_idx] = true;
                q.push(n_idx);
            }
        }
    }

}

void sorting() {
    for(int i=0;i<N;i++) {
        sort(v[i].begin(), v[i].end());
    }
}

void prt() {
    for(int i=0;i<dfs_v_result.size();i++) {
        cout << dfs_v_result[i] << " ";
    }
    cout << endl;
    for(int i=0;i<bfs_v.size();i++) {
        cout << bfs_v[i] << " ";
    }
}

int main() {
    // 입력받고
    input();

    // 각 점에 연결된 점들 sorting 과정
    sorting();

    // dfs
    isVisited[V] = true;
    dfs_v.push_back(V);
    dfs(V,0);

    memset(isVisited, false, sizeof(isVisited));

    // bfs
    isVisited[V] = true;
    q.push(V);
    bfs(V);
    
    prt();
}