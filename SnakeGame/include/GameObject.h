#ifndef GAMEOBJECT_H
#define GAMEOBJECT_H

#include <iostream>

struct Position
{
    int x;
    int y;
};

class GameObject
{
public:
    GameObject();
    virtual ~GameObject();

    virtual void draw() const = 0;
};

#endif
