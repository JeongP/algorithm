#include <string>
#include <vector>
#include <stack>
#include <iostream>

using namespace std;

vector<int> solution(vector<int> heights) {
    vector<int> answer;
    vector<pair<int,int>> vec;
    stack<int> s;
    
    for(int i=1; i<=heights.size(); i++) {
        vec.push_back(make_pair(i,heights[i-1]));
    }
    
    for(int i=heights.size()-1; i>=0; i--) {
        for(int j=i-1; j>=0; j--) {
            if(vec[i].second < heights[j]) {
                s.push(vec[j].first);
                break;
            }
            if(j==0) {
                s.push(0);
            }
        }
    }
    s.push(0);
    
    while(!s.empty()) {
        answer.push_back(s.top());
        s.pop();
    }
    
    return answer;
}