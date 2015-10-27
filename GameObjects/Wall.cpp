#include "Wall.h"

Wall::Wall() {
    sign = '#';
}

Wall::~Wall() {}

void Wall::action(GameObject *actionObject) {
    // Notifies action object that it is wall
    throw LocationIsWallException();
}
