#include "Coin.h"

Coin::Coin(int row, int column, Level* level) {
    sign = '.';
    this->row = row;
    this->column = column;
    this->level = level;
}

Coin::~Coin() {}

void Coin::action(GameObject *actionObject) {
    // Checking if action object is pacman. If yes - pacman gets score, coin disappears
    if ( actionObject->getSign() == 'O' ) {
        actionObject->addScores(100);
        level->getField(row, column)->setContent(NULL);
        delete this;
    }
}
