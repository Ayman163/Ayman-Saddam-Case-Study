#include "Game.h"

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
    std::cout << "\nGame closed.\n";
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
                directionX = 0;
                directionY = -1;
                break;

            case 's':
            case 'S':
                directionX = 0;
                directionY = 1;
                break;

            case 'a':
            case 'A':
                directionX = -1;
                directionY = 0;
                break;

            case 'd':
            case 'D':
                directionX = 1;
                directionY = 0;
                break;

            case 'q':
            case 'Q':
                isRunning = false;
                break;
        }
    }
}

void Game::update()
{
    snake.move(directionX, directionY);

    Position head = snake.getHead();

    // Check wall collision
    if (head.x <= 0 || head.x >= WIDTH - 1 ||
        head.y <= 0 || head.y >= HEIGHT - 1)
    {
        isRunning = false;
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
        render();

        std::this_thread::sleep_for(200ms);
    }
}
