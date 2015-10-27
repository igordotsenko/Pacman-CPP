#include "Pacman.h"

Pacman::Pacman(int row, int column, Level* level)
    : Moveable(row, column, level){
    sign = 'O';
    // Set current direction as "left"
    direction = directions->find('a')->second;
    scores = 0;
}

Pacman::~Pacman() {}

int Pacman::getScores() const {
    return scores;
}

void Pacman::addScores(int scores) {
    this->scores += scores;
}

void Pacman::action(GameObject *actionObject) {}

void Pacman::move() {
    int newRow;
    int newColumn;
    Location* newLocation;
    Location* currentLocation;

    // Check if there was a keyboard hit. If yes - pacman changes direction
    if ( _kbhit() ) {
        changeDirection();
    }

    // Define new location of pacman
    newRow = direction->getNewRow(currentRow);
    newColumn = direction->getNewColumn(currentColumn);
    newLocation = level->getField(newRow, newColumn);

    currentLocation = level->getField(currentRow, currentColumn);

    /*
     * Check object on new location
     * If it is wall - packman stops at the same location
     * If it is coin - pacman gets scores and moves to new location
     */
    if ( newLocation->getContent() != NULL ) {
        try {
            newLocation->getContent()->action(this);
        } catch ( LocationIsWallException e ) {
            return;
        } catch ( LeftPortalException e ) {
            newColumn = MAP_WIDTH-2;
            newLocation = level->getField(currentRow, newColumn);
        } catch (RightPortalException e ) {
            newColumn = 1;
            newLocation = level->getField(currentRow, newColumn);
        }
    }

    // If new location has ghost - game over
    checkForGhost(newLocation);

    // Replacing pacman on new location
    currentLocation->removePacman();
    newLocation->placePacman(this);
    currentRow = newRow;
    currentColumn = newColumn;
}

void Pacman::changeDirection() {
    char buttonHit = tolower(_getch());
    std::map<char, MovementDirection*>::iterator it = directions->find(buttonHit);

    if ( it != directions->end() ) {
    	direction = it->second;	
    }   
}

void Pacman::checkForGhost(Location* location) {
    if ( location->hasGhost() ) {
        level->gameOver();
    }
}
