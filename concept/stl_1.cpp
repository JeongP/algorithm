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

    bool operator <(Student &student) {
        return this->score < student.score;
    }
};

bool cmp (int a, int b) {
    return a > b;
}

int main () {
     
    Student students[] = {
        Student("jp",97),
        Student("sb",45),
        Student("jw",66),
        Student("dm",72),
        Student("ih",88)
    };
    
    // sort(students, students+5);
    for (int i=0; i<5; i++) {
        cout << students[i].name << " ";
    }
    return 0;
}
