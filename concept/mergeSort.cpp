// 일단 반으로 쪼개고 나중에 합쳐서 정렬한다.
// 단점: 정렬된 데이터를 잠시 담을 배열이 필요해, 메모리 상으로 낭비 발생.
#include <iostream>

using namespace std;
int num = 8;
int sorted[8];

void merge(int a[], int m, int middle, int n) {
    int i = m;
    int j = middle + 1;
    int k = m;

    while(i <= middle && j <= n) {
        if(a[i]<=a[j]) {
            sorted[k] = a[i];
            i++;
        } else {
            sorted[k] = a[j];
            j++;
        }
        k++;
    }

    if(i>middle) {
        for (int t=j; t<=n; t++) {
            sorted[k] = a[t];
            k++;
        }
    } else {
        for (int t=i; t<=middle; t++) {
            sorted[k] = a[t];
            k++;
        }
    }

    for(int t=m; t<=n; t++) {
        a[t] = sorted[t];
    }

}
void mergeSort(int a[], int m, int n) {
    if(m<n) {
        int middle = (m+n)/2;
        mergeSort(a, m, middle);
        mergeSort(a, middle+1, n);
        merge(a, m, middle, n);
    }
}
int main() {
    int arr[8] = {7,6,5,8,3,5,9,1};
    mergeSort(arr, 0, num-1);
    for (int i=0;i<num;i++) {
        cout << arr[i] << " ";
    }
}
