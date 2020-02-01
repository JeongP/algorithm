#include <iostream>
using namespace std;

// 특정한 값을 기준으로 큰 값과 작은 값을 나누어 정렬해본다.
void quickSort(int *data, int start, int end) {
    if(start>=end) return;
    
    int key = start;
    int i = start + 1, j = end;

    while(i<=j) {
        while(i<=end && data[i] <= data[key]) {
            i++;
        }
        while(j>start && data[j] >= data[key]) {
            j--;
        }
        if(j<i) {
            int tmp = data[j];
            data[j] = data[key];
            data[key] = tmp;
        }else {
            int tmp = data[i];
            data[i] = data[j];
            data[j] = tmp;
        }
    }

    quickSort(data,start,j-1);
    quickSort(data,j+1,end);
}
int main() {
    int arr[10] = {1,10,5,8,7,6,4,3,2,9};
    quickSort(arr, 0, 9);
    for (int i : arr) {
        cout << i << " ";
    }
    return 0;

}