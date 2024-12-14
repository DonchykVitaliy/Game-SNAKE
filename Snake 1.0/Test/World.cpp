#include "World.h"

using namespace std;

    World::World()
    {
        genApple = false;
        AppleX = 0;
        AppleY = 0;
    }

    World::~World() {}

    bool World::GetBool() { return genApple; }
    void World::TakeApple() { genApple = false; }
    int World::GetAppleX() { return AppleX; }
    int World::GetAppleY() { return AppleY; }

    int World::GenNumber(int WindowW, int WindowH) {
        srand(time(NULL)); // Initialize random seed

        AppleX = rand() % WindowW;
        cout << AppleX << endl;
        AppleY = rand() % WindowH;
        cout << AppleY << endl;

        genApple = true;
        return AppleX;
    }
