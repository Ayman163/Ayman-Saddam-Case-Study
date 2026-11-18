#include "Food.h"

Food::Food(int startX, int startY)
    : x(startX), y(startY)
{
}

void Food::draw() const
{
    std::cout << "Food position: ("
              << x << ", " << y << ")\n";
}

void Food::setPosition(int newX, int newY)
{
    x = newX;
    y = newY;
}
