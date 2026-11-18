#ifndef SNAKE_H
#define SNAKE_H

#include "GameObject.h"
#include <vector>

struct Position
{
    int x;
    int y;
};

class Snake : public GameObject
{
private:
    std::vector<Position> body;

public:
    Snake(int startX, int startY);

    void draw() const override;

    void move(int dx, int dy, bool grow = false);

    Position getHead() const;

    bool occupies(int x, int y) const;

    bool checkSelfCollision() const;

    int getLength() const;
};

#endif
