#include <iostream>
using namespace std;

// 한 바퀴마다 min과 비교하여 가장 작은 녀석을 맨 앞으로
// 시간복잡도: O(n^2)
int main () {
    int arr[10] = {1,10,5,8,7,6,4,3,2,9};
    int index;
    for(int i=0; i<10; i++) {

        int min = 9999;
        for( int j=i; j<10; j++ ) {
            if(min > arr[j]) {
                min = arr[j];
                index = j;
            }
        }
        int tmp = arr[i];
        arr[i] = arr[index];
        arr[index] = tmp;
    }

    for (int i : arr) {
        cout << i << " ";
    }
}