#include <iostream>
using namespace std;

// 본인 순서 때, 앞의 녀석들과 비교하며 본인의 위치를 알아서 찾아가는 정렬.
// 그러다보니 왼쪽 것들은 정렬이 되어있는 상태.
// 정렬이 대부분 되어있는 정렬에서 사용하면 좋음.
int main() {
    int arr[10] = {1,10,5,8,7,6,4,3,2,9};

    for (int i=0; i<10; i++) {
        int j = i;
        for ( int j=i; j>0; j--) {
            if(arr[j] < arr[j-1]) {
                int tmp = arr[j];
                arr[j] = arr[j-1];
                arr[j-1] = tmp;
            }
        }
    }

    for (int i : arr) {
        cout << i << " ";
    }

}