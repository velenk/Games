#ifndef _SNAKE_H_
#define _SNAKE_H_

//0 = ' '
//1 = *
//2 = #
//3 = $
const int k_Size = 20;
int i, j;
class Map;

class Snake {
public:
  Snake(int a, Map& map0);
  void Write(Map& map0);
private:
  int lenth;
  int x, y;
  int snake[k_Size*k_Size][2];
};

class Map {
friend Snake;
public:
  void Initialize() {
    for (i = 1; i < k_Size+1; i++) {
      for (j = 1; j < k_Size+1; j++) {
        map[i][j] = ' ';
      }
    }
    for (i = 0; i < k_Size+1; i++) {
      map[0][i] = map[k_Size+1][i] = '-';
    }
    for (i = 0; i < k_Size+2; i++) {
      map[i][0] = map[i][k_Size+1] = '|';
    }
  }
  void display();
private:
  char map[k_Size+2][k_Size+2];
  int head = 0;
  int tail = 0;
};

Snake::Snake(int a, Map& map0) : x(1), y(a), lenth(a) {
  for (i = 0; i < k_Size*k_Size; i++) {
    snake[i][0] = snake[i][1] = 0;
  }
  for (i = 0; i < a; i++) {
    snake[i][0] = i;
    snake[i][1] = 1;
    map0.map[1][i+1] = '*';
  }
  map0.map[1][a] = '#';
  map0.head = a;
}

void Map::display() {
  system("cls");
  for (i = 0; i < k_Size+2; i++) {
    std::cout << "    ";
    for (j = 0; j < k_Size+2; j++) {
      std::cout << map[i][j] << " ";
    }
    std::cout << std::endl;
  }
}
#endif
