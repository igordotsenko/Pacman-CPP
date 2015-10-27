#ifndef EXIT_H
#define EXIT_H

#include "GameObject.h"
#include "../MapComponents/Level.h"

/*
 * Class defines level's exit point
 * When pacman reachs an exit the game ends
 */

class Level;

class Exit : public GameObject {
    private:
        Level* level;

    public:
        Exit(Level* level);
        virtual ~Exit();

        virtual void action(GameObject* actionObject);
};

#endif // EXIT_H
