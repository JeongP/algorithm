#include <iostream>
#include <string>

using namespace std;



int main () {
    string s;
    int arr[26] = {0,};
    int idx; // Max 값을 갖고 있는 index를 위한 변수
    int max_cnt=0; //Max값이 몇개 이상인지에 대한..
    int max_value = -1;
    
    cin >> s;

    for(int i=0;i<s.length();i++) {
        // 각 문자 정수화하기.(A - 0, Z - 25)
        int n = s[i] - 'A';
        
        
        // 소문자의 경우
        if(n>=32) {
            arr[n-32]++;
            
        }else if(n>=0) {
            // 대문자의 경우
            arr[n]++;
        }
    }
    
    // 최대값과 인덱스 찾기.
    for(int i=0;i<26;i++) {
        if(max_value < arr[i]) {
            idx = i;
            max_value = arr[i];
        }
    }
    

    // 최대값이 여러개인지 체크
    for(int i=0;i<26;i++) {
        if(arr[i] == max_value) {
            max_cnt++;
        }
    }

    if(max_cnt == 1) {
        char answer = idx + 'A';
        cout << answer << endl;
    } else {
        cout << "?" << endl;
    }
}