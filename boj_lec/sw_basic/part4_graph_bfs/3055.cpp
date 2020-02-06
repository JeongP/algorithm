#include <iostream>
#include <queue>

using namespace std;

const int MAX = 50+1;
int R,C;
char map[MAX][MAX];
queue<pair<pair<int,int>,int>> q;
queue<pair<int,int>> wq;
int start_x, start_y;
int end_x, end_y;
int answer = 0;
int visit[MAX][MAX][2]; // 그냥 방문 여부와 잠김 여부 체크.

typedef struct {
    int y,x;
}Dir;

Dir moveDir[4] = {{1,0}, {-1,0}, {0,1}, {0,-1}};

void input() {
    cin >> R >> C;
    for(int i=0;i<R;i++) {
        for(int j=0;j<C;j++) {
            cin >> map[i][j];
            if(map[i][j] == 'S') {
                start_x = j;
                start_y = i;
                q.push(make_pair(make_pair(i,j),0));
            }
            if(map[i][j] == 'D') {
                end_x = j;
                end_y = i;
            }
            if(map[i][j]=='*') {
                wq.push(make_pair(i,j));
            }
            if(map[i][j] == 'X') {
                visit[i][j][0] = 1;
                visit[i][j][1] = 1;
            }
        }
    }
}

// void inputcheck() {
//     for(int i=0;i<R;i++) {
//         for(int j=0;j<C;j++) {
//             cout << map[i][j] << " ";
//         }
//         cout << endl;
//     }
// }

bool BFS() {
    int cur_qsize = q.size();
    
    int routeCnt = 0;
    // cout << "#" << endl;
    for(int i=0;i<cur_qsize;i++) {

        int y = q.front().first.first;
        int x = q.front().first.second;
        int min = q.front().second;
        q.pop();
        
        if(y == end_y && x == end_x) {
            // cout << 11 << endl;
            answer = min;
            return false;
        }

        // cout << "(" << y << " " << x << ")" << endl;
        for(int i=0;i<4;i++) {
            int ny = y + moveDir[i].y;
            int nx = x + moveDir[i].x;
            
            if(0<=nx && nx<C && 0<=ny && ny<R && !visit[ny][nx][0] && !visit[ny][nx][1]) {
                // 갈 수 있는 곳이라면 방문처리 후 q에 다음좌표와 증가한 시간 삽입.
                visit[ny][nx][0] = 1;
                q.push(make_pair(make_pair(ny,nx),min+1));
                // cout << ny << " " << nx << endl;
                // 길 수 cnt    
                routeCnt++;
            }
        }
    }

    if(routeCnt == 0) {
        
        return false;
    }else {
        return true;
    }
}



void sol() {
    while(!wq.empty()) {

        int cur_wsize = wq.size();

        for(int i=0;i<cur_wsize;i++) {

            int wy = wq.front().first;
            int wx = wq.front().second;
            wq.pop();
            // cout << "[[" << wy << " " << wx << "]]" << endl;
            for(int i=0;i<4;i++) {
                int nwy = wy + moveDir[i].y;
                int nwx = wx + moveDir[i].x;
            
                // 범위 내에 있고, 잠기지 않은 점이라면
                if(nwy >= 0 && nwy < R && nwx >= 0 && nwx < C && !visit[nwy][nwx][1]) {
                    if(nwy == end_y && nwx == end_x) {
                        
                    }else {
                        // 잠김처리와 방문처리(이동불가하게)
                        visit[nwy][nwx][0] = 1;
                        visit[nwy][nwx][1] = 1;
                        wq.push(make_pair(nwy,nwx));
                        }
                }   
            }
        }

        // 길이 없다면
        if(!BFS()) {
            if(answer != 0) {
                cout << answer << endl;
                return;
            }else {
                cout << "KAKTUS" << endl;
                return;
            }
            
        }
    }
}


int main () {

    input();
    // inputcheck();
    
    visit[start_y][start_x][0] = 1;
    sol();

}