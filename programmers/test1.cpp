#include <string>
#include <vector>
#include <cstdlib>
#include <iostream>
using namespace std;

vector<int> solution(vector<string> purchase) {
    vector<int> answer;
    int days[365] = {0,};
    int months[12] = {31,28,31,30,31,30,31,31,30,31,30,31};
    int lv[5] = {0,};
    //받은 날짜를 365로 변환하기.
    for(int i=0;i<purchase.size();i++) {
        // 스트링에서 데이터 뽑아주기
        string date = purchase[i].substr(5,10);
        string m = date.substr(0,2);
        string d = date.substr(3,3);
        string p = purchase[i].substr(11,10);
        
        int month = atoi(m.c_str());
        int day = atoi(d.c_str());
        int daySum = 0;
        int price = atoi(p.c_str());
        // 일 수 더해주고
        for(int j=0;j<month-1;j++) {
            daySum+=months[j];
        }
        daySum += day;
        // cout << daySum << " ";

        for(int j=daySum;j<daySum+30;j++) {
            days[j] += price;
        }
        
    }

    for(int i=0;i<365;i++) {
        if(0 <= days[i] && days[i] < 10000) {
            lv[0]++;
        }else if (10000 <= days[i] && days[i] < 20000) {
            lv[1]++;
        }else if(20000 <= days[i] && days[i] < 50000) {
            lv[2]++;
        }else if(50000 <= days[i] && days[i] < 100000) {
            lv[3]++;
        }else if(days[i] >= 100000) {
            lv[4]++;
        }
    }

    for(int i=40;i<50;i++) {
        cout << days[i] << " ";
    }

    for(int i=0;i<5;i++) {
        answer.push_back(lv[i]);
    }
    return answer;
}