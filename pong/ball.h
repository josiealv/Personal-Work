#ifndef BALL_H
#define BALL_H
#include <iostream>
enum dir{STOP=0, LEFT=1, UPLEFT=2, DOWNLEFT=3, RIGHT=4, UPRIGHT=5, DOWNRIGHT=6};
class Ball
{
    public:
        Ball(int posx, int posy); //constructor for ball that gives its start position
        void changeDir (dir d);
        void randomDir(); //produces a random direction 
        int getx(); //getters for x, y, and direction
        int gety();
        dir getDirection ();
        void Move ();
        friend std::ostream& operator <<(std::ostream& o, const Ball& b);
        void reset(); //resets the ball to its original position from the start of the game

    private:
        int x, y; //stores position of the ball on the screen
        int ogx, ogy; //stores the original ball position
        dir direction;    
};
#endif