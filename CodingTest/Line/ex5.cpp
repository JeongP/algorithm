#include <iostream>
using namespace std;

int pascalTri[100][100];
int m,n;
int startX, startY;
int dir[4][2] = {{0,1},{0,-1},{1,0},{-1,0}};
int minDistance;

void pascal() {
    for(int i=0;i<50;i++) {
        pascalTri[i][0] = 1;
        pascalTri[0][i] = 1;
    }

    for(int i=1;i<50;i++) {
        for(int j=1;j<50;j++) {
            pascalTri[i][j] = pascalTri[i-1][j] + pascalTri[i][j-1];
        }
    }
}
int main () {
    cin >> n >> m;
    cin >> startY >> startX;

    if(startX == 0 && startY == 0) {
        cout << "fail"; 
        return 0;
    }

    if(startX <0 || startX >= m || startY < 0 || startY >= n) {
        cout << "fail";
        return 0;
    }

    minDistance = startX + startY;
    pascal();
    cout << minDistance << endl << pascalTri[startY][startX];
    return 0;

}