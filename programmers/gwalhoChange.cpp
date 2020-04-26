#include <string>
#include <vector>
#include <stack>
using namespace std;

bool isRight(string p) {
    stack<char> s;
    for(int i=0;i<p.length();i++) {
        if(p[i] == '(') {
            s.push(p[i]);
        }else {
            if(s.top() == '(') {
                s.pop();
            }else {
                s.push(p[i]);
            }
        }
    }
    if(s.empty()) return true;
    else return false;
}

bool isBalanced(string p) {
    int a=0, b=0;
    for(int i=0;i<p.length();i++) {
        if(p[i] == '(') a++;
        else b++;
    }
    if(a == b) return true;
    else return false;
}


string solution(string p) {
    string answer = "";
    
    // 올바른 괄호 문자열인지 체크
    if(isRight(p)) {
        return p;
    } else {
        // uv 로 나누고
    }


    
    




    return answer;
}