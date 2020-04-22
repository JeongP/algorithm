#include <string>
#include <vector>
#include <queue>
using namespace std;

int solution(string arrangement) {
    int answer = 0;
    bool laser = false;
    queue<char> q;
    int stick = 0;

    for(int i=0;i<arrangement.length();i++) {
        q.push(arrangement[i]);
    }

    while(!q.empty()) {
        char x = q.front();
        q.pop();
        if(x == '(') {
            stick++;
            laser = false;
            answer++;
            
        } else if( x == ')') {
            if(laser == false) {
                answer--;
                laser = true;
                stick--;
                answer += stick;
            } else {
                stick--;
            }
        }
    }
    return answer;
}


/*

    1. 큐에 입력받은 string을 char 형으로 넣는다.
    2. 큐가 빌 때까지 반복.
    3. 앞원소를 빼내서 '('라면 stick++, laser = false 로
    4. ')'라면 stick--해주고 laser가 false일 때만 stick 수만큼 answer에 더해주고 laser를 true로

 */