#include <string>
#include <vector>
#include <queue>
using namespace std;

vector<int> solution(vector<int> progresses, vector<int> speeds) {
    // 배포 일정을 담은 벡터
    vector<int> answer;
    queue<int> q;
    int deploy_cnt;

    // 업무 완료에 걸리는 day를 큐에 담아주기.
    for(int i=0;i<progresses.size();i++) {
        int day = 0;
        int finish_work = progresses[i];
        while(finish_work < 100) {
            finish_work += speeds[i];
            day++;
        }
        q.push(day);
    }

    while(!q.empty()) {
        
        int worktime = q.front();
        deploy_cnt = 1;
        q.pop();

        while(!q.empty()) {
            if(worktime >= q.front()) {
                deploy_cnt++;
                q.pop();
            }else {
                break;
            }
        }

        answer.push_back(deploy_cnt);

    }
    return answer;
}