#include <string>
#include <vector>
#include <iostream>
using namespace std;


int solution(string s) {
    int answer = s.length();
    string answerStr = "";
    
    for(int cutCnt = 1; cutCnt < s.length(); cutCnt++) {
        int cnt = 1;
        // cout << "cutCnt = " << cutCnt << endl;
        for(int i=0;i<s.length()-cutCnt;i+=cutCnt) {
    
            if(i+2*cutCnt >= s.length()) {
                
                if(s.substr(i,cutCnt) == s.substr(i+cutCnt,cutCnt)) {
                    cnt++;
                    answerStr = answerStr + to_string(cnt) + s.substr(i,cutCnt);
                    
                }else {
                    if(cnt == 1) {
                        answerStr = answerStr + s.substr(i,cutCnt) + s.substr(i+cutCnt, cutCnt);
                        
                    }else {
                        answerStr = answerStr + to_string(cnt) + s.substr(i,cutCnt) + s.substr(i+cutCnt, cutCnt);
                        
                    }
                }
                // cout << answerStr << endl;
            } 
            else {
                // 시작점에서 잘린 cnt와 그 다음 범위가 같은지
                if(s.substr(i,cutCnt) == s.substr(i+cutCnt,cutCnt)) {
                    cnt++;
                }else {
                    if(cnt == 1) {
                        answerStr = answerStr + s.substr(i,cutCnt);
                        
                    }else {
                        answerStr = answerStr + to_string(cnt) + s.substr(i,cutCnt);
                        
                    }
                    // cout << answerStr << endl;
                    cnt = 1;
                }
            }            
        }

        if(answer > answerStr.length()) {
            answer = answerStr.length();
        }

        answerStr = "";
    }

    return answer;
}

/*

    1. 자를 개수를 1부터 s.length()만큼 돌면서 체크해줌.
    2. 

 */