#include "Snake.h"
#include "World.h"
#include "deathWindow.h"
	
using namespace std;

Snake::Snake()
    {
        segments.push_back({ 0,0 });
        score = 0;
    }
Snake::~Snake() {}

    // видача координат тіла та конкретно голови
    const vector<pair<int, int>>& Snake::getSegments() const { return segments; }
    pair<int, int> Snake::HeadPosition() const { return segments[0]; }

    void Snake::move(Direction direction, int width, int height, Snake s) {
        // збереження ласт координат
        vector<pair<int, int>> newSegments = segments;

        switch (direction) {
        case Up:    segments[0].second -= 50; break;
        case Down:  segments[0].second += 50; break;
        case Left:  segments[0].first -= 50; break;
        case Right: segments[0].first += 50; break;
        default: break;
        }

        // Перевірка виходу за межі
        if (segments[0].first < 0 || segments[0].second < 0 ||
            segments[0].first >= width || segments[0].second >= height) {
            deathWindow(score);
        }

        // рух тіла
        for (size_t i = 1; i < segments.size(); ++i) {
            segments[i] = newSegments[i - 1];
        }
    }

    int Snake::GetScore() { return score; }

    void Snake::TakeApple() {
        // додавання до тіла нової частини
        segments.push_back(segments.back());
        score++;
    }