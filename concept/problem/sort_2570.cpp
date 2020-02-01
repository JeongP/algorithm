#include <iostream>
#include <vector>
using namespace std;

int main() {
    int arr[1001];
    int n;
    cin >> n;
    for (int i=0; i<n; i++) {
        cin >> arr[i];
    }

    for (int i=0; i<n; i++) {
        int min = 1001;
        int index;
        for(int j=i; j<n; j++) {
            if( min > arr[j]) {
                min = arr[j];
                index = j;
            }
        }
        int tmp = arr[i];
        arr[i] = arr[index];
        arr[index] = tmp;
    }

    for (int i=0; i<n; i++) {
        cout << arr[i] << " ";
    }
}

