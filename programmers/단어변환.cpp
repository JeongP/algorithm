#include <string>
#include <vector>

using namespace std;

bool visit[51];
int result = 99;

void DFS(string begin, string target, int cnt, vector<string> words) {
    
    if(target == begin) {
        result = min(result, cnt);
        return;
    }
    
    for(int i=0;i<words.size();i++) {
        int wordLen = begin.length();
        int spellCnt = 0;
        if(!visit[i]) {
            for(int j=0;j<wordLen;j++) {
                if(begin[j] == words[i][j]) spellCnt++;
            }
            if(spellCnt == wordLen-1) {
                visit[i] = true;
                DFS(words[i],target,cnt+1,words);
                visit[i] = false;
            }
        }
    }
}

int solution(string begin, string target, vector<string> words) {
    int answer = 0;
    bool isEnd = false;
    // 변환 가능한지
    for(int i=0;i<words.size();i++) {
        if(target == words[i]) {
            isEnd = true;
            break;
        }
    }
    if(!isEnd) return 0;

    DFS(begin, target, 0, words);

    answer = result;

    return answer;
}