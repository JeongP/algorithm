#include <string>
#include <vector>

using namespace std;

int main () {
    // 테스트 할 모든 숫자를 벡터에 담음.
    
    for(int i=123;i<=987;i++) {
        int num[3];
        num[0] = i/100;
        num[1] = i/10%10;
        num[2] = i%10;

        // if(0포함한 숫자와, 중복되는 숫자 제거)

        for(int i=0;i<baseball.size();i++) {
            
            int ans[3];
            ans[0] = baseball[i][0] / 100;
            ans[1] = baseball[i][0] / 100;
            ans[2] = baseball[i][0] / 100;

            for(int k=0;k<3;k++) {
                if(자리수 같고, 숫자도 같다면) {
                    strike++;
                }else if(자리수 다른데 숫자가 같다면) {
                    ball++;
                }
            }
            if(strike 수와 baseball[i][1] 같고 && ball 수와 base[i][2]가 같다면) count ++;
        }
        if(모든 조건을 만족한다 (count==baseball.size()) {
            answer++;
        }

    }

    // 각 숫자에 대해, 볼 스트라이크 체크.


    

}