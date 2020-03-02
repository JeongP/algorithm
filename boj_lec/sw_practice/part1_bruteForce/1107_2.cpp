/*

    참고: https://jaimemin.tistory.com/659

 */

#include <iostream>
#include <set>
#include <algorithm>
#include <cmath>
using namespace std;

const int MAX = 1000000+1;
const int INF = 987654321;

int N,M;
set<int> broken;

// 현재 채널에서 바꾸는 경우
int fromHundred() {
    return abs(N-100);
}

bool possible(int num)
{
    if(num == 0)
    {
        if(broken.find(num) == broken.end()) return true;
        else return false;
    }

    while(num) 
    {
        if(broken.find(num%10) != broken.end()) return false;
        num/=10;
    }
    return true;
}

int length(int n) {
    if(n==0) return 1;
    int cnt =0;
    while(n) {
        n/=10;
        cnt++;
    }
    return cnt;
}

// 채널 누르고 +/- 하는 경우
int findEntirely() {
    int result = INF;
    int num = 0;

    for(int i=0;i<MAX;i++) 
    {   
        // 채널을 누를 수 있다면..
        if(possible(i))
        {
            int clickCnt = abs(N-i);
            if(result > clickCnt) {
                result = clickCnt;
                num = i;
            }
        }
    }

    return result + length(num);
}



int main () {
    cin >> N >> M;
    for(int i=0;i<M;i++) {
        int btn;
        cin >> btn;
        broken.insert(btn);
    }

    cout << min(findEntirely(), fromHundred()) << endl;
    
    return 0;
}