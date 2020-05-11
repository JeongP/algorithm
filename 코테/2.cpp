#include <string>
#include <vector>
#include <queue>

using namespace std;

const int MAX = 610;
bool visit[MAX][MAX];
int result[MAX][MAX]; // 거리를 나타낼 배열.
queue<pair<int,pair<int,int>>> q; // 경과시간,(y,x) 좌표를 담은 큐

int dir[4][2] = {{0,1},{0,-1},{1,0},{-1,0}};

vector<vector<int>> solution(int N, vector<vector<int>> bus_stop) {
    vector<vector<int>> answer;
    vector<int> ans;
    // init
    for(int i=0;i<bus_stop.size();i++) {
        // 버스 정류장들 큐에 넣어주기. 
        int y = bus_stop[i][0]-1;
        int x = bus_stop[i][1]-1;
        q.push(make_pair(0,make_pair(y,x)));
        
        // 초기 정류장 위치 방문처리.
        visit[y][x] = true;
    }

    
    // 각 버스 정류장으로부터 시간 1씩 경과시키면서 방문처리 해주기. 
    while(!q.empty()) {
        int cur_qsize = q.size();
        
        for(int i=0; i<cur_qsize; i++) {
        
            int sec = q.front().first;
            int cur_y = q.front().second.first;
            int cur_x = q.front().second.second;
            q.pop();
            
            for(int k=0;k<4;k++) {
                int ny = cur_y + dir[k][0];
                int nx = cur_x + dir[k][1];
                
                // 다음 곳이 해당 범위 안에 있고, 방문하지 않았다면
                if(!visit[ny][nx] && 0<=ny && ny< N && 0<=nx && nx < N) {
                    visit[ny][nx] = true;
                    result[ny][nx] = sec+1;
                    q.push(make_pair(sec+1,make_pair(ny,nx)));
                }
            }
        }
    }
    
    
    // 정답 옮겨 넣기.
    for(int i=0;i<N;i++) {
        for(int j=0;j<N;j++) {
            int val = result[i][j];
            ans.push_back(val);
        }
        answer.push_back(ans);
        ans.clear();
    }
    return answer;
}




// 큐 체크
    // cout << q.front().first << " " << q.front().second.first;