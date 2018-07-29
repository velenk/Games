//2048
#include <iostream>
#include <conio.h>
#include <string>
#include <iomanip>
using namespace std;

inline void Start();//initialize data
void Print();//print the screen
bool GameOver();//judge game state
void Work();//getchar
void NewNumber();//get new number
void MoveLine(bool reverse);//move line
void MoveColume(bool reverse);//move colume
inline void End();//exit the game

int num[4][4] = {};
int i, j;

int main() {
  Start();
  Print();
  while (true) {
    Work();
    if (GameOver())
      break;
    NewNumber();
  }
  End();
  getch();
  return 0;
}

void Start() {
  cout << " Welcome to 2048!" << endl;
  cout << "The game's objective is to slide numbered tiles on a grid to combine them to create a tile with the number 2048" << endl;
  cout << " good luck! " << endl;
  cout << "Press any key to continue" << endl;
  while (true) {
    if (getch())
      return;
  }
}

void End() {
  int x = 0;
  for (i = 0; i < 4; ++i) {
    for (j = 0; j < 4; ++j) {
      if (num[i][j] > x)
        x = num[i][j];
    }
  }
  cout << "Your max number is " << x << endl;
  cout << "Press any key to exit" << endl;
}

void Print() {
  system("cls");
  cout << endl;
  for (i = 0; i < 4; ++i) {
    for (j = 0; j < 4; ++j) {
      cout << setw(6) << num[i][j];
    }
    cout << endl << endl;
  }
  //cout << "Max:" << max_num;
}

bool GameOver() {
  for (i = 0; i < 4; ++i) {
    for (j = 0; j < 4; ++j) {
      if (num[i][j] == 0) {
        return false;
      }
    }
  }
  return true;
}

void Work() {
  int ch = getch();
  if (ch == 72) {
    MoveColume(false);
  } else if (ch == 80) {
    MoveColume(true);
  } else if (ch == 75) {
    MoveLine(false);
  } else if (ch == 77) {
    MoveLine(true);
  }
  Print();
}

void NewNumber() {
  int count = 1;
  //int count = rand() % 2 + 1;
  while (true) {
    int x = rand() % 4;
    int y = rand() % 4;
    if (num[x][y] == 0) {
      num[x][y] = (rand() % 2) * 2 + 2;
      --count;
    }
    if (count == 0) {
      break;
    }
  }
}

void MoveLine(bool reverse) {
  int j1, j2;
  for (i = 0; i < 4; ++i) {
    if (reverse) {
      j = 3;
    } else {
      j = 0;
    }
    j1 = j;
    while (j1 >= 0 && j1 < 4) {
      if (reverse) {//right
        for (j2 = 3; j2 > 3 - j1; --j2) {
          if (num[i][j2-1] != 0) {
            if (num[i][j2] == 0) {
              num[i][j2] = num[i][j2-1];
              num[i][j2-1] = 0;
            } else if (num[i][j2] == num[i][j2-1]) {
              num[i][j2] *= 2;
              num[i][j2-1] = 0;
            }
          }
        }
        --j1;
      } else {//left
        for (j2 = 0; j2 < 3 - j1; ++j2) {
          if (num[i][j2+1] != 0) {
            if (num[i][j2] == 0) {
              num[i][j2] = num[i][j2+1];
              num[i][j2+1] = 0;
            } else if (num[i][j2] == num[i][j2+1]) {
              num[i][j2] *= 2;
              num[i][j2+1] = 0;
            }
          }
        }
        ++j1;
      }
    }
  }
}

void MoveColume(bool reverse) {
  int i1, i2;
  for (j = 0; j < 4; ++j) {
    if (reverse) {
      i = 3;
    } else {
      i = 0;
    }
    i1 = i;
    while (i1 >= 0 && i1 < 4) {
      if (reverse) {//down
        for (i2 = 3; i2 > 3 - i1; --i2) {
          if (num[i2-1][j] != 0) {
            if (num[i2][j] == 0) {
              num[i2][j] = num[i2-1][j];
              num[i2-1][j] = 0;
            } else if (num[i2][j] == num[i2-1][j]) {
              num[i2][j] *= 2;
              num[i2-1][j] = 0;
            }
          }
        }
        --i1;
      } else {//up
        for (i2 = 0; i2 < 3 - i1; ++i2) {
          if (num[i2+1][j] != 0) {
            if (num[i2][j] == 0) {
              num[i2][j] = num[i2+1][j];
              num[i2+1][j] = 0;
            } else if (num[i2][j] == num[i2+1][j]) {
              num[i2][j] *= 2;
              num[i2+1][j] = 0;
            }
          }
        }
        ++i1;
      }
    }
  }
}
