#ifndef _SNAKE_H_
#define _SNAKE_H_

//default = ' '
//snake = *
//snake head = #
//apple = @
const int k_Size = 20;
const int k_Time = 100;
bool g_GameOver = true;
int i, j;
class Map;
//class snake
class Snake {
public:
  Snake(int a, Map& map0);
  void Write(Map& map0);//write snake to map
  void Move(Map& map0);//move snake
private:
  int lenth;
  char direction;//the direction of going ahead
  int x, y;//head position
  int snake[k_Size*k_Size][2];//snake body
};
//class map
class Map {
friend Snake;
public://initialize map
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
  void Set(int x, int y, char c) {
    map[x][y] = c;
  }
  void display();//display to screen
private:
  char map[k_Size+2][k_Size+2];//map's character
  int head = 0;
  int tail = 0;
};
//snake's structure
Snake::Snake(int a, Map& map0) : x(1), y(a), lenth(a), direction(77) {
  for (i = 0; i < k_Size*k_Size; i++) {
    snake[i][0] = snake[i][1] = 0;
  }
  for (i = 0; i < a; i++) {
    snake[i][0] = 1;
    snake[i][1] = i + 1;
    map0.map[1][i+1] = '*';
  }
  map0.map[1][a] = '#';
  map0.head = a-1;
}
//move snake
void Snake::Move(Map& map0) {
  bool getchar = true;
  auto start = clock();
  char key = direction;
  while (getchar = (clock() - start < k_Time) && !kbhit());//time run out or hit keyboard
  if (getchar){
    getch();
    key = getch();
  }
  getchar = true;
  if (key == ' ') {
    while (!kbhit()) { };
  }//pause game by space and continue by any key
  if (key == 72 || key == 75 || key == 77 || key == 80) {
    direction = key;
  }
  int x1 = snake[map0.head][0];
  int y1 = snake[map0.head][1];
  map0.Set(x1, y1, '*');
  switch (direction) {
    case 72 : x1 += 1; break;//up
    case 80 : x1 -= 1; break;//down
    case 75 : y1 -= 1; break;//left
    case 77 : y1 += 1;//right
  }
  map0.head = (map0.head + 1) % (k_Size * k_Size);//update head
  snake[map0.head][0] = x1;
  snake[map0.head][1] = y1;//update snake
  if (map0.map[x1][y1] != ' ' && map0.map[x1][y1] != '@') {
    g_GameOver = false;
  }
  if (map0.map[x1][y1] != '@') {//eat apple
    map0.tail = (map0.tail + 1) % (k_Size * k_Size);//update tail
  } else {
    lenth += 1;
    if (lenth >= k_Size * k_Size) {
      g_GameOver = false;
    }
  }
  map0.Set(x1, y1, '#');
}
//display map to screen
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
