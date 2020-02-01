#include <string>
#include <vector>

using namespace std;

int solution(int n, vector<int> lost, vector<int> reserve) {
    int answer = 0;
    bool stu[n+1];
    for (int i=0;i<=n;i++) {
        stu[i] = true;
    }
    
    for (int i=0;i<lost.size();i++) {
        stu[lost[i]] = false;
    }
    
    for (int i=0; i<reserve.size(); i++) {
        if(!stu[reserve[i]]) {
            stu[reserve[i]] = true;
            continue;
        } else {
            if(!stu[reserve[i]-1]) {
                stu[reserve[i]-1] = true;
                continue;
            }else if(!stu[reserve[i]+1]) {
                stu[reserve[i]+1] = true;
                continue;
            }
            
        }
    }
    
    for (int i=1;i<=n;i++) {
        if(stu[i]) answer++;
    }
    
    return answer;
}