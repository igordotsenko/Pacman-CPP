#ifndef PACMAN_H
#define PACMAN_H

#include <conio.h>
#include <map>

#include "Moveable.h"
#include "../../MapComponents/Level.h"
#include "../../MapComponents/Location.h"
#include "../../Exceptions.h"

class Level;
class Location;
class MovementDirection;

class Pacman : public GameObject, public Moveable {
    private:
        int scores;

    public:
        Pacman(int row, int column, Level* level);
        virtual ~Pacman();

        int getScores() const;

        virtual void addScores(int scores);

        virtual void action(GameObject* actionObject);
        virtual void move();
        virtual void changeDirection();
        void checkForGhost(Location* location);
};

#endif // PACMAN_H
