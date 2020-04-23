#include <string>
#include <vector>

using namespace std;

bool used[20010];

int solution(int stock, vector<int> dates, vector<int> supplies, int k) {
    int answer = 0;
    int idx;

    while(stock < k) {

        int maxSup = 0;
        for(int i=0;i<dates.size();i++) {
            if(dates[i] <= stock && !used[i]) {
                if( maxSup < supplies[i] ) {
                    idx = i;
                    maxSup = supplies[i];
                }
                
            }
        }

        used[idx] = true;
        answer++;
        stock += maxSup;

    }

    return answer;
}

/*
    
    
    day = stock;
    dates <= stock들 중에서 supplies의 값이 최대인 것.
    answer ++;
    if(stock >= K-1) return answer;

    stock += supplies[i]
    dates <= stock 인 것들 중에서 supplies의 값이 최대인 것.
    answer ++;
    if(stock >= K-1) return answer;



 */