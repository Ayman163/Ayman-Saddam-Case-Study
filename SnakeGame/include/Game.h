#ifndef GAME_H
#define GAME_H

#include "Snake.h"
#include "Food.h"
#include "ScoreManager.h"

class Game
{
private:
    static const int WIDTH = 30;
    static const int HEIGHT = 15;
    Snake snake;
    Food food;
    ScoreManager scoreManager;

    int directionX;
    int directionY;

    bool isRunning;

    void handleInput();
    void update();
    void render();
    void spawnFood();
    void resetGame();
    void showGameOver();

public:
    Game();
    ~Game();

    void run();
};

#endif
