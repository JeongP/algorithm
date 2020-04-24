#include <vector>
#include <queue>
#include <iostream>
using namespace std;

// 전역 변수를 정의할 경우 함수 내에 초기화 코드를 꼭 작성해주세요.
vector<int> solution(int m, int n, vector<vector<int>> picture) {
    int number_of_area = 0;
    int max_size_of_one_area = 0;
    queue<pair<int,int>> q;
    bool visit[101][101] = {0,};
    int dir[4][2] = {{1,0}, {-1,0}, {0,1}, {0,-1}};
    int areaSize = 0;
    

    for(int i=0;i<m;i++) {
        for(int j=0;j<n;j++) {
            // 방문했다면
            if(visit[i][j] || picture[i][j] == 0) continue;
            // 0이 아닌경우
            if(picture[i][j] != 0 && !visit[i][j]) {
                visit[i][j] = true;
                q.push(make_pair(j,i));
                areaSize = 1;
                while(!q.empty()) {
                    int x = q.front().first;
                    int y = q.front().second;
                    q.pop();
                    for(int k=0;k<4;k++) {
                        int nx = x + dir[k][0];
                        int ny = y + dir[k][1];
                        
                        if(0<=ny && ny < m && 0<=nx && nx < n){
                            if(!visit[ny][nx] && picture[ny][nx] == picture[y][x]) {
                                areaSize++;
                                visit[ny][nx] = true;
                                q.push(make_pair(nx,ny));
                            }
                        }
                        
                    }
                }
                number_of_area++;
            }
            // find MaxSizeOfArea
            if(max_size_of_one_area < areaSize) {
                // cout << areaSize << " ";
                max_size_of_one_area = areaSize;
            }
        }
    }

    
    vector<int> answer(2);
    answer[0] = number_of_area;
    answer[1] = max_size_of_one_area;

    return answer;
}