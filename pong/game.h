#ifndef GAME_H
#define GAME_H
#include "paddle.h"
#include "ball.h"
class Game
{
    public:
        Game (int w, int h);
        ~Game();
        void score_incr(Paddle* player);
        void Draw();
        void input();
        void Collide();
        void Play();
    private:
        int width, height; 
        int p1_score, p2_score;
        char up_p1, down_p1, up_p2, down_p2; //keys to control the player on the screen
        bool end; //will quit game if true
        Ball* ball;
        Paddle* p1;
        Paddle* p2;
};
#endif
