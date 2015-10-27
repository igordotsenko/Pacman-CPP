#include "Exit.h"

Exit::Exit(Level *level) {
  this->level = level;
  sign = '^';
}

Exit::~Exit() {}

void Exit::action(GameObject *actionObject) {
    // Check if action object is pacman. If yes - game over
    if ( actionObject->getSign() == 'O' ) {
        level->gameOver();
    }

}
