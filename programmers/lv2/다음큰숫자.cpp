#include <string>
#include <vector>
#include <iostream>

using namespace std;

string itos(int n) {
    string tmp = "";
    while(n!=1) {
        if(n%2 == 0) {
            tmp = '0' + tmp;
        } else {
            tmp = '1' + tmp;
        }
        n /= 2;
    }
    tmp = '1' + tmp;
    return tmp;
}

int cntOne(string s) {
    int c = 0;
    for(int i=0;i<s.length();i++) {
        if(s[i] == '1') c++;
    }    
    return c;
}

int solution(int n) {
    int answer = 0;
    string s = "";
    int nCnt = 0;
    int iCnt = 0;
    
    s = itos(n);
    nCnt = cntOne(s);
    for(int i=n+1;i<=1000000;i++) {
        string s2 = itos(i);
        iCnt = cntOne(s2);
        if(iCnt == nCnt) {
            answer = i;
            break;
        }
                          
    }
    
    return answer;
}


/*

    1. n의 2진수 구하고
    2. n보다 크고 10만보다 작은 수중에 2진수 구해서 1의 갯수가 같은거랑 비교

*/