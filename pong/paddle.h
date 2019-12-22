#ifndef PADDLE_H
#define PADDLE_H
#include <iostream>
class Paddle
{
    public:
        Paddle ();
        Paddle (int posx, int posy);
        void reset();
        int getx();
        int gety();
        void MoveUp();
        void MoveDown();
        friend std::ostream& operator <<(std::ostream& o, const Paddle& p);
    private:
        int x, y; //stores position of the ball on the screen
        int ogx, ogy; //stores the original ball position
};
#endif