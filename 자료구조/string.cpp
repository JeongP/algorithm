#include <iostream>
#include <string>
using namespace std;

int main () {
    // string s1 = "hello my name is..";
    // cout << s1;
    // // s1.resize(8);
    // // cout << s1;
    
    // cout << s1.substr(5) << endl;
    // cout << s1.substr(5,10) << endl;

    // // replace
    // string s2 = "JP";
    // cout << s1.replace(4,3,s2);

    // // compare
    // string sc1 = "Brav";
    // string sc2 = "Brbv";
    // string sc3 = "Br";
    // string sc4 = "ra";

    // cout << sc1.compare(sc2) << endl;
    // cout << sc1.compare(0,2,sc3) << endl;
    // cout << sc1.compare(1,2,sc4,0,2);


    // // copy
    // string str1 = "BlockDMask";
    // char arr[10];
    // int len = str1.copy(arr,5,3);
    // cout << len;

    // find
    string a = "BlogBlogBlog";
    cout << a.find("Blog",10);


    // string을 내림차순으로 sorting 하기.
    string s = "abdknzpdknfz";
    sort(s.begin(),s.end(),greater<int>());
    cout << s;
}