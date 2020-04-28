#include <string>
#include <vector>

using namespace std;


int solution(string s) {
    int answer = s.length();
    string answerStr = "";
      
    for(int cutCnt=1;cutCnt<s.length();cutCnt++) {
        int result = 0;
        int cnt = 1;
        for(int i=0;i<s.length()-cutCnt;i+=cutCnt) {
            if(s.substr(i,i+cutCnt) == s.substr(i+cutCnt, 2*cutCnt)) {
                cnt++;
            }else {
                if(cnt == 1) {
                    answerStr += s.substr(i,cutCnt);
                }else {
                    answerStr = answerStr + to_string(cnt) + s.substr(i,cutCnt);
                }
                
            }
        }
        result = answerStr.length();
        if(result < answer) {
            answer = result;
        }
    }
    return answer;
}

/*

    1. 자를 개수를 1부터 s.length()만큼 돌면서 체크해줌.
    2. 

 */