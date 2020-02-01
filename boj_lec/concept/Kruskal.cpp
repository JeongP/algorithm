#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Edge {
public:
    int node[2];
    int distance;
    Edge(int a, int b, int distance) {
        this->node[0] = a;
        this->node[1] = b;
        this->distance = distance;
    }
    bool operator <(Edge &edge) {
        return this->distance < edge.distance;
    }
};

int getParent(int p[], int x) {
    if(p[x] == x) return x;
    return p[x] = getParent(p, p[x]);
}

int unionParent(int p[], int a, int b) {
    a = getParent(p,a);
    b = getParent(p,b);

    if(a < b) p[b] = a;
    else p[a] = b;
}

bool find(int p[], int a, int b) {
    a = getParent(p,a);
    b = getParent(p,b);
    if(a==b) return 1;
    else return 0;
}


int main () {
    // edge
    int n = 7;
    // 간선
    int m = 11;

    vector<Edge> v;
    // 간선들 벡터에 담기.
    v.push_back(Edge(1,7,13));
    sort(v.begin(), v.end());

    // initial
    int set[n+1];
    for(int i=1;i<=n;i++) {
        set[i] = i;
    }

    int sum = 0;
    for(int i=0;i<v.size();i++) {
        if(!find(set, v[i].node[0], v[i].node[1])) {
            sum += v[i].distance;
            unionParent(set, v[i].node[0], v[i].node[1]);
        }
    }

    return 0;

}