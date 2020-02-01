#include <iostream>
#include <vector>
using namespace std;

int main () {
    vector<string> phonebook = {"119", "97674223", "1195524421"};

    for ( int i=0;i<phonebook.size();i++) {
        for(int j=0;j<phonebook.size();j++) {
            if(phonebook[i].length() > phonebook[j].length()) continue;
            else {
                for(int k=0;k<phonebook[i].length();k++) {
                    if(phonebook[k]!=phonebook[j]) return true;
                }
                return false;
            }
        }
    }
}
