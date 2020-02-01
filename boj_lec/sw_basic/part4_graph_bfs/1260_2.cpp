#include <iostream>
#include <vector>
#include <cstring>
#include <queue>

using namespace std;

const int MAX = 1001;
int N, M, V;
vector<int> v[MAX];
bool isVisited[MAX];
queue<int> q;


void input() {
    cin >> N >> M >> V;
    int a,b;
    for(int i=0;i<M;i++) {
        cin >> a >> b;
        v[a].push_back(b);
        v[b].push_back(a);
    }
}

void dfs(int idx) {
    cout << idx << " ";
    for(int i=0;i<N;i++) {
        if(!isVisited[i] && v[idx][i]) {
            isVisited[i] = true;
            dfs(i);
        }
    }
}

void bfs(int idx) {
    
    q.push(idx);
    isVisited[idx] = true;

    while(!q.empty()) {
        int x = q.front();
        q.pop();
        cout << x << " ";
        
        for(int i=0;i<N;i++) {
            if(!isVisited[i] && v[idx][i]) {
                isVisited[i] = true;
                q.push(i);
            }
        }
    }
}

int main () {

    input();
    dfs(V);
    cout << endl;
    memset(isVisited, false, sizeof(isVisited));
    bfs(V);
    return 0;

}