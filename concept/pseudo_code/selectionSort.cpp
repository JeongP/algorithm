#include <iostream>
using namespace std;

int main () {
    int arr[10] = {1,1,1,1,1,1,1,1,1,1};
    for (배열 원소 수만큼) {
        최소값 설정
        for ( i부터 원소수만큼 ) {
            if(해당 원소가 최소값보다 작다면) {
                최소값에 대입.
                인덱스 저장.
            }
        }
        // 스왑
        int tmp = arr[i];
        arr[i] = min;
        min = tmp;
    }
}