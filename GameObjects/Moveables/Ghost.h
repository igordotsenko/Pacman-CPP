#ifndef GHOST_H
#define GHOST_H

#include <stdlib.h>

#include "Moveable.h"
#include "../../MapComponents/Level.h"
#include "../../MapComponents/Location.h"

class Location;

class Ghost : public GameObject, public Moveable {
    private:

        GameObject* coin;




    public:
        static int lastId;

    public:
        int id;
        Ghost(int row, int column, Level* level);
        virtual ~Ghost();

        virtual void action(GameObject* actionObject);
        bool locationIsAvailable(Location* location);
        virtual void move();
        Location* specifyNewLocation();
        void changeDirection();
        Location* checkForPortal(Location* location);
        void checkForPacman(Location* location);
        void checkForCoin(Location* location);
};

#endif // GHOST_H
