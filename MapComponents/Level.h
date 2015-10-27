#ifndef LEVEL_H
#define LEVEL_H

#include <ostream>
#include <cstdlib>
#include <iostream>
#include <set>

#include "Location.h"
#include "../GameObjects/Moveables/Ghost.h"
#include "../GameObjects/Moveables/Pacman.h"
#include "../GameObjects/Coin.h"
#include "../GameObjects/Exit.h"
#include "../GameObjects/Wall.h"
#include "../GameObjects/LeftPortal.h"
#include "../GameObjects/RightPortal.h"

/*
 * Class that contains all locations of map
 * Responsible for pacman/ghosts moving and game ending
 */

#define MAP_HEIGHT 31
#define MAP_WIDTH 28
#define MAX_GHOSTS 2

class Pacman;
class Location;
class Ghost;

class Level {
    private:
        char map[MAP_HEIGHT][MAP_WIDTH+1];
        Location* field[MAP_HEIGHT][MAP_WIDTH+1];
        Pacman* pacman;
        Ghost* ghosts[MAX_GHOSTS];
        int ghostNumber;

    public:
        Level();
        ~Level();

        Location* getField(int row, int column) const;
        Ghost* getGhosts();

        void moveAll();
        void gameOver();
};

std::ostream& operator<<(std::ostream& out, const Level& level);

#endif // LEVEL_H
