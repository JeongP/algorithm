#include <iostream>
#include <queue>
#include <string>
using namespace std;

int N,K,L;
queue<pair<int,string>> q;
queue<pair<int,int>> snake;
bool map[110][110];
int sec = 0;
// int dir[4][2] = {{}};

void input() {
    cin >> N >> K;
    for(int i=0;i<K;i++){ 
        int y,x;
        cin >> y >> x;
        map[y][x] = true;   
    }
    cin >> L;
    for(int i=0;i<L;i++) {
        int x; string c;
        cin >> x >> c;
        q.push(make_pair(x,c));
    }
}

void move(int step, string dir) {
    int y = snake.front().first;
    int x = snake.front().second;
    if(x==1 && y==1) {
        // 처음 시작점에서 move
        while(step--) {
            int nx = x+1;
            // 범위 안에서 움직일 수 있고
            if(nx <= N) {
                // 사과가 있따면 새롭게 넣어주고 기존거 다 뒤로..
                if(map[y][nx]) {
                    snake.push(make_pair(y,nx));
                    for(int qs=0;qs<snake.size()-1;qs++) {
                        int a = snake.front().first;
                        int b = snake.front().second;
                        snake.pop();
                        snake.push(make_pair(a,b));
                    }
                }else {
                    for(int qs=0;qs<snake.size();qs++) {
                        int a = snake.front().first;
                        int b = snake.front().second;
                        b+=1;
                        snake.pop();
                        snake.push(make_pair(a,b));
                    }
                }
            }   
        }
        
    }else {

    }
}

void gameStart() {
    // 뱀의 첫 좌표.
    snake.push(make_pair(1,1));
    
    // 경로가 다할때까지.
    while(!q.empty()) {
        int step = q.front().first;
        string dir = q.front().second;
        q.pop();
        move(step,dir);

    }
}

int main () {
    input();
    gameStart();
}