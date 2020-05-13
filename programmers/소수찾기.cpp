#include <string>
#include <vector>
#include <cstdlib>
#include <algorithm>
#include <iostream>
#include <cmath>
using namespace std;

bool isDecimal(int number) {
    
    if (number == 2) return true; 
    if (number % 2 == 0) return false; 
     
    for (int i = 3; i <= sqrt(number); i++) {
        if (number% i == 0) return false;
    } 
    return true;
}

bool involve(int i, string numbers) {
    string s = to_string(i);
    int len = s.length();
    int len_cmp = 0;
    bool isOk;
    for(int a=0;a<s.length();a++) {
        isOk = false;
        for(int b=0;b<numbers.length();b++) {
            if(s[a] == numbers[b]) {
                numbers[b] = 'x';
                len_cmp++;
                isOk = true;
                break;
            }
        }
        if(!isOk) return false;
    }
    if(len_cmp == len) return true;
    else return false;

}


int solution(string numbers) {
    int answer = 0;
    string nCopy = numbers;
    sort(nCopy.begin(),nCopy.end(),greater<int>());
    int n = stoi(nCopy);

    for(int i=2;i<=n;i++) {
        if(isDecimal(i)) {
            if(involve(i,numbers)) answer++;
        }
    }
    return answer;
}

/*

    1. numbers를 내림차순으로 해서 가장 큰 수 찾기.
    2. 2부터 가장 큰 수까지 소수 찾고
    3. 각 소수의 각자리수가 numbers에 포함 되는지.
    4. 된다면 counting

 */