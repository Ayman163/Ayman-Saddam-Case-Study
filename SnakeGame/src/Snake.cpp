#include "Snake.h"

Snake::Snake(int startX, int startY)
{
    body.push_back({startX, startY});
    body.push_back({startX - 1, startY});
    body.push_back({startX - 2, startY});
}

void Snake::draw() const
{
    std::cout << "Snake body:\n";

    for (int i = 0; i < body.size(); i++)
    {
        if (i == 0)
            std::cout << "Head: ";
        else
            std::cout << "Body: ";

        std::cout << "("
                  << body[i].x << ", "
                  << body[i].y << ")\n";
    }
}

void Snake::move(int dx, int dy, bool grow)
{
    Position newHead = {
        body[0].x + dx,
        body[0].y + dy
    };

    body.insert(body.begin(), newHead);

    if (!grow)
    {
        body.pop_back();
    }
}

Position Snake::getHead() const
{
    return body[0];
}

bool Snake::occupies(int x, int y) const
{
    for (const Position& segment : body)
    {
        if (segment.x == x && segment.y == y)
            return true;
    }

    return false;
}

bool Snake::checkSelfCollision() const
{
    Position head = body[0];

    for (int i = 1; i < body.size(); i++)
    {
        if (head.x == body[i].x &&
            head.y == body[i].y)
        {
            return true;
        }
    }

    return false;
}

int Snake::getLength() const
{
    return body.size();
}
