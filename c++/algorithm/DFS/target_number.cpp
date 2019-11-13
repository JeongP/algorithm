#include <string>
#include <vector>

using namespace std;

int total_count=0;

void dfs(vector<int> v, int target, int sum, int depth) {
    if(v.size()-1==depth) {
        if(sum == target) {
            total_count++;
        }
        return;
    }
    dfs(v, target, sum+v[depth+1], depth+1);
    dfs(v, target, sum-v[depth+1], depth+1);
}


int solution(vector<int> numbers, int target) {
    int answer = 0;
    
    dfs(numbers, target, numbers[0], 0);
    dfs(numbers, target, -1*numbers[0], 0);
    
    answer = total_count;
    
    return answer;
}