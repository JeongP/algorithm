/*

    배운점.
    - 경로를 어떻게 담을까에 대한 부분이 어려웠음.
    - 도착점에 도달했을 때 첫 부분으로 찾아가기 위해 'beforeLoc = parent[afterLoc]'를 사용하면 된다는 것을 알 수 있었다.

 */

#include <iostream>
#include <vector>
#include <queue>
using namespace std;

const int MAX = 100000+1;
int N,K;
queue<pair<int,int>> q;
// 본인의 이전 루틴 idx를 담을 배열
int parent[MAX];
bool visit[MAX];
// 경로 담을 배열.
vector<int> path;


void input() {
    cin >> N >> K;
}

void prt(int n) {
    cout << n << endl;
    
    // 지나온 경로들 벡터에 넣어주기.
    int idx=K;
    while(idx!=N) {
        path.push_back(idx);
        idx = parent[idx];
    }
    path.push_back(N);

    for(int i=path.size()-1;i>=0;i--) {
        cout << path[i] << " ";
    }
}


void solution () {
    q.push(make_pair(N,0));
    while(!q.empty()) {
        
        for(int i=0;i<q.size();i++) {
            int cur_num= q.front().first;
            int cnt = q.front().second;
            q.pop();
            
            // 목적지에 도달 했을 때.
            if(cur_num == K) {      
                prt(cnt);
                return;
            }

            if(!visit[cur_num -1] && cur_num - 1 >= 0) {
                visit[cur_num -1] = true;
                parent[cur_num-1] = cur_num;
                q.push(make_pair(cur_num-1,cnt+1));
            }
            if(!visit[cur_num +1] && cur_num+1<=MAX) {
                visit[cur_num +1] = true;
                parent[cur_num+1] = cur_num;
                q.push(make_pair(cur_num+1,cnt+1));
            }
            if(!visit[cur_num*2] && cur_num*2<=MAX) {
                visit[cur_num*2] = true;
                parent[cur_num*2] = cur_num;
                q.push(make_pair(cur_num*2,cnt+1));
            }
            
        }
    }
}
int main () {
    input();
    solution();
}