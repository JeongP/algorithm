#include <iostream>

using namespace std;

const int MAX = 40000;
int T;
int N, M, x, y;
int k;
bool find_check;

void input() 
{
    ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
    cin >> T;
}

int GCD (int a, int b) {
    while(b!=0) {
        int c = a%b;
        a = b;
        b = c;
    }
    return a;
}
int LCM (int a, int b) {
    return a*b / GCD(a, b);
}

void solution () 
{
    while(T--) 
    {   
        k = 1;
        find_check = false;
        cin >> M >> N >> x >> y;
        int lcm = LCM(M,N);
        

        int mx = 1; int ny = 1;
        for(int i=2;i<=lcm;i++) {
            if(mx < M) mx +=1;
            else mx = 1;

            if(ny < N) ny += 1;
            else ny = 1;
            
            k++;

            if(mx == x && ny == y) {
                cout << k << '\n';
                find_check = true;
                break;
            }
        }
        if(!find_check) {
            cout << -1 << '\n';
        }
        
    }
}

int main () 
{
    input();
    solution();
}