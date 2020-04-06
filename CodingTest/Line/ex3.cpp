/*

    #최적의 투표소 설치#
    1. 직원들의 수와 투표 가능한 시간을 입력받는다.
    2. 투표 가능한 시간을 나타내는 배열에 모든 직원의 투표 가능한 시간을 다 담는다.
    3. 겹치는 값들은 같은 시간에 투표를 하는것을 의미하므로 그 중 가장 큰 수만큼의 투표소를 설치해 문제를 해결한다.

 */

#include <iostream>
using namespace std;

int timeStamp[160];

int main () {
    int n;
    int start, end;
    
    cin >> n;
    for(int i=0;i<n;i++) {
        cin >> start >> end;
        for(int j=start;j<end;j++) {
            timeStamp[j]++;
        }
    }
    int max = -1;
    for(int i=0;i<160;i++) {
        if(max < timeStamp[i]) max = timeStamp[i];
    }
    cout << max << endl;
}