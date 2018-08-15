#include <iostream>
#include <conio.h>
#include <time.h>
#include <stdlib.h>
#include "snake.h"
int main() {
  Map m;
  m.Initialize();
  Snake s(5, m);
  do {
  m.display();
  s.Move(m);
  } while (g_GameOver);
  return 0;
}

