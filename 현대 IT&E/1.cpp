#include <vector>

using namespace std;

int dir[4][2] = {{1,0},{-1,0},{0,1},{0,-1}};

int solution(vector<vector<int> > maps){
    int answer = 0;
    int r = maps.size();
    int c = maps[0].size();
    
 
    // 모든 점에 대해 육지인 곳에서 4방향 체크.
    
    
    
    for(int i=0;i<r;i++) {
        for(int j=0;j<c;j++) {
            int cnt = 0;
            // 육지인 부분에 대해
            if(maps[i][j] == 1) {
                // 네 면 카운팅.
                for(int k=0;k<4;k++) {
                    int ny = i + dir[k][0];
                    int nx = j + dir[k][1];
                    
                    
                    if(ny < 0 || ny >= r || nx < 0 || nx >= c) {
                        answer++;
                    } else if(maps[ny][nx] == 0) {
                        answer++;
                    }
                }
                
            }
        }
    }
    
    return answer;
}