#include <string>
#include <vector>
#include <iostream>

using namespace std;

bool isBalance(string str){
    int tmp1 = 0;
    int tmp2 = 0;
    for(int i = 0; i < str.length(); i++){
        if(str[i] == '(')
            tmp1++;
        else    // ')'
            tmp2++;
    }
    if(tmp1 == tmp2)
        return true;
    else
        return false;    
}

bool isCorrect(string str){
    int tmp = 0;
    for(int i = 0; i < str.length(); i++){
        if(tmp < 0) // e.g ())
            return false;
        if(str[i] == '(')
            tmp++;
        else
            tmp--;
    }
    if(tmp == 0)
        return true;
    else    // ( 남은경우
        return false;
}

string solve(string w){
    int len = w.length();
    for(int i = 1; i <= len; i++){
        string u = w.substr(0, i);// 0~ i
        string v = "";
        if(i != len)    // 이부분 처리 안하면 segment 에러
            v = w.substr(i); // i~end
        
        if(isBalance(u) && isBalance(v)){   // 둘다 균형이라면 분리.
            string tmp = "";
            if(isCorrect(u)){   //올바르다면
                tmp = solve(v);
                u += tmp;
                return u;
            }
            else{
                tmp += '(';
                tmp += solve(v);
                tmp += ')';
                u = u.substr(1, u.length() - 2);    // begin end 제거
                for(int j = 0; j < u.length(); j++){   // 뒤집기
                    if(u[j] == '(')
                        u[j] = ')';
                    else
                        u[j] = '(';
                }
                tmp += u;
                return tmp;
            }
        }
    }
    return w;
}

string solution(string p) {
    string answer = "";
    if(p.length() == 0) // 빈문자열
        return answer;
    answer = solve(p);
    
    return answer;
}