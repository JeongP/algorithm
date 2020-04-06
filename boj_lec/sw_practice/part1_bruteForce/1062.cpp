/*

    1. K개의 알파벳을 배우는 모든 경우의 수를 DFS로 구하고
    2. 각 경우마다 입력받은 단어들을 읽을 수 있는 지 없는지 판단한다.
    3. 그 중 가장 큰 값을 return 한다.

 */

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

int N,K;
vector<string> words;
bool alphabet[26];
int answer = 0;

void input() {
    cin >> N >> K;
    for(int i=0;i<N;i++) {
        string s;
        cin >> s;
        words.push_back(s);
    }
}

void initialize() {
    // acint는 읽을 수 있는 걸로.
    alphabet[0] = true;
    alphabet[2] = true;
    alphabet[8] = true;
    alphabet[13] = true;
    alphabet[19] = true;
}

int checkNum() {
    int cnt = 0;
    int ansCnt = 0;
    for(int i=0;i<N;i++) {
        for(int j=0;j<words[i].length();j++) {
            int alpha_idx = words[i][j] - 'a';
            if(!alphabet[alpha_idx]) break;
            else cnt++;
        }
        if(words[i].length() == cnt) {
            ansCnt++;
        }
        cnt=0;
    }
    return ansCnt;
}


int dfs(int idx, int depth) {

    if(depth == K-5) {
        // answer = max(answer, checkNum());
        return checkNum();
    }

    for(int i=idx;i<26;i++) {
        if(!alphabet[i]) {
            alphabet[i] = true;
            answer = max(dfs(i, depth+1), answer);
            alphabet[i] = false;
        }
    }

    return answer;
}

int main () {
    input();
    initialize();
    if(K<5) {
        cout << 0 << endl;
        return 0;
    }

    cout << dfs(0,0) << endl;
    return 0;
}