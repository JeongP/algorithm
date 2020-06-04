#include<iostream>
#include<queue>
#include<vector>
#include<cstdio>
#include<cmath>
using namespace std;


int N, L,R;
int map[51][51] = {0,};
bool visit[51][51] = {0,};
int dirX[4] = {0,1,0,-1};
int dirY[4] = {-1,0,1,0};
queue<pair<char,pair<int,int>>> q;
vector<pair<char,pair<int,int>>> v;
queue<pair<int,int>> q2;
int result = 0;

void input() {
    cin >> N >> L >> R;
    for(int i=0;i<N;i++) {
        for(int j=0;j<N;j++) {
            cin >> map[i][j];
        }
    }
}

bool possi() {
    // 연합 만들 수 없는 경우 false 리턴
    for(int i=0;i<N;i++) {
        for(int j=0;j<N;j++) {
            for(int k=0;k<4;k++) {
                int ny = i + dirY[k];
                int nx = j + dirX[k];
                if(ny >= 0 && ny < N && nx >= 0 && nx < N) {
                    int n = abs(map[i][j] - map[ny][nx]);
                    if(n >= L && n <= R) return true;
                }
            }
        }
    }
    return false;
}

void prt() {
    for(int i=0;i<N;i++) {
        for(int j=0;j<N;j++) {
            cout << map[i][j] << " ";
        }
        cout << endl;
    }
}
void movePeople(int areaSum,int cnt) {
    int val = areaSum / cnt;
    for(int i=0;i<v.size();i++) {
        int y = v[i].second.first;
        int x = v[i].second.second;
        map[y][x] = val;
    }
    v.clear();
    // prt();
}

void makeUnion() {
    int chk = 0;
    char group = 'A';
    for(int i=0;i<N;i++) {
        for(int j=0;j<N;j++) {
            int areaSum = map[i][j];
            int unionCnt = 1;
            if(!visit[i][j]) {
                visit[i][j] = true;
                q.push(make_pair(group++,make_pair(i,j)));
                v.push_back(make_pair(group++,make_pair(i,j)));
                while(!q.empty()) {
                    char g = q.front().first;
                    int y = q.front().second.first;
                    int x = q.front().second.second;
                    q.pop();
                    // cout << chk++ << ": " << y << "," <<  x << endl;
                    for(int k=0;k<4;k++) {
                        int ny = y + dirY[k];
                        int nx = x + dirX[k];
                        // 범위 내에 있고, L과 R의 조건을 만족한다면.. 방문처리하고 큐에 삽입.
                        if(ny >= 0 && ny < N && nx >= 0 && nx < N && !visit[ny][nx]) {
                            int n = abs(map[y][x] - map[ny][nx]);
                            if(n >= L && n <= R) {
                                visit[ny][nx] = true;
                                q.push(make_pair(g,make_pair(ny,nx)));
                                v.push_back(make_pair(g,make_pair(ny,nx)));
                                areaSum += map[ny][nx];
                                unionCnt++;
                            }
                        }
                    }
                }
                if(unionCnt == 1) {
                    visit[i][j] = false;
                    v.pop_back();
                }
                else movePeople(areaSum,unionCnt);
            }
        }
    }
}

void initVisit() {
    for(int i=0;i<N;i++) {
        for(int j=0;j<N;j++) {
            visit[i][j] = 0;
        }
    }
}
int main(int argc, char** argv)
{
	  

    input();
    result = 0;
    while(possi()) {
        // 모든 노드를 돌면서 연합을 만든다.
        initVisit();
        makeUnion();
        result++;
    }
    cout << result << endl;
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}