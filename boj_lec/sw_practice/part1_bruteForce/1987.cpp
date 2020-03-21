/*

    DFS로 풀겠습니다.
    BFS는 각 진행경로마다 방문한 알파벳여부를 파악하는게 복잡해서 입니다.

 */

#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int R,C;
bool alphabet[26];
string s[20];
int result = -1;

struct Dir {
    int y,x;
};

Dir moveDir[4] = {{1,0},{0,1}, {-1,0}, {0,-1}};

void input() {
    cin >> R >> C;
    for(int i=0;i<R;i++) {
        cin >> s[i];
        // for(int j=0;j<s[i].length();j++) {
        //     int idx = s[i][j] - 'A';
        //     if(!alphabet[idx]) {
        //         alphabet[idx] = true;
        //     }
        // }   
    }
}

void dfs(int y, int x, int cnt) {

    result = max(result, cnt);
    
    for(int i=0;i<4;i++) {
        int nx = x + moveDir[i].x;
        int ny = y + moveDir[i].y;

        
        if(0<=nx && nx < C && 0 <= ny && ny < R) {
            int idx = s[ny][nx] - 'A';
            if(!alphabet[idx]) {
                alphabet[idx] = true;
                dfs(ny,nx,cnt+1);
                alphabet[idx] = false;
            }
        }
        
    }

}

void sol () {
    int idx = s[0][0] - 'A';
    alphabet[idx] = true;
    dfs(0,0,1);
}

int main () {
    input();
    sol();
    cout << result << endl;
}