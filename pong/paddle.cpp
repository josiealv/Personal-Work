#include "paddle.h"
#include <iostream>
using namespace std;

Paddle::Paddle()
{
    x=0;
    y=0;
}
Paddle::Paddle(int posx, int posy): ogx(posx), ogy(posy)
{
    x=posx;
    y=posy;
}
void Paddle::reset() {x=ogx; y=ogy;}
int Paddle::getx() {return x;}
int Paddle::gety() {return y;}
void Paddle::MoveUp() {y--;}
void Paddle::MoveDown() {y++;}
