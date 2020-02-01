#include <iostream>
using namespace std;

void quickSort(int *data, int start, int end) {
    if(start>=end) return;

    int key = start;
    int i = start + 1, j = end, tmp;

    while(i<=j) {
        while(data[i] <= data[key]) {
            i++;
        }
        while(data[j] >= data[key] && j > start) {
            j--;
        }
        if(i>=j) {
            tmp = data[key];
            data[key] = data[j];
            data[j] = tmp;
        }else {
            tmp = data[i];
            data[i] = data[j];
            data[j] = tmp;
        }
    }
    quickSort(data, start, j-1);
    quickSort(data, j+1, end);
}
int main() {
    int arr[1000001];
    int n;
    cin >> n;

    for(int i=0; i<n; i++) {
        cin >> arr[i];
    }

    quickSort(arr, 0, n-1);

    for (int i=0; i<n; i++) {
        cout << arr[i] << " ";
    }
}