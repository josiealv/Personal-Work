#include "game.h"
#include <time.h>
#include <curses.h>
#include <iostream>
using namespace std;

Game::Game (int w, int h): width (w), height (h)
{
    srand(time (NULL));
    end=false;
    up_p1 = 'w';
    up_p2 = 'i';
    down_p1 = 's';
    down_p2 = 'k'; 
    p1_score =0;
    p2_score=0;
    ball = new Ball (w/2, h/2); //this way ball starts in the middle
    p1 = new Paddle (1, h/2-3); //paddles starts against the walls
    p2 = new Paddle (w-2, h/2-3);
}
Game::~Game()
{
    delete ball;
    delete p1;
    delete p2;
}
void Game::score_incr(Paddle* player)
{
    if (player == p1) 
    {
        p1_score++;
    }
    else
    {
        p2_score++;
    }
    ball->reset(); //resets game if a player scores ie wins
    p1->reset();
    p2->reset();
}
int Game::kbhit() //detects if the keyboard has been hit 
{
    int get = getch();

    if (get != ERR) 
    {
        ungetch(get);
        return 1;
    } 
    else 
    {
        return 0;
    }
}
void Game::input()
{
    ball->Move();
    int p1y = p1->gety();
    int p2y = p2->gety();
    initscr();
    cbreak();
    noecho();
    nodelay(stdscr, TRUE);
    scrollok(stdscr, TRUE);
    if (kbhit())
    {
        char input = getchar();
        if (input ==up_p1)
        {
            if(p1y>0)
            {
                p1->MoveUp();
            }
        }
        if (input==up_p2)
        {
            if (p2y>0)
            {
                p2->MoveUp();
            }
        }
        if (input==down_p1)
        {
            if (p1y+4 < height) //cause we have 4 segements
            {
                p1->MoveDown();
            }
        }
        if (input==down_p2)
        {
            if (p2y+4 < height)
            {
                p2->MoveDown();
            }
        }
        if (ball->getDirection()==STOP) //randomize direction of ball if we are at the start of the game
        {
            ball->randomDir();
        }
        if (input=='q')
        {
            end=true;
        }
    }
    endwin();
}
void Game::Collide() //with the Sky
{
    int ballx = ball->getx();
    int bally = ball->gety();
    int p1x = p1->getx();
    int p1y = p1->gety();
    int p2x = p2->getx();
    int p2y = p2->gety();

    for (int i=0; i<4; i++) //left paddle
    {
        if(ballx==p1x+1) //left paddle is hit
        {
            if (bally==p1y+i)
            {
                ball->changeDir((dir)((rand()%3)+4));
            }
        }
    }
    for (int i=0; i<4; i++) //right paddle
    {
        if(ballx==p2x-1) //right paddle is hit
        {
            if (bally==p2y+i)
            {
                ball->changeDir((dir)((rand()%3)+1));
            }
        }
    }
    if (bally==height-1) //ball hit bottom wall
    {
        if (ball->getDirection()==DOWNRIGHT)
        {
            ball->changeDir(UPRIGHT);
        }
        else if (ball->getDirection()==DOWNLEFT)
        {
            ball->changeDir(UPLEFT);
        }
    }
    if (bally==0) //ball hit top wall
    {
        if (ball->getDirection()==UPRIGHT)
        {
            ball->changeDir(DOWNRIGHT);
        }
        else if (ball->getDirection()==UPLEFT)
        {
            ball->changeDir(DOWNLEFT);
        }
    }
    if (ballx==width-1) //ball hit right wall
    {
        score_incr(p1);
    }
    if (ballx==0) //ball hit left wall
    {
        score_incr(p2);
    }
}
void Game::Play()
{
    while (!end)
    {
        Draw();
        input();
        Collide();
    }
}
void Game::Draw()
{
    system ("clear");
    for (int i=0; i < width+2; i++) //part of the wall for the game
    {
        cout << "#";
    }
    cout << endl;
    for (int j=0; j<height; j++)
    {
        for (int k=0; k<width; k++)
        {
            int ballx = ball->getx();
            int bally = ball->gety();
            int p1x = p1->getx();
            int p1y = p1->gety();
            int p2x = p2->getx();
            int p2y = p2->gety();
            if (k==0) //print wall
            {
                cout << "#";
            }
            if (ballx==k && bally==j) //print the ball if at the current location
            {
                cout << "O";
            }
            else if (p1x==k && p1y==j)
            {
                cout << "|"; //player1 paddle
            }
            else if(p2x==k && p2y==j)
            {
                cout << "|"; //player2 paddle
            }
            else if (p1x==k && p1y+1==j)
            {
                cout << "|"; //player1 paddle
            }
            else if (p1x==k && p1y+2==j)
            {
                cout << "|"; //player1 paddle
            }
            else if (p1x==k && p1y+3==j)
            {
                cout << "|"; //player1 paddle
            }
            else if(p2x==k && p2y+1==j)
            {
                cout << "|"; //player2 paddle
            }
            else if(p2x==k && p2y+2==j)
            {
                cout << "|"; //player2 paddle
            }
            else if(p2x==k && p2y+3==j)
            {
                cout << "|"; //player2 paddle
            }
            else
            {
                cout << " ";
            }
            
            if (k==width-1) //print wall
            {
                cout << "#" ;
            }
        }
        cout << endl;
    }
    for (int i=0; i < width+2; i++)
    {
        cout << "#";
    }
    cout << endl;
}