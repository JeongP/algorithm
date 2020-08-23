#include <string>
#include <vector>
#include <iostream>
using namespace std;

int arr[100010] = {0,};
int mNum = 0;
int counting() {
    int cnt = 0;
    for (int i=1;i<=mNum;i++) {
        if(arr[i] != 0) cnt++;
    }
    return cnt;
}

vector<int> solution(string s) {
    vector<int> answer;
    string num = "";
    
    for(int i=0;i<s.length()-1;i++) {
        if(s[i] != '{' && s[i] != '}' && s[i] != ',') {
            num += s[i];
        }
        else if(s[i] == ',') {
            int n = stoi(num);
            if(n > mNum) mNum = n;
            arr[n]++;
            num = "";
        }
        else if(s[i] == '}') {
            int n = stoi(num);
            if(n > mNum) mNum = n;
            arr[n]++;
            i++;
            num = "";
        }
    }
    
    // 원소 개수 세아리기
    int c = counting();
    
    while(c!=0) {
        for(int i=1;i<=mNum;i++) {
            if(c == arr[i]) {
                answer.push_back(i);
                c--;
                break;
            }
        }
    }
    return answer;
}

/*

    1. 입력 문자열 s를 돌면서 숫자가 나올 때, 해당 숫자 배열 cnt 를 ++ 해준다.    
    2. 배열을 돌면서 배열값이 가장 큰 값(해당 숫자의 등장 횟수가 가장 높은 값)을 가져와서
    3. 일치하는 배열 원소 값을 하난 씩 뺴줌.

*/