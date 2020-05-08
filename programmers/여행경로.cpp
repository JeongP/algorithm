#include <string>
#include <vector>
#include <map>
using namespace std;

vector<vector<string>> paths;
vector<string> path;
vector<string> answer;
void DFS(string start, string end, int moveCnt, vector<vector<string>> tickets) {

    if(moveCnt == tickets.size()) {
        // 완성 경로에 추가
        path.push_back(end);
        answer = path;
        return;
    }

    for(int i=0;i<tickets.size();i++) {
        if(end == tickets[i][0]) {
            path.push_back(tickets[i][0]);
            DFS(tickets[i][0], tickets[i][1], moveCnt+1,tickets);
            path.pop_back();
        }
    }
}


vector<string> solution(vector<vector<string>> tickets) {
    
    for(int i=0;i<1;i++) {
        
        if(tickets[i][0] == "ICN") {
            path.push_back(tickets[i][0]);
            DFS(tickets[i][0], tickets[i][1], 1, tickets);
            path.pop_back();
        }
    }

    
    return answer;
}

/*

    총 공항 수  =  tickets.size() + 1
    moveCnt;
    bool visit;
    갈 수 있는 경로를 담을 이차원 벡터.

 */