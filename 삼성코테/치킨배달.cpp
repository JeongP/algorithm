
#include<iostream>
#include<vector>
#include<cstdio>
using namespace std;

int N,M;
vector<pair<int,int>> v;
vector<pair<int,int>> house;
int map[51][51] = {0,};
bool visit[14] = {0,};
int result = 987654321;

void input() {
    cin >> N >> M;
    for(int i=0;i<N;i++) {
        for(int j=0;j<N;j++) {
            cin >> map[i][j];
            // 치킨집의 경우
            if(map[i][j] == 2) {
                v.push_back(make_pair(i,j));
                map[i][j] = 0;
            }
            if(map[i][j] == 1) {
                house.push_back(make_pair(i,j));
            }
        }
    }
}

void prt() {
    for(int i=0;i<N;i++) {
        for(int j=0;j<N;j++) {
            cout << map[i][j] << " ";
        }
        cout << endl;
    }
}

void chickenDistance() {
    
    vector<pair<int,int>> hopIdx;
    int chk_dis = 0;
    // 치킨 집 세팅.
    for(int i=0;i<v.size();i++) {
        if(visit[i]) {
            int y = v[i].first;
            int x = v[i].second;
            map[y][x] = 2;
            hopIdx.push_back(make_pair(y,x));
        }
    }


    for(int i=0;i<house.size();i++) {
        int houseToHop = 987654321;
        int hx = house[i].second;
        int hy = house[i].first;
        for(int j=0;j<hopIdx.size();j++) {
            int cy = hopIdx[j].first;
            int cx = hopIdx[j].second;
            int sero = 0; int garo = 0;
            if(hy >= cy) sero = hy - cy;
            else if(hy < cy) sero = cy - hy;
            if(hx >= cx) garo = hx - cx;
            else if(hx < cx) garo = cx - hx;
            if(houseToHop > sero + garo) houseToHop = sero + garo;
        }
        // cout << houseToHop << " ";
        chk_dis += houseToHop;
    }
    // cout << endl;
    // prt();
    // cout << endl;
    // 치킨 집 세팅 해제
    for(int i=0;i<hopIdx.size();i++) {
        map[hopIdx[i].first][hopIdx[i].second] = 0;
    }
    // 치킨 거리 비교
    if(result > chk_dis) result = chk_dis;
    // cout << result << endl;
}


void select(int cnt) {
    if(cnt == M) {
        chickenDistance();
        // cout << endl;
        // prt();
        // exit(0);
        return;
    }

    for(int i=0;i<v.size();i++) {
        if(!visit[i]) {
            visit[i] = true;
            select(cnt+1);
            visit[i] = false;
        }
    }
}

void init() {
    v.clear();
    for(int i=0;i<14;i++) {
        visit[i] = false;
    }
    result = 987654321;
}

int main(int argc, char** argv)
{
	int test_case;
	int T = 1;
	
	// freopen("input.txt", "r", stdin);
	// cin>>T;
    
	for(test_case = 1; test_case <= T; ++test_case)
	{   
        // init();
        input();
        select(0);
        cout << result << endl;
        // cout << "#" << test_case << " " << result << endl;
	}
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}