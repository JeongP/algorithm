/*

    입력값 받을 배열 -> arr
    각 원소에서 증가하는 부분 수열의 합을 담을 배열 -> dp
    각 원소들(n)에 대해 앞의 값(i)보다 크다면 dp[i]값에 arr[n]값을 더해줘서 결과를 구한다.

 */


#include <iostream>
#include <algorithm>

using namespace std;

#define MAX 1001

int main () {
    // initialize value
    int n;
    int arr[MAX] = {0};
    int dp[MAX] = {0};

    // input
    cin >> n;
    for(int i=1;i<=n;i++) {
        cin >> arr[i];
        dp[i] = arr[i];
    }

    // solution
    // dp[1] = arr[1];
    for(int i=2;i<=n;i++) {
        for(int j=1;j<i;j++) {
            if(arr[i] > arr[j] && dp[i] < dp[j]+arr[i]) {
                dp[i] = dp[j] + arr[i];
            }
        }
    }

    // prt answer
    int sum = 0;
    for(int i=1;i<=n;i++) {
        sum = max(sum,dp[i]);
    }

    cout << sum << endl;

}