#include <iostream>
#include <algorithm>

using namespace std;

int main () {
    int a[] = {5,7,3,6,9,1,2,4,8};
    sort(a,a+9,greater<int>());

    for (int i : a) {
        cout << i << " ";
        
    }
}