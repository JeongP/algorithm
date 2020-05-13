#include <string>
#include <vector>
#include <iostream>
using namespace std;

bool visit[22];

int moveRight (char c) {
    int cnt = 0;
    char a = 'A';
    while(a != c) {
        cnt++;
        a++;
    }
    return cnt;
}

int moveLeft (char c) {
    int cnt = 1;
    char a = 'Z';
    while(a != c) {
        cnt++;
        a--;
    }
    return cnt;
}

int solution(string name) {
    int answer = 0;
    int idx = 0;
    string initialName = "";
    
    // 맨처음 문자열 세팅.
    for(int i=0;i<name.length();i++) {
        initialName = initialName + "A";
        
        if(name[i] == 'A') visit[i] = true;
    }

    // 처음 이동하기
    if(name[idx] <= 'N') {
        answer = answer + moveRight(name[idx]);
        initialName[idx] = name[idx];
    } else if (name[idx] > 'N') {
        answer = answer + moveLeft(name[idx]);
        initialName[idx] = name[idx];
    }

    
    while(name != initialName) {
        
        
        // idx 위치 바꿔주기.
        int rightIdx;
        int rightCnt = 1;
        if(idx == name.length()-1) {
            rightIdx = 0;
        }else {
            rightIdx= idx + 1;
        }

        int leftIdx; 
        int leftCnt=1;
        if(idx == 0) {
            leftIdx = name.length()-1; 
        } else {
            leftIdx = idx-1; 
        }
        
        
        while(visit[rightIdx] && rightIdx < name.length()) {
            if(rightIdx == name.length()-1) {
                rightIdx = 0;
            }else {
                rightIdx +=1;
            }
            rightCnt++;
        }
        
        while(visit[leftIdx] && leftIdx >= 0) {
            if(leftIdx == 0) {
                leftIdx = name.length()-1;
            } else {
                leftIdx = idx - 1;
            }
            leftCnt++;
        }
        
        // 오른쪽으로 이동
        if(leftCnt >= rightCnt) {
            answer = answer + moveRight(name[rightIdx]);
            visit[rightIdx] = true;
            initialName[rightIdx] = name[rightIdx];
            idx = rightIdx;
        } 
        else { // 왼쪽이동
            answer = answer + moveLeft(name[leftIdx]);
            visit[leftIdx] = true;
            initialName[leftIdx] = name[leftIdx];
            idx = leftIdx;
        }
        
    }
    
    
    
    return answer;
}

/*

    1. 첫 자리 알파벳 변경
    2. 모든 알파벳 방문할 때까지, 반복
    3. 좌우 각각에 대해 A가 아닌 문자열을 만나는 카운트 비교 후 방향 이동 후 알파벳 변경.

 */