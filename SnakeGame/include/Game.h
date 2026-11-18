#ifndef GAME_H
#define GAME_H

#include "Snake.h"
#include "Food.h"
#include "ScoreManager.h"

class Game
{
private:
    Snake snake;
    Food food;
    ScoreManager scoreManager;

    int directionX;
    int directionY;

    bool isRunning;

    void handleInput();
    void update();
    void render();

public:
    Game();
    ~Game();

    void run();
};

#endif
