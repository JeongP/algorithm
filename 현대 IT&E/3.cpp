#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

const int MAX = 5;
int directions[6];
int copyMap[MAX][MAX];
int map[MAX][MAX];
int bSize = 4;
int result = 0;


void moveUp() {
    for(int i=0;i<bSize-1;i++) {
        for(int j=0;j<bSize;j++) {
            bool check = false;
            // 옮길 수 있다면
            if(copyMap[i][j] == 0) {
                int k = i + 1;
                // 옮길 수 있는 만큼 계속 옮기고
                while(k<=bSize-1) {
                    if(copyMap[k][j] != 0) {
                        check = true;
                        break;
                    }
                    k++;
                }
                
                if(check) {
                    copyMap[i][j] = copyMap[k][j];
                    copyMap[k][j] = 0;
                }
            }
        }
    }
    
    // 합칠 수 있는거 합쳐주기
    for(int i=0;i<bSize-1;i++) {
        for(int j=0;j<bSize;j++) {
            if(copyMap[i][j] == copyMap[i+1][j]) {
                copyMap[i][j] = copyMap[i][j] * 2;
                copyMap[i+1][j] = 0;
            }
        }
    }
    
    // 합친 이후 빈 자리 채워서 넣어주기
    for(int i=0;i<bSize-1;i++) {
        for(int j=0;j<bSize;j++) {
            bool check = false;
            // 옮길 수 있다면
            if(copyMap[i][j] == 0) {
                int k = i + 1;
                // 옮길 수 있는 만큼 계속 옮기고
                while(k<=bSize-1) {
                    if(copyMap[k][j] != 0) {
                        check = true;
                        break;
                    }
                    k++;
                }
                
                if(check) {
                    copyMap[i][j] = copyMap[k][j];
                    copyMap[k][j] = 0;
                }
            }
        }
    }
}

void moveDown() {
    for(int i=bSize-1;i>0;i--) {
        for(int j=0;j<bSize;j++) {
            bool check = false;
            // 옮길 수 있다면
            if(copyMap[i][j] == 0) {
                int k = i - 1;
                // 옮길 수 있는 만큼 계속 옮기고
                while(k>=0) {
                    if(copyMap[k][j] != 0) {
                        check = true;
                        break;
                    }
                    k--;
                }
                
                if(check) {
                    copyMap[i][j] = copyMap[k][j];
                    copyMap[k][j] = 0;
                }
            }
        }
    }
    
    // 합칠 수 있는거 합쳐주기
    for(int i=bSize-1;i>0;i--) {
        for(int j=0;j<bSize;j++) {
            if(copyMap[i-1][j] == copyMap[i][j]) {
                copyMap[i][j] = copyMap[i][j] * 2;
                copyMap[i-1][j] = 0;
            }
        }
    }
    
    for(int i=bSize-1;i>0;i--) {
        for(int j=0;j<bSize;j++) {
            bool check = false;
            // 옮길 수 있다면
            if(copyMap[i][j] == 0) {
                int k = i - 1;
                // 옮길 수 있는 만큼 계속 옮기고
                while(k>=0) {
                    if(copyMap[k][j] != 0) {
                        check = true;
                        break;
                    }
                    k--;
                }
                
                if(check) {
                    copyMap[i][j] = copyMap[k][j];
                    copyMap[k][j] = 0;
                }
            }
        }
    }
}

void moveLeft() {
    for(int i=0;i<bSize;i++) {
        for(int j=0;j<bSize-1;j++) {
            bool check = false;
            // 옮길 수 있다면
            if(copyMap[i][j] == 0) {
                int k = j + 1;
                // 옮길 수 있는 만큼 계속 옮기고
                while(k<=bSize-1) {
                    if(copyMap[i][k] != 0) {
                        check = true;
                        break;
                    }
                    k++;
                }
                
                if(check) {
                    copyMap[i][j] = copyMap[i][k];
                    copyMap[i][k] = 0;
                }
            }
        }
    }
    
    // 합칠 수 있는거 합쳐주기
    for(int i=0;i<bSize;i++) {
        for(int j=0;j<bSize-1;j++) {
            if(copyMap[i][j] == copyMap[i][j+1]) {
                copyMap[i][j] = copyMap[i][j] * 2;
                copyMap[i][j+1] = 0;
            }
        }
    }
    
    // 합친 이후 빈 자리 채워서 넣어주기
    for(int i=0;i<bSize;i++) {
        for(int j=0;j<bSize-1;j++) {
            bool check = false;
            // 옮길 수 있다면
            if(copyMap[i][j] == 0) {
                int k = j + 1;
                // 옮길 수 있는 만큼 계속 옮기고
                while(k<=bSize-1) {
                    if(copyMap[i][k] != 0) {
                        check = true;
                        break;
                    }
                    k++;
                }
                
                if(check) {
                    copyMap[i][j] = copyMap[i][k];
                    copyMap[i][k] = 0;
                }
            }
        }
    }
}

void moveRight() {
    for(int i=0;i<bSize;i++) {
        for(int j=bSize-1;j>0;j--) {
            bool check = false;
            // 옮길 수 있다면
            if(copyMap[i][j] == 0) {
                int k = j - 1;
                // 옮길 수 있는 만큼 계속 옮기고
                while(k>=0) {
                    if(copyMap[i][k] != 0) {
                        check = true;
                        break;
                    }
                    k--;
                }
                
                if(check) {
                    copyMap[i][j] = copyMap[i][k];
                    copyMap[i][k] = 0;
                }
            }
        }
    }
    
    // 합칠 수 있는거 합쳐주기
    for(int i=0;i<bSize;i++) {
        for(int j=bSize-1;j>0;j--) {
            if(copyMap[i][j] == copyMap[i][j-1]) {
                copyMap[i][j] = copyMap[i][j] * 2;
                copyMap[i][j-1] = 0;
            }
        }
    }
    
    // 합친 이후 빈 자리 채워서 넣어주기
    for(int i=0;i<bSize;i++) {
        for(int j=bSize-1;j>0;j--) {
            bool check = false;
            // 옮길 수 있다면
            if(copyMap[i][j] == 0) {
                int k = j - 1;
                // 옮길 수 있는 만큼 계속 옮기고
                while(k>=0) {
                    if(copyMap[i][k] != 0) {
                        check = true;
                        break;
                    }
                    k--;
                }
                
                if(check) {
                    copyMap[i][j] = copyMap[i][k];
                    copyMap[i][k] = 0;
                }
            }
        }
    }
}



int findMax() {
    int maxValue = 0;
    for(int i=0;i<bSize;i++) {
        for(int j=0;j<bSize;j++) {
            if(copyMap[i][j] > maxValue) {
                maxValue = copyMap[i][j];
            }
        }
    }
    return maxValue;
}


void playGame() {
    
    // 방향 배열에 대해 이동.
    for(int i=0;i<5;i++) {
        int dir = directions[i];
        if(dir == 0) moveUp();
        else if(dir == 1) moveDown();
        else if(dir == 2) moveLeft();
        else if(dir == 3) moveRight();
    }
    
    int n = findMax();
    result = max(result, n);
}

void choiceDirection(int cnt) {
    // 방향 5개 모두 선택
    if(cnt == 5) {
        // 게임에 사용할 맵 복사
        for(int i=0;i<bSize;i++) {
            for(int j=0;j<bSize;j++) {
                copyMap[i][j] = map[i][j];
            }
        }
        playGame();
        return;
    }
    
    for(int i=0;i<4;i++) {
        directions[cnt] = i;
        choiceDirection(cnt+1);
    }
}

int solution(vector<vector<int>> board)
{
	int answer = -1;
    
    // map 전역변수로.
    for(int i=0;i<bSize;i++) {
        for(int j=0;j<bSize;j++) {
            map[i][j] = board[i][j];
        }
    }
    
    // 이동할 방향 선택해주기.
    choiceDirection(0);
    
    answer = result;
	return answer;
}