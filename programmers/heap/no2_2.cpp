#include <string>
#include <vector>
#include <queue>

using namespace std;

int solution(int stock, vector<int> dates, vector<int> supplies, int k) {
    int answer = 0;
    int start = 0;
    priority_queue<int, vector<int>, less<int>> pq;
    while(stock < k) {
        for(int i=start;i<dates.size();i++) {
            if(dates[i] < stock) {
                pq.push(supplies[i]);
            }else {
                start = i;
                break;
            }
        }

        stock += pq.top();
        answer++;
        while(!pq.empty()) {
            pq.pop();
        }
    }

    

    return answer;
}

/*

    while(stock < k) {
        
        for() {
            if: dates[i] < stock 인 i에 대해 supplies[i]를 pq에 담기.
            else: 시작 idx 바꿔주고 break;
        }
        
        stock += pq.top();
        pq 비우기.
        answer++

        

        
    }

 */