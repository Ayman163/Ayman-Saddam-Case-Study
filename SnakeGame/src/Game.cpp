#include "Game.h"

#include <random>
#include <iostream>
#include <conio.h>
#include <chrono>
#include <thread>

Game::Game()
    : snake(5, 5),
      food(10, 8),
      directionX(1),
      directionY(0),
      isRunning(true)
{
}

Game::~Game()
{
}

void Game::handleInput()
{
    if (_kbhit())
    {
        char key = _getch();

        switch (key)
        {
            case 'w':
            case 'W':
                if (directionY != 1)
                {
                    directionX = 0;
                    directionY = -1;
                }
                break;

            case 's':
            case 'S':
                if (directionY != -1)
                {
                    directionX = 0;
                    directionY = 1;
                }
                break;

            case 'a':
            case 'A':
                if (directionX != 1)
                {
                    directionX = -1;
                    directionY = 0;
                }
                break;

            case 'd':
            case 'D':
                if (directionX != -1)
                {
                    directionX = 1;
                    directionY = 0;
                }
                break;

            case 'q':
            case 'Q':
                isRunning = false;
                break;
        }
    }
}
void Game::spawnFood()
{
    static std::random_device rd;
    static std::mt19937 gen(rd());

    std::uniform_int_distribution<int> xDist(1, WIDTH - 2);
    std::uniform_int_distribution<int> yDist(1, HEIGHT - 2);

    int x;
    int y;

    do
    {
        x = xDist(gen);
        y = yDist(gen);
    }
    while (snake.occupies(x, y));

    food.setPosition(x, y);
}
void Game::update()
{
    Position nextHead = snake.getHead();

    nextHead.x += directionX;
    nextHead.y += directionY;

    // Check wall collision
    if (nextHead.x <= 0 || nextHead.x >= WIDTH - 1 ||
        nextHead.y <= 0 || nextHead.y >= HEIGHT - 1)
    {
        isRunning = false;
        return;
    }

    // Check food collision
    Position foodPosition = food.getPosition();

    bool ateFood = (nextHead.x == foodPosition.x &&
                    nextHead.y == foodPosition.y);

    // Move snake
    snake.move(directionX, directionY, ateFood);

    // Update score
    if (ateFood)
    {
        scoreManager.addPoints(10);
        spawnFood();
    }

    // Check self collision
    if (snake.checkSelfCollision())
    {
        isRunning = false;
    }
}

void Game::render()
{
    std::cout << "\033[2J\033[H";

    std::cout << "===== SNAKE GAME =====\n\n";

    for (int y = 0; y < HEIGHT; y++)
    {
        for (int x = 0; x < WIDTH; x++)
        {
            if (y == 0 || y == HEIGHT - 1 ||
                x == 0 || x == WIDTH - 1)
            {
                std::cout << "#";
            }
            else if (snake.occupies(x, y))
            {
                Position head = snake.getHead();

                if (head.x == x && head.y == y)
                    std::cout << "@";
                else
                    std::cout << "o";
            }
            else
            {
                Position foodPosition = food.getPosition();

                if (foodPosition.x == x &&
                    foodPosition.y == y)
                    std::cout << "*";
                else
                    std::cout << " ";
            }
        }

        std::cout << '\n';
    }

    std::cout << "\nScore: "
              << scoreManager.getScore();

    std::cout << "\nW A S D: Move | Q: Quit\n";
}

void Game::run()
{
    using namespace std::chrono_literals;

    while (isRunning)
    {
        handleInput();
        update();

        if (isRunning)
        {
            render();
            std::this_thread::sleep_for(200ms);
        }
    }

    render();
}
