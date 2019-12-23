#include "ball.h"
#include <iostream>
using namespace std;

Ball::Ball(int posx, int posy): ogx(posx), ogy(posy) //constructor for ball that gives its start position
{
    x=posx;
    y=posy;
    direction = STOP;
}
void Ball::reset()
{
    x=ogx;
    y=ogy;
    direction = STOP;
}
void Ball::changeDir (dir d)
{
    direction = d;
}
void Ball::randomDir()
{
    direction = (dir) ((rand()%6)+1); //produces random numbers from 1 to 6 for direction
}
int Ball::getx () {return x;} //getters for x, y, and direction
int Ball::gety() {return y;}
dir Ball::getDirection (){return direction;}

void Ball::Move () //get out the way, get out the way!
{
      switch (direction) //we start at the top
      {
        case STOP:
          break;
        case LEFT:
          x--;
          break;
        case RIGHT:
          x++;
          break;
        case UPLEFT:
          x--; 
          y--;
          break;
        case DOWNLEFT:
          x--;
          y++;
          break;
        case UPRIGHT:
          x++;
          y--;
          break;
        case DOWNRIGHT:
          x++;
          y++;
          break;
        default:
          break;             
      }
}
