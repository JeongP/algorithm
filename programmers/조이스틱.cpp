#include <string>
#include <vector>
#include <iostream>
using namespace std;

bool words[22];

bool isAllVisited(string s) {
    for(int i=0;i<s.size();i++) {
        if(!words[i]) {
            return false;
        }
    }
    return true;
}


int solution(string name) {
    int answer = 0;
    int idx = 0;
    string alphabet = "";

    for(int i=0;i<name.length();i++) {
        alphabet += "A";    
    }
    
    words[idx] = true;
    while(!isAllVisited(name)) {
        
        int c = name[idx] - 'A';
        // N 아래의 알파벳의 경우 조이스틱 윗 버튼 클릭.
        if(c<=13) {
            while(name[idx] != alphabet[idx]) {
                int tmp = alphabet[idx] - 'A'; 
                tmp++;
                alphabet[idx] = tmp + 'A';
                answer++;
            }
        } else {
            while(name[idx] != alphabet[idx]) {
                int tmp = alphabet[idx] - 'A';
                tmp = 26 - tmp;
                tmp--;
                alphabet[idx] = tmp + 'A';
                answer++;
            }
        }

        // 방향 정하고, idx 재설정
        int leftIdx = idx;
        int lcnt = 0;
        int rightIdx = idx;
        int rcnt = 0;
        while(1){
            if(leftIdx <= 0) {
                leftIdx = name.length();
            }
            leftIdx-=1;
            lcnt++;
            if(name[leftIdx] != 'A') break;
        }

        while(1) {
            rightIdx+=1;
            rcnt++;
            if(name[rightIdx] != 'A') break;
        }

        // 방향 정하기.
        if(rcnt<=lcnt) {
            for(int j=idx;j<=rightIdx;j++) {
                words[j] = true;
            }
            answer += rcnt;
            idx = rightIdx;
        }else {
            if(leftIdx <= idx) {
                for(int j= idx;j>=leftIdx;j--) {
                    words[j] = true;
                }
            } else {
                for(int j= idx;j>=0;j--) {
                    words[j] = true;
                }
                for(int j=leftIdx;j<name.length();j++) {
                    words[j] = true;
                }
            }
            answer += lcnt;
            idx = leftIdx;
        }

        // 방문 채워주기
        for()
        
    }

    return answer;
}

/*

    1. 첫 자리 알파벳 변경
    2. 모든 알파벳 방문할 때까지, 반복
    3. 좌우 각각에 대해 A가 아닌 문자열을 만나는 카운트 비교 후 방향 이동 후 알파벳 변경.

 */

