#include <string>
#include <vector>
#include <queue>

using namespace std;

int solution(vector<int> priorities, int location) {
    int answer = 0;
    queue<pair<int,int>> q;
    priority_queue<int> pq;
    queue<pair<int,int>> answer_q;
    
    // qA => 입력값의 인덱스와 벨류로 이루어진 큐
    for(int i=0; i<priorities.size(); i++) {
        q.push(pair<int,int>(i, priorities[i]));
        pq.push(priorities[i]);
    }
    
    while(!q.empty()) {
        if(q.front().second == pq.top()) {
            answer_q.push(make_pair(q.front().first,q.front().second));
            q.pop();
            pq.pop();
        } else {
            int n = q.front().first;
            int v = q.front().second;
            q.pop();
            q.push(make_pair(n,v));
        }
    }
    
    int count =1;
    while(!answer_q.empty()) {
        if(answer_q.front().first == location) {
            answer = count;
            break;
        } else {
            answer_q.pop();
        }
        count++;
    }
    
    return answer;
}