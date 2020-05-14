#include <iostream>
#include <queue>
#include <deque>

using namespace std;

const int MAX = 101;
enum { UP, RIGHT, DOWN, LEFT};
int board[MAX][MAX] = {0};
int dx[4] = {-1,0,1,0};
int dy[4] = {0,1,0,-1};
deque<pair<int,int>> snake;
int now_dir = RIGHT;
int N, sec = 0;

void changeDir(char _way) {
    if(_way == 'L') {
        now_dir = (now_dir + 3)%4;
    }else {
        now_dir = (now_dir + 1)%4;
    }
}
bool move() {
    
    int curX = snake.front().first + dx[now_dir];
    int curY = snake.front().second + dy[now_dir];
    // 게임 끝나느 조건
    if(curX < 1 || curX > N || curY < 1 || curY > N) return false;
    if(board[curY][curX] == -1) return false;
    
    snake.push_front(make_pair(curX,curY));
    if(board[curX][curY] != 1) {
        board[snake.back().first][snake.back().second] = 0;
        snake.pop_back();
    }
    board[curX][curY] = -1;
    return true;

}

int main () {
    snake.push_back(make_pair(1,1)); board[1][1] = -1;
    int K;
    cin >> N >> K;
    for(int i=0;i<K;i++) {
        int row, col;
        cin >> row >> col;
        board[row][col] = 1;
    }

    int L;
    cin >> L;
    for(int i=0;i<L;i++) {
        int X; char C;
        cin >> X >> C;
        // 이동
        while(sec != X) {
            if(move() == false) {
                cout << sec+1 << endl;
                return 0;
            }
            sec++;
        }
        
        // 방향 전환
        changeDir(C);
    }
}