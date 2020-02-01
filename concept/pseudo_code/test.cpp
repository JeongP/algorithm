#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

void make_numbers(string s, int i, string s2) {
    // s2에 s[i] 더해줌.
    s2 += s[i];
    // 재귀 종료 조건.
    if(!s[i+1]) {
        // 벡터에 삽입한다.
        return;
    }
    
    for(int j=i+1;j<s.size();j++) {
        
        make_numbers(s, j, s2);
    }
    
}


int main () {
    string s = "1234";
    
    vector<string> v;
    // numbers에 입력된 문자열로 만들 수 있는 모든 경우의 수 만들기.
    for(int i=0;i<s.size();i++) {
        string s2 = "";
        make_numbers(s, i, s2);
    }

    // 소수체크
    for ( int i=0; i<v.size(); i++ ) {
        for(int j=0; j<stoi(v[i]); j++) {
            if(나누어 떨어지냐, 즉 소수가 아니라면) {
                break;
            }
        }
        // 소수가 아니라면 count ++;
    }

    // string의 첫 자리수가 0이라면 지워주는 과정 세팅
    for(벡터를 돌면서) {
        
    }
    // 
}