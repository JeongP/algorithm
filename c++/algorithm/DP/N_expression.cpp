#include <string>
#include <vector>
#include <algorithm>

using namespace std;


vector<int> vec;

void dfs(int num, int number, int depth) {
    if(depth > 8) return;
    if(num == number) {
        vec.push_back(depth);
        return;
    } else {
        depth++;
        dfs(num+num, number, depth);
        dfs(num-num, number, depth);
        dfs(num*num, number, depth);
        dfs(num/num, number, depth);
    }
}



int solution(int N, int number) {
    int answer = 0;
    
    dfs(N, number, 1);
    sort(vec.begin(), vec.end());
    if(vec.front() > 8) return -1;
    answer = vec.front();
    return answer;
}