#include <iostream>
using namespace std;

int main () {
    int n;
    int max = -1000001;
    int min = 1000001;
    int cnt;
    int x = 1;

    cin >> cnt;

    while((x != n) && cin >> cnt) {
        if(max < n) max = n;
        if(min > n) min = n;
        x++;
    }

    cout << min << " " << max;

}