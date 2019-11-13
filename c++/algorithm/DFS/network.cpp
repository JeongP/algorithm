#include <string>
#include <vector>

using namespace std;

int cnt = 0;
bool check[201];
void DFS(vector<vector<int>> computers, int k) {
    for(int i=0; i<computers[k].size(); i++) {
        if(computers[k][i] == 1) {
            if(!check[i]) {
                if(k==i) {
                
                } else {
                    check[i] = true;
                    DFS(computers, i);
                }
            }
            
        }
    }
}

int solution(int n, vector<vector<int>> computers) {
    int answer = 0;
    
    for(int i=0; i<n; i++) {
        if(!check[i]){
            check[i] = true;
            cnt++;
            DFS(computers, i);
        }
    }
    
    answer = cnt;
    return answer;
}