#include <iostream>
#include <cstring>
#include <cmath>
#include <algorithm>

using namespace std;

const int INF = 987654321;
const long long MAX = 100001;
long long cache[MAX];
long long N;

void preCalculate() {
    for(int i=1;i*i<=N;i++) {
        cache[i] = i*i;
    }
}

long long minSquare() {
    long long result = INF, temp = N;
    for(long long i =(long long)sqrt(temp);i>=1;i--) {
        long long sum = 0;
        for(int j=i; temp&&j>=1;j--) {
            sum += temp / cache[j];
            temp %= cache[j];
        }
        result = min(sum, result);
        temp = N;
    }

    return result;
}

int main () {
    cin >> N;
    if(N<1 || N>=MAX) {
        exit(-1);
    }
    preCalculate();
    cout << minSquare() << endl;
    
}