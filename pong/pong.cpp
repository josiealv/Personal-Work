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
  cout << "Press any key to move the ball" << endl;
  cout << "P1:" << endl;
  cout << " 'w' is up" << endl;
  cout << " 's' is down" << endl;
  cout << "P2:" << endl;
  cout << " 'i' is up" << endl;
  cout << " 'k' is down" << endl;
  cout<< endl;
  cout<< "Press 'b' to begin" << endl;
  char b;
  cin>>b;
  if (b=='b')
  {
      g.Play();
  }
  return 0;
}