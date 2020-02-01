#include <iostream>

using namespace std;


int main () {

    // 입력받고
    int n, k; 
    cin >> n >> k;
    int d[n];
    for (int i=0; i<n; i++) {
        cin >> d[i];
    }
    int result=0;
    int index = n-1;
    while (k!=0) {
        result = k / d[index];
        k = k % d[index];
        index--;
    }

    cout << result << endl;
}