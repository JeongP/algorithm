#include <iostream>
#include <algorithm>
using namespace std;

class Student {
public:
    string name;
    int score;

    Student (string name, int score) {
        this->name = name; 
        this->score = score;
    }

    bool operator < (Student &student) {
        return this->score < student.score;
    }
};

int main () {
    

}