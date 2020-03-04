/*

    1. 경로 중 minimum한 경로를 찾는 것이기 때문에, BFS
    2. 맵에 대한 입력 받기.
    3. R, B, 0에 대한 좌표 받아두기.

 */

#include <iostream>
#include <string>
#include <queue>
using namespace std;

typedef struct {
    int rx, ry, bx, by, cnt;
}ING;

struct Dir{
    int y,x;
};

const int MAX  = 10+1;
int N, M;
string map[MAX];
int f_rx, f_ry, f_bx, f_by, gx, gy;
queue<ING> q;
Dir moveDir[4] = {{1,0}, {-1,0}, {0,1}, {0,-1}};



void input() {
    cin >> N >> M;
    for(int i=0;i<N;i++) {
        cin >> map[i];
    }
}

void initialize() {
    for(int i=0;i<N;i++) {
        for(int j=0;j<M;j++) {
            if(map[i][j] == 'R') 
            {
                f_rx = j; f_ry = i;
            }
            if(map[i][j] == 'B')
            {
                f_bx = j; f_by = i;
            }
            // if(map[i][j] == '0')
            // {
            //     gx = j; gy = i;
            // }
        }
    }
}

void move(int &x, int &y, int mov_x, int mov_y, int &c) {
    while(map[y+mov_y][x+mov_x] == '.' || map[y+mov_y][x+mov_x] == 'B' || map[y+mov_y][x+mov_x] == 'R')  
    {
        
        x += mov_x;
        y += mov_y;
        c++;
        // cout << x << " " << y << endl;
    }
}


void sol() {
    q.push({f_rx,f_ry,f_bx,f_by,0});

    while(!q.empty()) 
    {
        int cur_bx = q.front().bx;
        int cur_by = q.front().by;
        int cur_rx = q.front().rx;
        int cur_ry = q.front().ry;
        int cur_cnt = q.front().cnt;
        q.pop();
        
        if(cur_cnt >= 10) {
            cout << -1 << endl;
            return;
        }
        
        for(int i=0;i<4;i++) 
        {
            int n_rx = cur_rx;
            int n_ry = cur_ry;
            int n_bx = cur_bx;
            int n_by = cur_by;
            int r_c = 0; int b_c = 0;
            
            //  블루와 레드 좌표를 각각 이동시킨다
            move(n_rx, n_ry, moveDir[i].x, moveDir[i].y, r_c);
            move(n_bx, n_by, moveDir[i].x, moveDir[i].y, b_c);
            // cout << r_c << " " << b_c << endl;
            if(map[n_ry + moveDir[i].y][n_rx + moveDir[i].x] == 'O') {
                if(map[n_by + moveDir[i].y][n_bx + moveDir[i].x] != 'O') 
                {
                    // cout << n_rx << " " << n_ry << " , " << n_bx << " " << n_by << endl;
                    cout << cur_cnt + 1 << endl;
                    return;
                } 
                else if (map[n_by + moveDir[i].y][n_bx + moveDir[i].x] == 'O')
                {
                    // cout << "?" << endl;
                    cout << -1 << endl;
                    return;
                }
            }

            // 블루와 레드 좌표가 겹치는 경우 처리 해주기.
            if(n_rx == n_bx && n_ry == n_by) 
            {
                if(r_c > b_c) 
                {
                    n_rx -= moveDir[i].x;
                    n_ry -= moveDir[i].y;
                } 
                else 
                {
                    n_bx -= moveDir[i].x;
                    n_by -= moveDir[i].y;
                }
            }
            
            q.push({n_rx, n_ry, n_bx, n_by, cur_cnt+1});
        }
    }
    
}


int main () {
    input();
    initialize();
    sol();
    
}