#include <iostream>

using namespace std;

int main() {
    int a[10] = {1,10,5,8,7,6,4,3,2,9};
    
    for (int i=0; i<10; i++) {
        int j = i;
        while(j>=0 && a[j] > a[j+1]) {
            int tmp = a[j];
            a[j] = a[j+1];
            a[j+1] = tmp;
            j--;
        }
    }
}