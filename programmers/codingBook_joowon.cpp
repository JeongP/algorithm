#include <vector>
#include <iostream>

using namespace std;

// 전역 변수를 정의할 경우 함수 내에 초기화 코드를 꼭 작성해주세요.

int visit[100][100];
int map[100][100];
int number_of_area; //몇개영역
int max_size_of_one_area;   //가장큰영역
int dx[] = {-1, 0, 1, 0};
int dy[] = {0, 1, 0, -1};
int m, n;
bool chk = false;
int cnt = 0;

void dfs(int x, int y){
    if(visit[x][y] != 0 || map[x][y] == 0)
        return;
    
    visit[x][y] = 1;
    cnt++;  // 몇개?
    for(int i = 0; i < 4; i++){
        int nx = x + dx[i];
        int ny = y + dy[i];
        if(nx >= 0 && nx < m && ny >= 0 && ny < n){
            if(map[nx][ny] != 0 && visit[nx][ny] == 0){
                if(map[nx][ny] == map[x][y]){   // 같은 숫자인 경우에만
                    if(chk == false){   //처음이었으면
                        number_of_area++;
                    }
                    chk = true; // 처음이 아님으로 유지
                    dfs(nx, ny);
                }
            }
        }
    }
}

vector<int> solution(int x, int y, vector<vector<int>> picture) {
    number_of_area = 0; //몇개영역
    max_size_of_one_area = 0;   //가장큰영역  
    m = x;
    n = y;
    for(int i = 0; i < m; i++)
        for(int j = 0; j < n; j++){
            visit[i][j] = 0;
            map[i][j] = 0;
        }
        
    dx[0] = -1;
    dy[0] = 0;
    chk = false;
    cnt = 0;
    
    for(vector<int>::size_type i = 0; i < picture.size(); i++){
        for(vector<int>::size_type j = 0; j < picture[i].size(); j++){
            map[i][j] = picture[i][j];
        }
    }
    
    
    for(int i = 0; i < m; i++)
        for(int j = 0; j < n; j++){
            cnt = 0;
            chk = false;    // case : 처음이면 false
            dfs(i, j);
            if(cnt == 1){   // 상하좌우 x
                cnt = 0;
                number_of_area--;
            }
           // cout << cnt;
            if(max_size_of_one_area < cnt)  // 다 돌고 나왔을 때
                max_size_of_one_area = cnt;
        }
    
   /* cout << endl;
    for(int i = 0; i < m; i++){
        for(int j = 0; j < n; j++){
            cout << visit[i][j] << " ";
        }
        cout << endl;
    }*/
    
    vector<int> answer(2);
    answer[0] = number_of_area;
    answer[1] = max_size_of_one_area;
    return answer;
}