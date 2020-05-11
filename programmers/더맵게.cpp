#include <string>
#include <vector>
#include <queue>
using namespace std;

int solution(vector<int> scoville, int K) {
    int answer = 0;
    priority_queue<int, vector<int>, greater<int>> q;

    while(q.top() < K) {
        if(q.size() == 1) return answer = -1;
        int first = q.top(); q.pop();
        int second = q.top(); q.pop();
        q.push(first + second*2);
        answer++;
    }
    return answer;
}