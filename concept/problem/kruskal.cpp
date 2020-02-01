// 가장 적은 비용으로 노드 연결.
// 간선 정보를 오름차순으로 정렬한 후, 사이클이 생기지 않는 간선들을 모아 최단거리를 뽑아내는 방법.

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int getParent(int set[], int a) {
    if(set[a] == a) return a;
    return set[a] = getParent(set, a);
}

bool find (int set[], int a, int b) {
    int x = getParent(set, a);
    int y = getParent(set, b);
    if(x==y) {
        return 1;
    } else {
        return 0;
    }
}

void unionParent(int set[], int a, int b) {
    int x = getParent(set, a);
    int y = getParent(set, b);

    if(x<y) set[b] = a;
    else set[a] = b;

}

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

int main() {
    int n=7;
    int m=11;

    vector<Edge> v;
    v.push_back(Edge(1,7,12));
    v.push_back(Edge(1,7,12));
    v.push_back(Edge(1,7,12));
    v.push_back(Edge(1,7,12));
    v.push_back(Edge(1,7,12));
    v.push_back(Edge(1,7,12));
    v.push_back(Edge(1,7,12));
    v.push_back(Edge(1,7,12));
    v.push_back(Edge(1,7,12));
    v.push_back(Edge(1,7,12));
    v.push_back(Edge(1,7,12));
    v.push_back(Edge(1,7,12));

    // 간선거리 최소비용으로 정렬
    sort(v.begin(), v.end());

    // 각 노드의 부모들 1로 초기화
    int set[n];
    for( int i=0;i<n;i++ ) {
        set[i] = i;
    }

    int sum = 0;
    for ( int i = 0; i<v.size(); i++ ) {
        // 사이클이 생기지 않으면(부모가 다르다면), 그 간선을 더해줌.
        if(!find(set, v[i].node[0]-1, v[i].node[1]-1)) {
            sum += v[i].distance;
            unionParent(set, v[i].node[0]-1, v[i].node[1]-1);
        }
    }

}

/*
    1. 두 노드와 간선의 정보를 담을 수 있는 클래스(edge) 생성.
    2. 간선에 대해 오름차순으로 정렬을 합니다.
    3. 각 엗지에 대해, 두 노드의 부모가 같은지를 파악합니다.
    4. 같지 않다면(싸이클이 만들어지지 않는 조건) 간선(비용)을 합에 더해주면 됩니다.
    4-1. 이 과정에서 부모가 같은지 여부를 알 수 있는 FindParent()함수를 만들어줍니다.
    5. 비용에 더한 후, 두 노드의 부모를 같게 해줍니다.
    5-1. UnionParent()를 통해 두 노드의 부모를 합쳐줍니다.
    
 */