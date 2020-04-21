#include <string>
#include <vector>
#include <queue>
using namespace std;

int solution(int bridge_length, int weight, vector<int> truck_weights) {
    int answer = 0;
    // 다리를 건너는 트럭을 표현해줄 v (무게와, 경과시간)
    // vector<pair<int,int>> v;
    queue<pair<int,int>> q;

    int idx =0;
    
    do {
        // 다리를 건너고 있는 트럭 중 타임오바 된 것 체크.
        int qsize = q.size();
        for(int i=0;i<qsize;i++) {
            int qf = q.front().first;
            int qs = q.front().second;
            q.pop();

            if(qs<bridge_length) {
                q.push(make_pair(qf,qs+1));
            } else {
                // 다리를 다 건넌 트럭이라면 가중 무게를 더해줌.
                weight += qf;
            }
        }

        // 다리가 다음 트럭의 무게를 견딜 수 있는지.
        if(idx < truck_weights.size()) {
            if(weight >= truck_weights[idx]) {
                weight -= truck_weights[idx];
                q.push(make_pair(truck_weights[idx],1));
                idx++;
            }
        }
        


        answer++;


    }while(!q.empty());


    return answer;
}