#ifndef GAMEOBJECT_H
#define GAMEOBJECT_H

#include "../Exceptions.h"

/*
 * Basic class for such game objects as Wall, Coin, Ghost, Packman, RightPortal, LeftPortal
 * @param sign is visual representation of object
 * @method action representate interaction with another game object
 */

class GameObject {
    protected:
        char sign;
    public:
        GameObject();
        virtual ~GameObject();

        virtual char getSign();
        // Needed for scores adding to pacman
        virtual void addScores(int scores);

        virtual void action(GameObject* actionObject) = 0;
};

#endif // GAMEOBJECT_H
