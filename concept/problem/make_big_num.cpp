#include <iostream>
#include <vector>
#include <string>

using namespace std;

string number = "1924"; 
int k = 2;
vector<string> v;

void swap (string number, int i) {
    int tmp = number[i];
    number[i] = number[i+1];
    number[i+1] = tmp;
}

int main () {
    
    
    
    int result_length = number.length()-k;
    
    for(int i=0;i<number.length()-1;i++) {
        // 0일땐 벡터에 일단 삽입
        if(i==0) {
            v.push_back(number[0]);
            continue;
        }
        // 남은 원소를 다 넣어야하는 상황인가
        if() {
            for(남은 모든 원소에 대해) {
                // 삽입.
            }
            answer = 벡터에 원소들 삽입하기.
        }else {
            if(number[i-1] < number[i]) {
            v.pop_back();
            v.push_baack(number[i]);
            } else {
                v.push_back(number);
            }
        }
    }

}