#include <iostream>
#include <map>
#include <string>

using namespace std;

template <typename K, typename V>
void print_map(map<K,V>& m) {
    for (auto itr = m.begin(); itr != m.end(); itr++) {
        cout << itr->first << " : " << itr->second << endl;
    }
}

int main() {

    map<string, double> pitcher_list;


// 아래는 insert의 세가지 방법

    // map의 insert 함수는 pair 객체로 타입을 지정하고, 인자로 받습니다.
    pitcher_list.insert(pair<string,double>("박세웅",2.23));
    pitcher_list.insert(pair<string,double>("해커",2.93));
    pitcher_list.insert(pair<string,double>("피어밴드",2.95));
  
    // 타입을 지정하지 않아도 간단히 make_pair로 페어 객체를 만들 수 있음.
    pitcher_list.insert(make_pair("차우찬", 3.04));
    pitcher_list.insert(make_pair("정원준", 3.07));
    pitcher_list.insert(make_pair("헥터", 3.09));

    // insert를 안쓰고 추가하는 방법
    pitcher_list["니퍼트"] = 3.56;
    pitcher_list["박종훈"] = 3.76;
    pitcher_list["켈리"] = 3.90;
    
    print_map(pitcher_list);

    cout << "박세웅 방어율은? :: " << pitcher_list["박세웅"] << endl;

    return 0;
}