#pragma once
#include "World.h"
#include <vector>
#include <iostream>

using namespace std;

enum Direction { Up, Down, Left, Right, None };

class Snake : public World
{
public:

    Snake();
    ~Snake();

    // видача координат тіла та конкретно голови
    const vector<pair<int, int>>& getSegments() const;
    pair<int, int> HeadPosition() const;

    void move(Direction direction, int width, int height, Snake s);

    int GetScore();
    void TakeApple();

private:
    vector<pair<int, int>> segments;    // пара координат для частин тіла змії
    int score;
};