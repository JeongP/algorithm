/*

    방법을 몰라, 검색을 통해 해결...
    
    [배운것]
    1. string 각 자리에 가중치 주기.
    2. 내림차순?

 */

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

const int MAX = 26;
int N;
vector<string> v;
int alphabet[MAX];
int answer = 0;

void input() {
    cin >> N;
    for(int i=0;i<N;i++) {
        string x;
        cin >> x;
        v.push_back(x);
    }
}

// void prt() {
//     for(int i=0;i<10;i++) {
//         cout << alphabet[i] << " ";
//     }
// }

bool desc(int a,int b) {
    return a > b;
}

void sol () {
    // 각 문자열에 대해 판별.
    for(int i=0;i<N;i++) {
        string word = v[i];
        int word_len = word.length();
        // 일의 자리부터 최대 자리까지 돌면서 가중치를 알파벳 배열에 넣어주기.
        int pow = 1;
        for(int j=word_len-1;j>=0;j--) {
            // 각 알파벳의 index 찾아주고
            int tmp = v[i][j] - 'A';
            alphabet[tmp] = alphabet[tmp] + pow;
            pow *= 10;
        }
    }
    
    sort(alphabet, alphabet+MAX, desc);
    // prt();
    int num = 9;
    for(int i=0;i<MAX;i++) {
        if(alphabet[i] == 0 ) break;
        answer = answer + alphabet[i] * num;
        num--;
    }
    cout << answer << endl;
}


int main () {
    input();
    sol();
    return 0;
}