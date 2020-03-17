#include <iostream>
using namespace std;

const int MAX =100+1;
int n;
int map[MAX][MAX];
int result[MAX][MAX];
void input() {
    cin >> n;
    for(int i=1;i<=n;i++) {
        for(int j=1;j<=n;j++) {
            cin >> map[i][j];
        }
    }
    result[1][1] = 1;
}

// void prt() {

//     for(int i=1;i<=n;i++) {
//         for(int j=1;j<=n;j++) {
//             cout << result[i][j] << " ";
//         }
//         cout << endl;
//     }
// }

void sol() {
    for(int i=1;i<=n;i++) {
        for(int j=1;j<=n;j++) {
            if(result[i][j] == 0 || (i==n && j==n)) continue;

            int move = map[i][j];
            int down = i + move;
            int right = j + move;
            
            if(down <= n) result[down][j] += result[i][j];
            if(right <= n) result[i][right] += result[i][j];
        }
    }
    cout << result[n][n] << endl;
    // prt();
}

int main () {
    input();
    sol();
}