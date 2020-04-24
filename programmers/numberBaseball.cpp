#include <string>
#include <vector>
#include <iostream>
using namespace std;

int solution(vector<vector<int>> baseball) {
    int answer = 0;
    string num1 = "";
    string num2 = "";
    int strike = 0;
    int ball = 0;
    int condition = 0;
    for(int i=123;i<=987;i++) {
        num1 = to_string(i);
        if(num1[0] == num1[1] || num1[1] == num1[2] || num1[0] == num1[2]) continue;
        else if(num1[0] == '0' || num1[1] == '0' || num1[2] == '0') continue;

        condition = 0;
        
        
        for(int j=0;j<baseball.size();j++) {
            num2 = to_string(baseball[j][0]);
            ball = 0;
            strike = 0;
            for(int a=0;a<3;a++) {
                for(int b=0;b<3;b++) {
                    if(num1[a] == num2[b] && a == b) {
                        strike++;
                        continue;
                    }
                    if(a!=b && num1[a] == num2[b]) {
                        ball++;
                        continue;
                    }
                }
            }
            if(strike == baseball[j][1] && ball == baseball[j][2]) {
                condition++;
            }
        }
        
        if(condition == baseball.size()) {
            
            answer++;
        }
        
    }
    
    return answer;
}