/*
	1. 맵 입력 받을 때, 방문x, 시작점, 끝점 처리
    2. 가로선 두고
    3. 사다리 조작이 잘 되었는지  
*/
#include<iostream>

using namespace std;

int N,M,H;
int map[31][11] = {0,};
int result = 4;
int cnt = 3;

void input() {
    cin >> N >> M >> H;
	// map 처리 0: 방문x , 1: 시작점, 2: 끝점
    for(int i=0;i<M;i++) {
   		int a, b;
        cin >> a >> b;
       	map[a-1][b-1] = 1;
        map[a-1][b] = 2;
    }
}

void goGame(int sadariCnt) {
    for(int i=0;i<N;i++) {
        int idx = i;
        int n = 0;
        while(n<H) {
			// 양 옆으로 갈 곳이 없다면
            if(map[n][idx] == 0) {
            	n++;
                continue;
            }
            // 방향결정
            else if(map[n][idx] == 1) idx++; // 오른쪽으로 이동
            else idx--;            		    // 왼쪽으로 이동
            n++;
        }
        // idx의 위치 확인
        if(idx != i) return;
    }
    // 모두 같은 경우
    if(result > sadariCnt) result = sadariCnt;
}

void setting(int sadariCnt, int num) {
    if(sadariCnt == num) {
		goGame(sadariCnt);
        return;
    }
    
    // 가로선 두기.
    for(int i=0;i<H;i++) {
        for(int j=0;j<N-1;j++) {
            if(map[i][j] == 0 && map[i][j+1] == 0) {
                map[i][j] = 1; map[i][j+1] = 2;
                setting(sadariCnt, num+1);
                map[i][j] = 0; map[i][j+1] = 0;
            }
        }
    }
}

void solution() {
	int sadariCnt = 0;
    while(sadariCnt <= cnt) {
     	setting(sadariCnt,0);
        sadariCnt++;
    }
    if(result == 4) {
    	result = -1;
    }
}


int main(int argc, char** argv)
{
    input();
    if(M == 0) result = 0;
    else solution();
    cout << result << endl;

	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}

