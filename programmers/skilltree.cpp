#include <string>
#include <vector>
#include <iostream>
using namespace std;

int solution(string skill, vector<string> skill_trees) {
    int answer = 0;
    bool alphabet[26] = {0,};
    for(int i=0;i<skill_trees.size();i++) {

        // 선행스킬순서에 포함되는지 여부 찾기.
        for(int j=0; j<skill_trees[i].length();j++) {
            if(skill.find(skill_trees[i][j]) != string::npos) {
                int idx = skill_trees[i][j] - 'A';
                alphabet[idx] = true;
            }
        }
        for(int k=0;k<6;k++) {
            cout << alphabet[k] << " ";
        }
        int chk_idx = 0;
        for(int j=0; j<skill_trees[i].length();i++) {
            int idx = skill_trees[i][j] - 'A';    
            // 선행스킬순서에 포함되는 알파벳이라면
            if(alphabet[idx]) {
                // 선행스킬순서와 스킬트리의 알파벳이 다르다면 
                if(skill[chk_idx] != skill_trees[i][j]) break;
                else chk_idx++;
            }
            if(j == skill_trees[i].length()-1) answer++;
        }
    }
    return answer;
}