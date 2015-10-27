#include "Moveable.h"

Moveable::Moveable(int row, int column, Level* level) {
    currentRow = row;
    currentColumn = column;
    this->level = level;
    initDirections();
}

Moveable::~Moveable() {
    std::map<char,MovementDirection*>::iterator it = directions->begin();

    for ( ; it != directions->end(); it++ ) {
        delete it->second;
    }

    delete directions;
}

void Moveable::initDirections() {
    directions = new std::map<char, MovementDirection*>();
    directions->insert(std::pair<char,MovementDirection*>('w', new Up()));
    directions->insert(std::pair<char,MovementDirection*>('a', new Left()));
    directions->insert(std::pair<char,MovementDirection*>('s', new Down()));
    directions->insert(std::pair<char,MovementDirection*>('d', new Right()));
}

void Moveable::move() {}
void Moveable::changeDirection() {}

