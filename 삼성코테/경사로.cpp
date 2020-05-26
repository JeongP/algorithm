#include <iostream>

using namespace std;

int N,L;
int map[101][101] = {0,};
bool visit[101][101] = {0,};
int result = 0;
bool flag = false;
bool possi = true;

void input() {
    cin >> N >> L;
    for(int i=0;i<N;i++) {
        for(int j=0;j<N;j++) {
            cin >> map[i][j];
        }
    }
}

void findGaro(int idx) {
    int start = map[idx][0];

    for(int i=1;i<N;i++) {
        // 다음 녀석이 1 큰 경우
        if(start == map[idx][i] - 1) {
            for(int j=i-1; j>=i-L;j--) {
                if(j<0) {flag = true; break;}
                if(visit[idx][j]) {flag = true; break;}
                if(map[idx][i-1] != map[idx][j]) {flag = true; break;}
            }

            if(flag) {
                possi = false;
                break;
            }
            // 경사로를 둘 수 있는 경우 
            else {
                for(int j=i-1; j>=i-L;j--) {
                    visit[idx][j] = true;
                }
                start = map[idx][i];
            }
            
        }
        // 다음 녀석이 1 작은 경우.
        else if(start == map[idx][i] + 1) {
            // 경사로 놓을 수 있는지 체크
            for(int j=i;j<i+L;j++) {
                // j의 범위가 판을 넘어가거나
                if(j>=N) {flag = true; break;}
                if(visit[idx][i]) {flag = true; break;}
                // 값이 달라 경사로를 놓을 수 없다면.
                if(map[idx][i] != map[idx][j]) {flag = true; break;}
            }
            
            // 길 생성 불가.
            if(flag) {
                possi = false;
                break;
            }
            else {
                for(int j=i;j<i+L;j++) {
                    visit[idx][j] = true;
                }
                 // 경사로 끝점으로 i 값 이동.
                i = i+L-1;
                start = map[idx][i];
            }
           
        }
        // 같은 경우 
        else if(start == map[idx][i]){
            start = map[idx][i];
        } 
        
        else {
            possi = false;
            break;    
        }
    }

    // 길 만들 수 있으면 result ++;
    if(possi) {
        result++;
    } else {
        possi = true;
        flag = false;
    }
}

void findSero(int idx) {
    int start = map[0][idx];

    for(int i=1;i<N;i++) {
        // 다음 녀석이 1 큰 경우
        if(start == map[i][idx] - 1) {
            for(int j=i-1; j>=i-L;j--) {
                if(j<0) {flag = true; break;}
                if(visit[j][idx]) {flag = true; break;}
                if(map[i-1][idx] != map[j][idx]) {flag = true; break;}
            }

            if(flag) {
                possi = false;
                break;
            }
            else {
                for(int j=i-1; j>=i-L;j--) {
                    visit[j][idx] = true;
                }
                start = map[i][idx];
            }
            
        }
        // 다음 녀석이 1 작은 경우.
        else if(start == map[i][idx] + 1) {
            // 경사로 놓을 수 있는지 체크
            for(int j=i;j<i+L;j++) {
                // j의 범위가 판을 넘어가거나
                if(j>=N) {flag = true; break;}
                if(visit[j][idx]) {flag = true; break;}
                // 값이 달라 경사로를 놓을 수 없다면.
                if(map[i][idx] != map[j][idx]) {flag = true; break;}
            }
            
            // 길 생성 불가.
            if(flag) {
                possi = false;
                break;
            }
            else {
                for(int j=i;j<i+L;j++) {
                    visit[j][idx] = true;
                }
                // 경사로 끝점으로 i 값 이동.
                i = i+L-1;
                start = map[i][idx];
            }
            
        }
        // 같은 경우 
        else if(start == map[i][idx]){
            start = map[i][idx];
        } 
        
        else {
            possi = false;
            break;    
        }
    }

    // 길 만들 수 있으면 result ++;
    if(possi) {
        result++;
    } else {
        possi = true;
        flag = false;
    }
}

void initMap() {
    for(int i=0;i<N;i++) {
        for(int j=0;j<N;j++) {
            visit[i][j] = false;
        }
    }
}
void solution() {
    for(int i=0;i<N;i++) {
        findGaro(i);
        // cout << result << endl;
    }
    
    initMap();
    for(int i=0;i<N;i++) {
        findSero(i);
    }
    
}

int main () {
    input();
    solution();
    cout << result << endl;
}