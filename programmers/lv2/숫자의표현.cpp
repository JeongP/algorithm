#include <string>
#include <vector>

using namespace std;

int solution(int n) {
    int answer = 0;
    int sum;
    
    for(int i=1;i<n;i++) {
        sum = 0;
        int tmp = i;
        while(sum < n) {
            sum += tmp;
            tmp+=1;
        }
        if(sum == n) answer++;
    }
    return answer+1;
}