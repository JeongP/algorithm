#include <iostream>
#include <algorithm>
#include <cstdlib>
#include <vector>
using namespace std;

int N, M, D;
int map[17][16];
int originMap[17][16];
bool exist[5];
int answer = 0;
vector<pair<int,int>> attackList;
int result = 0;
int chk = 1;


void input() {
    cin >> N >> M >> D;
    for(int i=0;i<N;i++) {
        for(int j=0;j<M;j++) {
            cin >> map[i][j];
        }
    }

    for(int i=0;i<N;i++) {
        for(int j=0;j<M;j++) {
            originMap[i][j] = map[i][j];
        }
    }

}


void selectEnermy(int archer_idx) {
    
    // measureTarget(archer_idx);
    int minDistance = 100;
    int x=5,y;
    // 사거리에 닿는 녀석들 중, 최소값에 대한 idx 구하기.

    for(int a=N-1;a>=0;a--) {
        // cout << i << endl;
        for(int b=0;b<M;b++) {
            // 적이 있다면?
            // cout << map[a][b] << " ";
            if(map[a][b] == 1) {
                int distance = abs(N-a) + abs(archer_idx - b);
                // cout << distance << " ";
                if(minDistance >= distance) {
                    if(minDistance == distance) {
                        if(x>b) {
                            minDistance = distance;
                            x = b; y = a;
                        }
                    }else {
                        minDistance = distance;
                        x = b; y = a;
                    }
                    
                }
            }
        }
    }

    if(D >= minDistance) {
        // 공격 대상 리스트업
        // cout << y << " " << x << endl;
        attackList.push_back(make_pair(y,x));
    }
    
}

void attack() {
    while(!attackList.empty()) {
        int y = attackList.back().first;
        int x = attackList.back().second;
        attackList.pop_back();
        if(map[y][x] != 0) {
            map[y][x] = 0;
            result++;
        }
    }
    
}

void moveEnermy() {
    
    for(int i=N-2;i>=0;i--) {
        for(int j=0;j<M;j++) {
            map[i+1][j] = map[i][j];
        }
    }

    for(int i=0;i<M;i++) {
        map[0][i] = 0;
    }

}

void prt() {
    for(int i=0;i<attackList.size();i++) {
        cout << attackList[i].first << " " << attackList[i].second << endl;
    }
}

bool endCondition() {
    for(int i=0;i<N;i++) {
        for(int j=0;j<M;j++) {
            if(map[i][j] == 1) return false;
        }
    }
    return true;
}


int startGame() {

    result = 0;
    int t = N;
    while(t--) {
        //map 다 0일 때.
        if(endCondition()) {
            return result;
        }
        // 궁수 한 명씩 공격.
        for(int i=0;i<5;i++) {
            // 궁수 있을 때
            if(exist[i]) {
                // 공격 대상 선택
                // cout << chk << endl;
                selectEnermy(i);
                // cout << i << " ";
            }
            
        }
        
        // prt();
        attack();
        moveEnermy();
        
    }
    
    return result;
}

void init_map() {
    for(int i=0;i<N;i++) {
        for(int j=0;j<M;j++) {
            map[i][j] = originMap[i][j];
        }
    }
}

void alignment(int depth) {

    // 배치가 완료되면 게임 시작.
    if(depth == 3) {
        answer = max(answer,startGame());
        init_map();
        return;
    }

    for(int i=0;i<5;i++) {
        if(!exist[i]) {
            exist[i] = true;
            alignment(depth+1);
            exist[i] = false;
        }
    }
}


int main () {
    input();
    // 각 궁수 배치.
    alignment(0);
    cout << answer << endl;
}


/*

    1. 궁수 자리 세팅.
    1-1. 
    2. 각 세팅에 대해 적진이 성에 도착할 떄 까지 반복.
    3. 궁수 한 명씩 공격.
    4. 적들 한 칸씩 이동.
    5. 모든 적들 제외 됐을 때, 최대값 비교

 */