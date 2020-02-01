#include <iostream>

using namespace std;

int d[1000001];

int dp(int x) {
    if(x==0) return 0;
    if(x==1) return 2;
    if(x==2) return 3;
    long long int result = 3 * dp(x - 2) + 2 * dp(x-1);
    for(int i=3; i<=x; i++) {
        result = result + 2 * dp(x-i);
    }
    return d[x] = result;
}
int main() {
    
}