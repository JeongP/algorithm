#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;


string solution(string number, int k) {
    string answer = "";
    string candidate = "";
    vector<int> v;
    int len = number.length();
    int answerLen = len - k;
    int idx = 0;
    
    while(answerLen!=0) {
        int maxVal = 0;
        for(int i=idx;i<=len-answerLen;i++) {
            int n = number[i] - '0';
            if(maxVal < n) {
                maxVal = n;
                idx = i+1;
            }
        }
        answer = answer + to_string(maxVal);
        answerLen--;
    }
    
    
    return answer;
}