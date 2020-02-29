#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
#include<set>
 
#define endl "\n"
#define MAX 8
using namespace std;
 
int N, M;
int Arr[MAX];
bool Select[MAX];
 
vector<int> V;
set<string> Visit;
 
void Input()
{
    cin >> N >> M;
    for (int i = 0; i < N; i++)
    {
        cin >> Arr[i];
    }
    sort(Arr, Arr + N);
}
 
bool Duplicate()
{
    string Temp = "";
    for (int i = 0; i < V.size(); i++)
    {
        char A = V[i] + '0';
        Temp = Temp + A;
    }
 
    if (Visit.find(Temp) == Visit.end())
    {
        Visit.insert(Temp);
        return false;
    }
    else
    {
        return true;
    }
}
 
void DFS(int Cnt)
{
    if (Cnt == M)
    {
        if (Duplicate() == false)
        {
            for (int i = 0; i < V.size(); i++)
            {
                cout << V[i] << " ";
            }
            cout << endl;
        }
        return;
    }
 
    for (int i = 0; i < N; i++)
    {
        if (Select[i] == true) continue;
        Select[i] = true;
        V.push_back(Arr[i]);
        DFS(Cnt + 1);
        V.pop_back();
        Select[i] = false;
    }
}
 
void Solution()
{
    DFS(0);
}
 
void Solve()
{
    Input();
    Solution();
}
 
int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
 
//    freopen("Input.txt", "r", stdin);
    Solve();
 
    return 0;
}

