#include <iostream>
using namespace std;

// 옆에 있는 값과 비교해서 더 작은 값을 앞으로 보내는 정렬 방식.
// 가장 큰 값이 맨 뒤로 보내지는 과정.
// 효율 가장 구림(매번 스왑 과정 필요). O(N^2)
int main () {
    int arr[10] = {1,10,5,8,7,6,4,3,2,9};
    int index;
    for (int i=0; i<10; i++) {
        for (int j=0;j<9-i;j++) {
            if(arr[j] > arr[j+1]) {
                int tmp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = tmp;
            }
        }
    }

    for (int i : arr) {
        cout << i << " ";
    }
}