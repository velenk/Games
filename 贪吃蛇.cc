#include <iostream>
#include <conio.h>
#include <time.h>
#include <stdlib.h>
#include "snake.h"
int main() {
  Map map0;
  map0.Initialize();
  Snake snake0(1, map0);
  map0.display();
  return 0;
}

