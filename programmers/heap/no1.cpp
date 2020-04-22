#include <string>
#include <vector>
#include <queue>
using namespace std;

int solution(vector<int> scoville, int K) {
    int answer = 0;
    priority_queue<int, vector<int>, greater<int>> pq;

    for(int i=0; i<scoville.size(); i++) {
        pq.push(scoville[i]);
    }

    while(!pq.empty()) {
        int first = pq.top();
        if(first >= K) {
            break;
        }
        pq.pop();
        if(pq.empty()) {
            // 더이상 뺄게 없을 때.
            if(first < K) {
                answer = -1;
                break;
            } 
        } 
        int second = pq.top();
        pq.pop();
        int newNum = first + (second * 2);
        answer++;
        pq.push(newNum);
    }

    return answer;
}