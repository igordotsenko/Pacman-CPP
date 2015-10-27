#include "Ghost.h"

Ghost::Ghost(int row, int column, Level *level)
    : Moveable(row, column, level) {
    id = lastId;
    lastId += 1;
    sign = 'M';
    // Set current movement direction as "down"
    direction = directions->find('s')->second;
    coin = NULL;
}

Ghost::~Ghost() {}

bool Ghost::locationIsAvailable(Location* location) {
    if ( location->hasGhost() ) {
        return false;
    }
    if ( location->getContent() != NULL ) {
        if ( location->getContent()->getSign() == '#' ) {
            return false;
        }
    }
    return true;
}

void Ghost::action(GameObject *actionObject) {}

void Ghost::move() {
    Location* currentLocation = level->getField(currentRow, currentColumn);
    Location* newLocation = specifyNewLocation();

    // If new location has pacman - game over
    checkForPacman(newLocation);

    // Check if locaton has ghost or wall. If has - change direction
    for ( ; !locationIsAvailable(newLocation);  ) {
        changeDirection();
        newLocation = specifyNewLocation();
    }

    // Check if location is a portal. If yes - teleportation
    newLocation = checkForPortal(newLocation);

    // Moving ghost on new location
    currentLocation->removeGhost(coin);
    if ( coin != NULL ) {
        coin = NULL;
    }
    checkForCoin(newLocation);
    newLocation->placeGhost(this);

    currentRow = newLocation->getRow();
    currentColumn = newLocation->getColumn();
}

Location* Ghost::specifyNewLocation() {
    int newRow = direction->getNewRow(currentRow);
    int newColumn = direction->getNewColumn(currentColumn);
    return level->getField(newRow, newColumn);
}

void Ghost::changeDirection() {
    char ways[] = { 'w', 'a', 's', 'd' };
    int way = rand() % 4;
    direction = directions->find(ways[way])->second;
}

Location* Ghost::checkForPortal(Location* newLocation) {
    if ( newLocation->getContent() != NULL ) {
       try {
            newLocation->getContent()->action(this);
        } catch ( LeftPortalException e ) {
            return level->getField(currentRow, MAP_WIDTH-2);
        } catch (RightPortalException e ) {
            return level->getField(currentRow, 1);
        }
    }
    return newLocation;
}

void Ghost::checkForPacman(Location* location) {
    if ( location->hasPacman() ) {
        level->gameOver();
    }
}

void Ghost::checkForCoin(Location* location) {
    if ( location->getContent() != NULL) {
        if ( location->getContent()->getSign() == '.' ) {
            coin = location->getContent();
        }
    }
}

int Ghost::lastId = 1;
