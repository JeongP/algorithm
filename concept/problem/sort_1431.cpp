#include <iostream>
#include <algorithm>

using namespace std;

int getSum(string a) {
    int sum = 0;
    for(int i=0; i<a.length(); i++) {
        if(a[i]-'0' >= 0 && a[i]-'0' <= 9) {
            sum += a[i]-'0';
        }
    }
    return sum;
}
bool cmp (string a, string b) {
    if(a.length() < b.length()) {
        return 1;
    }else if (a.length() > b.length()) {
        return 0;
    }else {
        if(getSum(a) != getSum(b)) {
            return getSum(a) < getSum(b);
        } else {
            return a < b;
        }
        
    }
}
int main() {
    string a[20000];
    int n;
    cin >> n;

    for (int i=0; i<n; i++) {
        cin >> a[i];
    }

    sort(a, a+n, cmp);
    for(int i=0; i<n; i++) {
        if(i>0 && a[i] == a[i-1]) {
            continue;
        } else {
            cout << a[i] << " ";
        }
    }
}