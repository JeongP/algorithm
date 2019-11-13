#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main() {
    vector<int> citations;
    citations.push_back(3);
    citations.push_back(0);
    citations.push_back(6);
    citations.push_back(1);
    citations.push_back(5);

    int answer = 0;

    // 0~1만회 for 문 돌리기 -> 인용된 논문 수 > 인용횟수 보다 높다면 그 값을 리턴
    for(int i=10000; i>=0; i--) {
        int count = 0;
        for(int citation : citations) {
            if(citation >= i) {
                count += 1;
            }
            if(count >= i) {
                answer = count;
                cout << answer << endl;
                
            }
        }
    }
    return answer;
}