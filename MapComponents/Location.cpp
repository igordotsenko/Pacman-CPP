#include "Location.h"

Location::Location(int row, int column, GameObject* content) {
    this->row = row;
    this->column = column;
    this->content = content;
    ghostSituated = false;
    pacmanSituated = false;
}

Location::~Location() {
    if ( content != NULL ) {
        delete content;
    }
}

int Location::getRow() const {
    return row;
}

int Location::getColumn() const {
    return column;
}

GameObject* Location::getContent() const {
    return content;
}

bool Location::hasPacman() const {
    return pacmanSituated;
}

bool Location::hasGhost() const {
    return ghostSituated;
}

void Location::setContent(GameObject *content) {
    this->content = content;
}

void Location::placePacman(GameObject* pacman) {
    if ( !pacmanSituated ) {
       pacmanSituated = true;
       content = pacman;
       SetConsoleCursorPosition ( GetStdHandle ( STD_OUTPUT_HANDLE ), { (SHORT)column, (SHORT)row } );
       std::cout << "O" << std::endl;
    }
}

void Location::placeGhost(GameObject* ghost) {
    if ( !ghostSituated ) {
       ghostSituated = true;
       content = ghost;
       SetConsoleCursorPosition ( GetStdHandle ( STD_OUTPUT_HANDLE ), { (SHORT)column, (SHORT)row } );
       std::cout << "M" << std::endl;
    }
}

void Location::removePacman() {
    if  ( pacmanSituated ) {
        pacmanSituated = false;
        content = NULL;
        SetConsoleCursorPosition ( GetStdHandle ( STD_OUTPUT_HANDLE ), { (SHORT)column, (SHORT)row } );
        std::cout << " " << std::endl;
    }
}

void Location::removeGhost(GameObject* coin) {
    if ( ghostSituated ) {
        ghostSituated = false;
        SetConsoleCursorPosition ( GetStdHandle ( STD_OUTPUT_HANDLE ), { (SHORT)column, (SHORT)row } );
        if ( coin != NULL ) {
            content = coin;
            std::cout << "." << std::endl;
            return;
        }
        content = NULL;
        std::cout << " " << std::endl;
    }
}
