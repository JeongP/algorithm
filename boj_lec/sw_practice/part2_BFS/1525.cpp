#include <iostream>
#include <string>
#include <queue>
#include <set>
using namespace std;

typedef struct {
    int y,x;
}Dir;

Dir moveDir[4] = {{1,0},{-1,0},{0,1},{0,-1}};

string Start, End;
set<string> visit;

void input() {
    End = "123456780";
    for(int i=0;i<3;i++) {
        for(int j=0;j<3;j++) {
            int x;
            cin >> x;
            char a = x + '0';
            Start += a;
        }
    }
}

void BFS() {
    queue<pair<string, int>> q;
    q.push(make_pair(Start,0));
    visit.insert(Start);
    

    while(!q.empty()) {
        string cur = q.front().first;
        int cnt = q.front().second;
        q.pop();

        if(cur == End) {
            cout << cnt << endl;
            return;
        }

        int zero = cur.find('0');
        int x = zero/3;
        int y = zero%3;

        for(int i=0;i<4;i++) {
            int nx = x + moveDir[i].x;
            int ny = y + moveDir[i].y;

            if(0<=nx && nx <3 && 0<=ny && ny<3) {
                string nstr = cur;
                // 위치 바꾸고
                swap(nstr[x*3+y], nstr[nx*3+ny]);
                // 이전에 없던 경우라면 추가해주기.
                if(visit.find(nstr) == visit.end()) {
                    visit.insert(nstr);
                    q.push(make_pair(nstr, cnt+1));
                }
            }
        }
    }
    cout << -1 << endl;
    return;
}

int main () {
    input();
    BFS();
}