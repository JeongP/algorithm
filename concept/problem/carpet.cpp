#include <iostream>

using namespace std;

int main () {
    int brown = 24;
    int red = 24;

    int total_tile_num = brown + red;

    // 약수를 구해서 벡터로 (1,2,3,4,6,8,12,16,24,48)

    for(int i=0; i<v.size()/2; i++) {
        
        if(v[i] < 3) continue;

        // 가로세로 결정
        int x = total_tile_num / v[i];
        int y = v[i];

        // 레드 색상도 약수를 구해서.
        arr_red = {1,2,3,4,6,8,12,24};
        for (int j=0; j<;j++) {
            int r_x = red/arr_red[j];
            int r_y = arr_red[j];

            if(x -2 = r_x && y-2 r_y) {
                answer.push_back(x);
                answer.push_back(y);
            }
        }
    }
    

}