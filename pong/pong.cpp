#include <iostream>
#include <time.h>
#include "ball.h"
using namespace std;
int main()
{
  Ball ball(0, 0);
  cout << ball << endl;
  ball.randomDir();
  cout << ball << endl; 
  ball.Move();
  cout << ball << endl;
  ball.randomDir();
  ball.Move();
  cout << ball << endl;

  return 0;
}