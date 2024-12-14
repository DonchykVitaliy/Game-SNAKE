#pragma once
#include <iostream>
#include <stdio.h>
#include <stdlib.h>


class World
{
public:

    World();
    ~World();

    bool GetBool();
    void TakeApple();
    int GetAppleX();
    int GetAppleY();

    int GenNumber(int WindowW, int WindowH);

private:
    bool genApple;
    int AppleX;
    int AppleY;
};