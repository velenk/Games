#include <iostream>
#include <conio.h>
#include <time.h>
#include <stdlib.h>
#include "snake.h"

void Start();
void End();

int main() {
  Start();
  Map m;
  m.Initialize();
  Snake s(5, m);
  do {
  m.Display();
  s.Move(m);
  } while (g_GameOver);
  End();
  return 0;
}

void Start() {
  std::cout << "\n\n\n          CramSnake\n\n" << "      press any key to start" <<std::endl;
  getch();
}

void End() {
  system("cls");
  std::cout << "\n\n\n           You Lose\n\n" << "      press any key to exit" << std::endl;
  getch();
}

