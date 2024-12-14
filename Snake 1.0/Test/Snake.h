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

    // ������ ��������� ��� �� ��������� ������
    const vector<pair<int, int>>& getSegments() const;
    pair<int, int> HeadPosition() const;

    void move(Direction direction, int width, int height, Snake s);

    int GetScore();
    void TakeApple();

private:
    vector<pair<int, int>> segments;    // ���� ��������� ��� ������ ��� �쳿
    int score;
};