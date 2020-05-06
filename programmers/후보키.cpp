#include <string>
#include <vector>
#include <algorithm>
#include <set>
using namespace std;

bool desc(vector<int> a, vector<int> b) {
    return a > b;
}

bool check(vector<vector<string>> relation, int col, int row, int subset) {
    for(int a=0;a<row-1;a++) {
        for(int b=a+1;b<row;b++) {
            bool isSame = true;
            for(int k=0;k<col;k++) {
                if(subset & 1<<k == 0) continue;
                if(relation[a][k] != relation[b][k]) {
                    isSame = false;
                    break;
                }
            }
            if(isSame) return false;
        }
    }
    return true;
}

int solution(vector<vector<string>> relation) {
    int answer = 0;
    int row = relation.size();
    int col = relation.front().size();
    vector<int> candidates;

    for(int i=1;i<(1<<col);i++) {
        if(check(relation, row, col, i)) candidates.push_back(i);
    }

    sort(candidates.begin(),candidates.end(), desc);

}