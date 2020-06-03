
#include<iostream>
#include <queue>
#include <vector>
#include <cstdio>
using namespace std;

queue<pair<int,int>> q;
queue<int> dq;
queue<int> gq;
int dirY[4] = {0,-1,0,1};
int dirX[4] = {1,0,-1,0};
bool map[101][101] = {0,};
vector<pair<int,int>> v;
int result = 0;

void input() {
    int N;
    cin >> N;
    for(int i=0;i<N;i++) {
        int x,y,d,g;
        cin >> x >> y >> d >> g;
        q.push(make_pair(x,y));
        dq.push(d);
        gq.push(g);
    }
}

void sol() {
    while(!q.empty()) {
        int x = q.front().first;
        int y = q.front().second;
        int d = dq.front(); int g = gq.front();
        q.pop(); dq.pop(); gq.pop();

        // 0세대 진행
        int nx = x + dirX[d];
        int ny = y + dirY[d];
        v.push_back(make_pair(x,y));
        v.push_back(make_pair(nx,ny));
        map[y][x] = true;
        map[ny][nx] = true;

        // g세대 만큼 진행
        while(g--) {
            int cur_vsize = v.size();
            int endX = v[cur_vsize-1].first;
            int endY = v[cur_vsize-1].second;
            for(int i=cur_vsize-1;i>=1;i--) {
                
                int lastX = v[i].first;
                int lastY = v[i].second;
                int secX = v[i-1].first;
                int secY = v[i-1].second;
                int forwardDir = -1;
                // 벡터 뒤에서 부터 두 점의 이동 방향 찾아주고
                if (lastX - secX > 0) forwardDir = 1;
                else if (lastX - secX < 0) forwardDir = 3;
                else if (lastY - secY > 0) forwardDir = 0;
                else if (lastY - secY < 0) forwardDir = 2;
                // 끝 점에서 이동 방향 정해진 대로 이동시켜준 뒤
                endX += dirX[forwardDir];
                endY += dirY[forwardDir];

                // v에 넣고 map을 방문처리 해준다.
                v.push_back(make_pair(endX,endY));
                map[endY][endX] = true;
            }
        }
        v.clear();
    }
}

int findSquare () {
    int cnt = 0;
    for(int i=0;i<100;i++) {
        for(int j=0;j<100;j++) {
            if(map[i][j] && map[i][j+1] && map[i+1][j] && map[i+1][j+1]) cnt++;
        }
    }
    return cnt;
}

int main(int argc, char** argv)
{
    input();
    sol();
        
    int result = findSquare();
    cout << result << endl;
	return 0;
}