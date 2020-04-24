#include <string>
#include <vector>
#include <iostream>
//#include <algorithm>

using namespace std;

int solution(vector<vector<int>> baseball) {
    int answer = 0;
    int a[3] = {0, };
    int b[3] = {0, };
    int strike = 0;
    int ball = 0;
    for(int j = 123; j <= 987; j++){
        int i;
        int tmp = j;
        int cnt = 2;    // for parsing
        while(tmp > 0){
            a[cnt--] = tmp % 10;
            tmp /= 10;
        }
        
        for(i = 0; i < baseball.size(); i++){ // 첫번째~ 끝 조건 만족시
            if(a[0] == a[1] || a[1] == a[2] || a[0] == a[2])    // 수 중복
                break;
            if(a[0] == 0 || a[1] == 0 || a[2] == 0)
                break;
            tmp = baseball[i][0];
            strike = baseball[i][1];
            ball = baseball[i][2];
            int tmpstr = 0;
            int tmpball = 0;
            cnt = 2;
            while(tmp > 0){
                b[cnt--] = tmp % 10;
                tmp /= 10;
            }
            
            for(int m = 0; m < 3; m++){
                for(int n = 0; n < 3; n++){
                    if(a[m] == b[n]){       // 같숫 발견 case
                        tmpball++;
                        if(m == n){  //자리까지 같으면
                            tmpstr++;
                            tmpball--;
                        }
                    }
                }
            }
            if(strike != tmpstr || ball != tmpball){    // 어긋나는경우
                break;
            }
        }
        
        if(i == baseball.size())    // break 안당했으면
            answer++;
    }
    return answer;
}