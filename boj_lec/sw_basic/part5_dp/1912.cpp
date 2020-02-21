/*

    연속할거냐 말거냐.
    arr[] = 입력수열.
    dp[n] = n번째에서 연속하는 값들의 최대값.
    dp[n] = max(dp[n-1]+arr[n], arr[n]) 일 것
    
 */

#include <iostream>
#include <algorithm>

using namespace std;

const int MAX = 100001;
int arr[MAX];
int dp[MAX];
int n;
int answer = 0;

void input() {
    cin >> n;
    for(int i=1;i<=n;i++) {
        cin >> arr[i];
        dp[i] = arr[i];
    }
}

void solution () {
    answer = dp[1];
    for(int i=2;i<=n;i++) {
        dp[i] = max(dp[i],dp[i-1]+arr[i]);
        answer = max(answer, dp[i]);
    }
    
}

void prt() {
    cout << answer << endl;

}

int main () {
    input();
    solution();
    prt();
}