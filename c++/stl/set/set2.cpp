#include <iostream>
#include <set>
#include <string>

using namespace std;

template <typename T>
void print_set(set<T>& s) {
    for( const auto& elem : s) {
        cout << elem << " " << endl;
     }
}

class Todo {
    int priority;
    string job_desc;

    public:
    Todo(int priority, string job_desc)
        : priority(priority), job_desc(job_desc) {}

    bool operator<(const Todo& t) const {
        if (priority == t.priority) {
        return job_desc < t.job_desc;
        }
        return priority > t.priority;
    }

    friend ostream& operator<<(ostream& o, const Todo& td);

};

ostream& operator<<(ostream& o, const Todo& td) {
    o << "[ 중요도: " << td.priority << "] " << td.job_desc;
    return o;
}


int main() {

    set<Todo> todos;

    todos.insert(Todo(1, "basketball"));
    todos.insert(Todo(3, "soccer"));
    todos.insert(Todo(2, "baseball"));

    print_set(todos);

    cout << " ======= " << endl;
    cout << " 야구를 끝냈다면 " << endl;
    todos.erase(todos.find(Todo(2, "baseball")));
    print_set(todos);
    
    return 0;
}