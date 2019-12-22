#include <iostream>
#include <time.h>
#include <curses.h>
#include "ball.h"
#include "game.h"
#include "paddle.h"
using namespace std;
int main()
{
  Game g(40, 20);
  g.Play();
  return 0;
}