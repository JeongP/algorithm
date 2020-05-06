#include <iostream>
#include <vector>
#include <string>

using namespace std;

char cube[12][9];
int n;
int T;
vector <string> cmd;

void input() {
   cin >> n;
   for (int i = 0; i < n; i++) {
      string tmp;
      cin >> tmp;
      cmd.push_back(tmp);
   }
}

void setCube() {
   for (int i = 0; i < 12; i++)
      for (int j = 0; j < 9; j++) {
         if (0 <= i && i <= 2 && 3 <= j && j <= 5)
            cube[i][j] = 'o';
         else if (3 <= i && i <= 5 && 0 <= j && j <= 2)
            cube[i][j] = 'g';
         else if (3 <= i && i <= 5 && 3 <= j && j <= 5)
            cube[i][j] = 'w';
         else if (3 <= i && i <= 5 && 6 <= j && j <= 8)
            cube[i][j] = 'b';
         else if (6 <= i && i <= 8 && 3 <= j && j <= 5)
            cube[i][j] = 'r';
         else if (9 <= i && i <= 11 && 3 <= j && j <= 5)
            cube[i][j] = 'y';
      }
}
void printCube() {
   for (int i = 3; i < 6; i++) {
      for (int j = 3; j < 6; j++) {
         cout << cube[i][j];
      }
      cout << endl;
   }
}

void U() {
   //inside
   int tmp34 = cube[3][4];
   int tmp35 = cube[3][5];
   cube[3][5] = cube[3][3];
   cube[3][4] = cube[4][3];
   cube[3][3] = cube[5][3];
   cube[4][3] = cube[5][4];
   cube[5][3] = cube[5][5];
   cube[5][4] = cube[4][5];
   cube[5][5] = tmp35;
   cube[4][5] = tmp34;
   
   //outside
   int tmp23 = cube[2][3];
   int tmp24 = cube[2][4];
   int tmp25 = cube[2][5];
   cube[2][5] = cube[3][2];
   cube[2][4] = cube[4][2];
   cube[2][3] = cube[5][2];
   cube[3][2] = cube[6][3];
   cube[4][2] = cube[6][4];
   cube[5][2] = cube[6][5];
   cube[6][3] = cube[5][6];
   cube[6][4] = cube[4][6];
   cube[6][5] = cube[3][6];
   cube[5][6] = tmp25;
   cube[4][6] = tmp24;
   cube[3][6] = tmp23;
}

void D() {
   //inside
   int tmp94 = cube[9][4];
   int tmp95 = cube[9][5];
   cube[9][5] = cube[9][3];
   cube[9][4] = cube[10][3];
   cube[9][3] = cube[11][3];
   cube[10][3] = cube[11][4];
   cube[11][3] = cube[11][5];
   cube[11][4] = cube[10][5];
   cube[11][5] = tmp95;
   cube[10][5] = tmp94;
   
   //outside
   int tmp03 = cube[0][3];
   int tmp04 = cube[0][4];
   int tmp05 = cube[0][5];
   cube[0][5] = cube[5][8];
   cube[0][4] = cube[4][8];
   cube[0][3] = cube[3][8];
   cube[5][8] = cube[8][3];
   cube[4][8] = cube[8][4];
   cube[3][8] = cube[8][5];
   cube[8][3] = cube[3][0];
   cube[8][4] = cube[4][0];
   cube[8][5] = cube[5][0];
   cube[3][0] = tmp05;
   cube[4][0] = tmp04;
   cube[5][0] = tmp03;
}

void F() {
   //inside
   int tmp64 = cube[6][4];
   int tmp65 = cube[6][5];
   cube[6][5] = cube[6][3];
   cube[6][4] = cube[7][3];
   cube[6][3] = cube[8][3];
   cube[7][3] = cube[8][4];
   cube[8][3] = cube[8][5];
   cube[8][4] = cube[7][5];
   cube[8][5] = tmp65;
   cube[7][5] = tmp64;

   //outside
   int tmp53 = cube[5][3];
   int tmp54 = cube[5][4];
   int tmp55 = cube[5][5];
   cube[5][5] = cube[5][2];
   cube[5][4] = cube[5][1];
   cube[5][3] = cube[5][0];
   cube[5][2] = cube[9][3];
   cube[5][1] = cube[9][4];
   cube[5][0] = cube[9][5];
   cube[9][3] = cube[5][8];
   cube[9][4] = cube[5][7];
   cube[9][5] = cube[5][6];
   cube[5][8] = tmp55;
   cube[5][7] = tmp54;
   cube[5][6] = tmp53;
}

void B() {
   //inside
   int tmp04 = cube[0][4];
   int tmp05 = cube[0][5];
   cube[0][5] = cube[0][3];
   cube[0][4] = cube[1][3];
   cube[0][3] = cube[2][3];
   cube[1][3] = cube[2][4];
   cube[2][3] = cube[2][5];
   cube[2][4] = cube[1][5];
   cube[2][5] = tmp05;
   cube[1][5] = tmp04;

   //outside
   int tmp33 = cube[3][3];
   int tmp34 = cube[3][4];
   int tmp35 = cube[3][5];
   cube[3][5] = cube[3][8];
   cube[3][4] = cube[3][7];
   cube[3][3] = cube[3][6];
   cube[3][8] = cube[11][3];
   cube[3][7] = cube[11][4];
   cube[3][6] = cube[11][5];
   cube[11][3] = cube[3][2];
   cube[11][4] = cube[3][1];
   cube[11][5] = cube[3][0];
   cube[3][0] = tmp33;
   cube[3][1] = tmp34;
   cube[3][2] = tmp35;

}

void L() {
   //inside
   int tmp31 = cube[3][1];
   int tmp32 = cube[3][2];
   cube[3][2] = cube[3][0];
   cube[3][1] = cube[4][0];
   cube[3][0] = cube[5][0];
   cube[4][0] = cube[5][1];
   cube[5][0] = cube[5][2];
   cube[5][1] = cube[4][2];
   cube[5][2] = tmp32;
   cube[4][2] = tmp31;

   //outside
   int tmp33 = cube[3][3];
   int tmp43 = cube[4][3];
   int tmp53 = cube[5][3];
   cube[3][3] = cube[0][3];
   cube[4][3] = cube[1][3];
   cube[5][3] = cube[2][3];
   cube[0][3] = cube[9][3];
   cube[1][3] = cube[10][3];
   cube[2][3] = cube[11][3];
   cube[9][3] = cube[6][3];
   cube[10][3] = cube[7][3];
   cube[11][3] = cube[8][3];
   cube[6][3] = tmp33;
   cube[7][3] = tmp43;
   cube[8][3] = tmp53;
}

void R() {
   //inside
   int tmp37 = cube[3][7];
   int tmp38 = cube[3][8];
   cube[3][8] = cube[3][6];
   cube[3][7] = cube[4][6];
   cube[3][6] = cube[5][6];
   cube[4][6] = cube[5][7];
   cube[5][6] = cube[5][8];
   cube[5][7] = cube[4][8];
   cube[5][8] = tmp38;
   cube[4][8] = tmp37;

   //outside
   int tmp35 = cube[3][5];
   int tmp45 = cube[4][5];
   int tmp55 = cube[5][5];
   cube[3][5] = cube[6][5];
   cube[4][5] = cube[7][5];
   cube[5][5] = cube[8][5];
   cube[6][5] = cube[9][5];
   cube[7][5] = cube[10][5];
   cube[8][5] = cube[11][5];
   cube[9][5] = cube[0][5];
   cube[10][5] = cube[1][5];
   cube[11][5] = cube[2][5];
   cube[0][5] = tmp35;
   cube[1][5] = tmp45;
   cube[2][5] = tmp55;
}

void solution() {
   for (int i = 0; i < cmd.size(); i++) {
      char c = cmd[i][0];
      char dir = cmd[i][1];

      if (c == 'U') {
         if (dir == '+') {
            U();
         }
         else if (dir == '-') {
            U();
            U();
            U();
         }
      }
      else if (c == 'D') {
         if (dir == '+') {
            D();
         }
         else if (dir == '-') {
            D();
            D();
            D();
         }
      }
      else if (c == 'F') {
         if (dir == '+') {
            F();
         }
         else if (dir == '-') {
            F();
            F();
            F();
         }
      }
      else if (c == 'B') {
         if (dir == '+') {
            B();
         }
         else if (dir == '-') {
            B();
            B();
            B();
         }
      }
      else if (c == 'L') {
         if (dir == '+') {
            L();
         }
         else if (dir == '-') {
            L();
            L();
            L();
         }
      }
      else if (c == 'R') {
         if (dir == '+') {
            R();
         }
         else if (dir == '-') {
            R();
            R();
            R();
         }
      }
   }
}

int main(void) {
   cin >> T;
   while (T-- > 0) {
      cmd.clear();
      setCube();
      input();
      solution();
      printCube();
   }
   return 0;
}