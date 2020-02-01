#include <iostream>
using namespace std;

int main () {
    int num;
    int firstNum, secondNum;
    int sum = 0;
    int resultNum = 0;
    int cycleNum = 0;

    cin >> num;
    
    if(num < 10) {
        num = num * 10;
    }

    resultNum = num;

    while(1) {
        firstNum = resultNum / 10;
        secondNum = resultNum % 10;
        sum = firstNum + secondNum;
        resultNum = (secondNum * 10) + (sum % 10);
        cycleNum++;
        if( resultNum == num ) break;
    }

    cout << cycleNum;
}



