#include <iostream>
#include <queue>
using namespace std;

const int MAX = 2001;
bool v[MAX][MAX];

int BFS(int s, queue<pair<pair<int,int>,int>> q) {
    
    while(!q.empty()) { 

        int dis = q.front().first.first;
        int clip = q.front().first.second;
        int sec = q.front().second;
        q.pop();

        if(s == dis) return sec;

        if(0<dis && dis<MAX && !v[dis][dis]) {
            v[dis][dis] = true;
            q.push(make_pair(make_pair(dis,dis),sec+1));
        }

        if(0<clip && clip+dis < MAX && !v[dis+clip][clip]) {
            v[dis+clip][clip] = true;
            q.push(make_pair(make_pair(dis+clip,clip),sec+1));
        }

        if(dis > 0 && !v[dis-1][clip]) {
            v[dis-1][clip] = true;
            q.push(make_pair(make_pair(dis-1,clip),sec+1));
        }
    }

    
}


int main () {
    int s;
    cin >> s;

    queue<pair<pair<int,int>,int>> q;
    bool v[MAX][MAX];

    q.push(make_pair(make_pair(1,0),0));
    int answer = BFS(s, q);
    cout << answer << endl;

}


/*
    1. BFS로 탐색을 진행할겁니다. (최소시간)
    2. BFS이기 때문에 queue와 방문여부를 사용할 변수를 사용할 거고.
    3. 화면에 출력된 이모티콘 갯수(x)와 클립보드에 있는 이모티콘 갯수(y)를 담을 수 있는 2차원 배열을 사용하겠습니다.
    4. bool v[x][y]로 하여, 같은 상황에 추가적인 분기가 없도록.
    5. queue에는 ((화면 이모티콘 개수, 전광판 이모티콘 개수), 경과 시간) 을 담아주겠습니다.
    6. 각 조건별로 BFS를 진행해줍니다.
    6-1. 조건1) 화면에 1개 이상의 이모티콘이 있어야하는 조건, 그리고 v[x][x]가 미방문 상태면 실행.
    6-2. 조건2) 클립보드에 1개 이상의 이모티콘이 있어야 하고 v[x+y][y]가 미방문 상태면 실행.
    6-3. 조건3) 화면에 이모티콘 1개 이상 있어야하고 v[x-1][y]가 미방문 상퇴면 실행.
 */