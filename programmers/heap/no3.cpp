#include <string>
#include <vector>
#include <queue>
using namespace std;

int solution(vector<vector<int>> jobs) {
    int answer = 0;
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
    
    for(int i=0;i<jobs.size();i++) {
        pq.push(make_pair(jobs[i][1], jobs[i][0]));    
    }

    // 첫 작업 실행.
    int entranceTime = jobs[0][0];
    int idx = 0;
    for(int i=1;i<jobs.size();i++) {
        
        if(entranceTime > jobs[i][0]) {
            idx = i;
            entranceTime = jobs[i][0];
        }
    }
    answer = jobs[idx][1];
    int finishTime = entranceTime + jobs[idx][1];
    pq.pop();

    while(!pq.empty()) {
        
        int workTime = pq.top().first;
        entranceTime = pq.top().second;
        int watiingTime = finishTime - entranceTime;
        pq.pop();
        
        finishTime += workTime;
        int processTime = finishTime - entranceTime;
        answer += processTime;        
    }

    answer /= jobs.size();
    return answer;
}

/*
    1. 처음 들어온 작업 수행.
    2. 다음 부터는 짧은 작업부터 수행. (대기시간을 최소화 하겠다.)
    

 */