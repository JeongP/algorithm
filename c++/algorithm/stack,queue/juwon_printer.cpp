#include <string>
#include <vector>
#include <queue>
#include <iostream>

using namespace std;

int solution(vector<int> priorities, int location) {
    int answer = 0;
    queue<int> PQ;
    while(priorities.size() != 0){
        bool pb = false; // pushback 여부
        for(int j = 1; j < priorities.size() - 1; j ++){
            if(priorities[0] < priorities[j]){
                priorities.push_back(priorities[0]);
                priorities.erase(priorities.begin());
                pb = true;
                if(location == 0)
                    location += priorities.size() - 1;
                else
                    location--;
                break;
            }
        }
        if(pb == false){
            PQ.push(priorities[0]);
            priorities.erase(priorities.begin());
            if(location == 0){
                answer = PQ.size();
                location = -1;
            }
            location--;
        }
    }
    while(!PQ.empty()){
        PQ.pop();
    }
    
    return answer;
}