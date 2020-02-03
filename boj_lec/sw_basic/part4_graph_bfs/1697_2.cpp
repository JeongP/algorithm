#include <iostream>

#include <queue>

using namespace std;

 

const int MAX = 100000 + 1;

bool visited[MAX];

 

int minSecond(int N, int K)

{

        queue<pair<int, int>> q;

 

        q.push(make_pair(N, 0));

        visited[N] = true;

 

        while (!q.empty())

        {

                 int curLoc = q.front().first;

                 int curSec = q.front().second;

                 q.pop();

 

                 if (curLoc == K) //목적지 도달 시 break

                         return curSec;

 

                 //세 가지 경우의 수

                 //이미 방문한 지점은 큐에 넣지 않는다

                 if (curLoc + 1 < MAX && !visited[curLoc + 1])

                 {

                         q.push(make_pair(curLoc + 1, curSec + 1));

                         visited[curLoc + 1] = true;

                 }

                 if (curLoc - 1 >= 0 && !visited[curLoc - 1])

                 {

                         q.push(make_pair(curLoc - 1, curSec + 1));

                         visited[curLoc - 1] = true;

                 }

                 if (curLoc * 2 < MAX && !visited[curLoc * 2])

                 {

                         q.push(make_pair(curLoc * 2, curSec + 1));

                         visited[curLoc * 2] = true;

                 }

        }

}

 

int main(void)

{

        int N, K;

        cin >> N >> K;

 

        cout << minSecond(N, K) << "\n";

 

        return 0;

}