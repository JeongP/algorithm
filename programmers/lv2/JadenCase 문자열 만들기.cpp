#include <string>
#include <vector>
#include <iostream>
using namespace std;

string solution(string s) {
    string answer = "";
    
    for(int i=0;i<s.length();i++) {
        char tmp = s[i];
        // 첫 번째 철자 대문자로
        if(i == 0 || s[i-1] == ' ') {
            if(s[i] >= 'a' && s[i] <= 'z') {
                tmp = char(s[i]-32);
                // cout << char(s[i] - 32) << " ";
            } 
        }
        
        // 이외 문자는 대문자를 소문자로
        else {
            if(s[i] >= 'A' && s[i] <= 'Z') {
                tmp = char(s[i]+32);
            } 
        }
        answer += tmp;
    }
    
    return answer;
}