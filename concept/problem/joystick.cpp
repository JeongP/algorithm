#include <iostream>
#include <vector>

using namespace std;



int main () {
    string name = "JEROEN";
    
    int count = 0;
    
    // 첫 자리수 정리해주고
    if( name[0] <= 77 ) {
        count = name[0] - 65;
    } else {
        count = 90 - name[0] + 1;
    }

    int index = 0;
    // 방향 설정
    for (int i=1; i<name.length(); i++) {
        // 다음 원소가 A라면 넘어가구.
        if(name[i] == 65) {
            continue;
        } else {
            // 커서 이동 방향 설정
            if(정방향으로 가는게 낫다면) {
                count += i-index;
                // 각 원소마다 조이스틱을 움직여 얻을 수 있는 최소값 설정
                if (name[i]가 M보다 작으면) {
                    count += ~
                } else {
                    count += ~
                }
            }else {
                count += name.length()-1-i;
                // 각 원소마다 조이스틱을 움직여 얻을 수 있는 최소값 설정
                if (name[i]가 M보다 작으면) {
                    count += ~
                } else {
                    count += ~
                }
            }
            
        }
        

    }    
}

void upAndDown() {

}