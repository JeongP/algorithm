#include <iostream>
#include <string>
#include <vector>
using namespace std;

int N;
string s;
char S[10][10];
vector<int> v;
bool end;

void input() {
    cin >> N >> s;
    
    // S[i][j] 배열 채워 넣기.
    int idx = 0;
    for(int i=1;i<=N;i++) {
        for(int j=i;j<=N;j++) {
            S[i][j] = s[idx];
            idx++;
        }
    }
}

void prt() {
    for(int i=0;i<v.size();i++) {
        cout << v[i] << " ";
    }
}

int vecSum(int start,int end) {
    int sum = 0;
    for(int i=start-1;i<end;i++) {
        sum += v[i];
    }
    return sum;
}

void dfs(int depth) {

    // 리턴 조건.
    if(depth == N) {
        prt();
        exit(0);
    }

    // 각 수에 대해서 (1,depth+1) ~ (depth+1, depth+1)까지 문제에서 주어진 조건 충족하는지 체크
    for(int i=-10;i<=10;i++) {

        // 조건카운팅 변수
        int condition_cnt = 0;
        for(int j=1;j<=depth+1;j++) {
            // 벡터에 있는 값들의 합 구하기.
            int vs = vecSum(j,depth);

            if(S[j][depth+1] == '+') {
                if(vs+i>0) {
                    condition_cnt++;
                }    
            }else if (S[j][depth+1] == '-') {
                if(vs+i<0) {
                    condition_cnt++;
                }
            }else if (S[j][depth+1] == '0') {
                if(vs+i==0) {
                    condition_cnt++;
                }
            }
        }

        // 조건 카운팅 변수가 모든 조건을 만족한다면 벡터에 숫자를 추가하고 dfs 이어서 진행.
        if(condition_cnt == depth+1) {
            v.push_back(i);
            dfs(depth+1);
            v.pop_back();
        }
    }    
}

void sol() {
    // 시작 값 세팅.
    for(int i=-10;i<=10;i++) {
        if(S[1][1] == '+') {
            if(i>0) {
                v.push_back(i);
                dfs(1);
                v.pop_back();
            }
        } else if (S[1][1] == '-') {
            if(i<0) {
                v.push_back(i);
                dfs(1);
                v.pop_back();
            }
        } else if (S[1][1] == '0') {
            if(i==0) {
                v.push_back(i);
                dfs(1);
                v.pop_back();
            }
        }
    }
}

int main () {
    input();
    sol();
}