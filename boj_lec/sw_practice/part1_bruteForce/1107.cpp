/*

    1. 1부터 999999까지 탐색.(999999의 근거는 MAX 채널(50만)을 찾아야하고 리모콘 버튼이 하나만 된다고 했을 때, 7자리수로 넘어가지 않아도 최소한의 차를 찾아낼 수 있어서)
    2. 고장난 버튼이 해당된 수가 아니라면 for문 마저 진행
    3. 채널 선택에 사용된 버튼 수를 구하고
    4. 찾고자 하는 채널과의 절대값 차를 더해줘서 정답을 도출한다.
    5. 틀렸다고 나온다; 테스트 케이스는 잘 맞는데..


    --
    <생각 못했던 거>
    1. 기존에 주어진 채널에서 찾아가는 것과 비교해서 최소값 찾는거..
    2. impossibleNum과 pushNumCnt에서 0 값에 대한 처리 생각못함..

 */

#include <iostream>
#include <set>
#include <algorithm>
#include <cstdlib>
#define INF 987654321

using namespace std;

int N,M;
set<int> breakArr;
int answer = INF;

void input() {
    cin >> N >> M;
    int x;
    for(int i=0;i<M;i++) {
        cin >> x;
        breakArr.insert(x);
    }

}

void prt() {
    if(N==100) {
        cout << 0 << endl;
        return;
    } else {
        cout << answer << endl;
    }

}

bool impossibleNum(int num) {
    
    while(num>0)
    {
        int dnum = num%10;
        // 각 자리수 중에 고장난 버튼이 하나라도 있다면
        if(breakArr.find(dnum) != breakArr.end()) 
        {
            return true;
        }
        num/=10;
    }
    return false;
}

int pushNumCnt(int num) {
    
    int cnt;
    while(num) {
        num/=10;
        cnt++;
    }
    return cnt;
}

void sol() {
    if(N==100) {
        prt();
        return;
    }
    
    for(int i=0;i<=999999;i++) {
        // 클릭 가능한지
        if(impossibleNum(i) == true) continue;
        // 숫자 누르는데 소모한 cnt 수
        int result = pushNumCnt(i);
        int updownBtn = abs(i-N);
        result = updownBtn + result;
        answer = min(result, answer);
    }

    prt();
}

int main () {
    input();
    sol();
    return 0;
}