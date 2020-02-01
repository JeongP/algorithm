#include <iostream>
#include <vector>

using namespace std;

string num = "17";
int a = num.length();
bool visited[2];
vector<string> v;

bool isPrime(string s) {
    for(int i=2;i<s.length();i++) {
        if(stoi(s)%i==0) return 0;
    }
    v.push_back(s);
    return 1;
}

void dfs (string s) {
    // 대충 마지막 조건
    if(s.length()) return;
    for(int i=0;i<s.length();i++) {
        if(!visited[s[i]]) {
            visited[s[i]] = 1;
            // 문자열 더해줌.
            isPrime(더해진 문자열);
            dfs(s);
            visited[s[i]] = 0;
            v.pop_back();
        }
    }    
}

void processing_zero(vector<string> v) {
    for( int i=0; v.size(); i++) {
        // 벡터의 첫번째 원소가 영인지 체크
        if(v[i][0] == 0) {
            // 벡터의 첫번째 0 삭제
        }
    }
}

void distinct(vector<string> v) {
    for(int i=0; i<v.size();i++) {
        for(int j=i; j<v.size(); j++) {
            // 중복된 것이 잇다면 벡터에서 erase()
        }
    }
}

int main () {
    
    
    // 모든 경우에 수에 대해 소수 판별.
    // 소수인 경우에 대해 벡터에 삽입.
    // 앞자리 0인것 0제외 해주고
    // 중복처리
    
    
    dfs(num);
    processing_zero(v);
    distinct(v);

}

