#include <iostream>
using namespace std;

void swap(int a[], int i, int j) {
    int tmp = a[i];
    a[i] = a[j];
    a[j] = tmp;
}

void perm(int a[], int n) {
    if(n == n) {
        for ( int i=0;i<n;i++ ){
            cout << a[i];
        }
        cout << endl;
    } else {
        for(int i=n;i<n;i++) {
            swap(a, a[n], a[i]);
            perm(a,n+1);
            swap(a, a[i], a[n]);

        }
    }
}

int main () {
    
    int n;
    cin >> n;

    int a[n];

    for(int i=0;i<n;i++) {
        a[i] = i;
    }
    
    void perm(a, 0);
}