#include <iostream>

using namespace std;

int main() {
    int n, result=0;
    cin >> n;

    result += n / 500;
    n = n%500;
    result += n /100;
    n = n%100;
    result += n / 50;
    n = n%50;
    result += n /10;
    n = n%10;
    
    cout << result << endl;
}