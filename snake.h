#ifndef _SNAKE_H_
#define _SNAKE_H_
//#define _TEST_

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
  void Display();//display to screen
  void NewApple();
private:
  char map[k_Size+2][k_Size+2];//map's character
  int head = 0;
  int tail = 0;
};
//snake's structure
Snake::Snake(int a, Map& map0) : x(1), y(a), lenth(a), direction('d') {
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
  map0.NewApple();
}
//move snake
void Snake::Move(Map& map0) {
  bool get = true;
  auto start = clock();
  char key = direction;
  while ((get = (clock() - start < k_Time)) && !kbhit()) { }//time run out or hit keyboard
  #ifdef _TEST_
  std::cout << get << std::endl;
  #endif
  if (get){
    key = getch();
  }
  #ifdef _TEST_
  std::cout << key << std::endl;
  #endif
  if (key == ' ') {
    char a = '1';
    while (a != ' ') {
      a = getch();
    };
  }//pause game by space and continue by any key
  if (key == 'w' || key == 's' || key == 'a' || key == 'd') {
    direction = key;
    #ifdef _TEST_
    std::cout << direction << std::endl;
    #endif
  }
  int x1 = snake[map0.head][0];
  int y1 = snake[map0.head][1];
  map0.Set(x1, y1, '*');
  switch (direction) {
    case 'w' : x1 -= 1; break;//up
    case 's' : x1 += 1; break;//down
    case 'a' : y1 -= 1; break;//left
    case 'd' : y1 += 1;//right
  }
  #ifdef _TEST_
  std::cout << x1 << " " << y1 << std::endl;
  #endif
  map0.head = (map0.head + 1) % (k_Size * k_Size);//update head
  snake[map0.head][0] = x1;
  snake[map0.head][1] = y1;//update snake
  if (map0.map[x1][y1] != ' ' && map0.map[x1][y1] != '@') {
    g_GameOver = false;
  }
  if (map0.map[x1][y1] != '@') {//don't eat apple
    map0.Set(snake[map0.tail][0], snake[map0.tail][1], ' ');
    map0.tail = (map0.tail + 1) % (k_Size * k_Size);//update tail
  } else {//eat apple
    lenth += 1;
    if (lenth >= k_Size * k_Size) {
      g_GameOver = false;
    }
    map0.NewApple();
  }
  map0.Set(x1, y1, '#');
}
//display map to screen
void Map::Display() {
  system("cls");
  for (i = 0; i < k_Size+2; i++) {
    std::cout << "    ";
    for (j = 0; j < k_Size+2; j++) {
      std::cout << map[i][j] << " ";
    }
    std::cout << std::endl;
  }
}
//make a new apple
void Map::NewApple() {
  int x2 = 0, y2 = 0;
  srand(time(0));
  while (map[x2][y2] != ' ') {
    x2 = rand() % k_Size + 1;
    y2 = rand() % k_Size + 1;
  }
  Set(x2, y2, '@');
}
#endif
