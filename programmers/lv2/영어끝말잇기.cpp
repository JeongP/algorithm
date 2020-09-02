#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

vector<int> solution(int n, vector<string> words) {
    vector<int> answer;
    
    for(int i=1;i<words.size();i++) {
        string before = words[i-1];
        string after = words[i];
        bool flag = false;

        for(int j=0;j<i;j++) {
            if(words[j] == words[i]) {
                // 조건 처리.
                flag = true;
            }
        }
        
        if(before[before.length()-1] != after[0]) flag = true;

        if(flag) {
            int person = i % n + 1;
            int turn = i/n +1;
            answer.push_back(person);
            answer.push_back(turn);
            return answer;
        } 
    }

    answer.push_back(0);
    answer.push_back(0);
    
    return answer;
}