#include <string>
#include <vector>

using namespace std;

vector<int> solution(int brown, int red) {
    vector<int> answer;

    for(int sero=3;sero<=brown;sero++) {
        int garo = (brown-(sero*2))/2 + 2;
        // 세로가 가로보다 긴 경우.
        if(sero > garo) break;
        if(red == (sero-2) * (garo-2)) {
            answer.push_back(garo);
            answer.push_back(sero);
            break;
        }
    }

    return answer;
}