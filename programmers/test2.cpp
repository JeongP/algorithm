#include <string>
#include <vector>
#include <map>
#include <iostream>
using namespace std;

string l[100020][4] = {"",};

int solution(vector<string> ip_addrs, vector<string> langs, vector<int> scores) {
    int answer = -1;
    map<string,int> m;
    // 언어 관련 배열
    
    int people = 0;


    // 각 아이피마다 몇명있는지.    
    for(int i=0;i<ip_addrs.size();i++) {
        // ip 주소가 등록된게 없다면
        if(m.find(ip_addrs[i]) == m.end()) {
            m.insert(make_pair(ip_addrs[i],1));
        }else {
            m[ip_addrs[i]]++;
        }
    }


    for(int i=0;i<ip_addrs.size();i++) {
        if(m[ip_addrs[i]] == 4) continue;
        if(m[ip_addrs[i]] == 3) {
            if(langs[i] == "C" || langs[i] == "C++" || langs[i] == "C#") {
                l[ip_addrs[i]][0] = "";
            }else if(langs[i] == "Java") {
                
            }else if(langs[i] == "JavaScript") {
                
            }else if(langs[i] == "Python3") {
                
            }
        }else if(m[ip_addrs[i]] == 2) {
            
        }
    }


    return answer;
}