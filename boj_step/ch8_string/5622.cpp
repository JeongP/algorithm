#include <iostream>
#include <string>

using namespace std;
int sum = 0;
void go(char a) {
    int num = a -'A';
    if(0<=num && num <=2) {
        // abc
        sum += 3;
    }else if(3<=num && num <=5) {
        // def
        sum += 4;
    }else if(6<=num && num <= 8) {
        // ghi
        sum += 5;
    }else if(9<=num && num <=11) {
        // jkl
        sum += 6;
    }else if(12<=num && num<=14) {
        // mno
        sum += 7;
    }else if(15<=num && num<=18) {
        // pqrs
        sum += 8;
    }else if(19<=num && num <= 21) {
        // tuv
        sum += 9;
    }else if(22<=num && num <=25) {
        // wxyz
        sum += 10;
    }else {
        // operator
        sum += 11;
    }
}

int main () {
    string s;
    cin >> s;

    for(int i=0;i<s.length();i++) {
        go(s[i]);
    }

    cout << sum << endl;
}
