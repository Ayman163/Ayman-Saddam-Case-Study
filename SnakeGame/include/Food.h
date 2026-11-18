#ifndef FOOD_H
#define FOOD_H

#include "GameObject.h"

class Food : public GameObject
{
private:
    int x;
    int y;

public:
    Food(int startX, int startY);

    void draw() const override;

    void setPosition(int newX, int newY);
};

#endif
