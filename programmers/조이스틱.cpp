#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(string name) {
    int answer = 0;
    int point = 0;
    string compare;

    for(int i = 0; i < name.length(); i ++) compare += "A";

    while(compare != name) {
        int next = 0; int rightAnswer = 0; int leftAnswer = 0;

        for(int i=0;i<name.length();i++) {
            if(point + i < name.length()) rightAnswer = point + i;
            else rightAnswer = point + i - name.length();

            if(point - i >= 0) leftAnswer = point - i;
            else leftAnswer = point - i + name.length();

            if(compare[rightAnswer] != name[rightAnswer]) next = rightAnswer;
            else if(compare[leftAnswer] != name[leftAnswer]) next = leftAnswer;
            else continue;

            answer += i;
            answer += min(name[next]-'A', 'Z'+1 - name[next]);
            compare[next] = name[next];
            break;
        }
        point = next;
    }
    return answer;
}