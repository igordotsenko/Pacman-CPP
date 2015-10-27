#ifndef LOCATION_H
#define LOCATION_H

#include <cstddef>
#include <windows.h>

#include "../GameObjects/GameObject.h"
#include "../GameObjects/Moveables/Pacman.h"

/*
 * Location is a represantation of level's field
 * @param content is a game object which is placed in location
 */

class Location {
    private:
        int row;
        int column;
        GameObject* content;
        bool pacmanSituated;
        bool ghostSituated;

    public:
        Location(int row, int column, GameObject* content = NULL);
        ~Location();

        int getRow() const;
        int getColumn() const;
        GameObject* getContent() const;
        bool hasPacman() const;
        bool hasGhost() const;

        void setContent(GameObject* content);

        void placePacman(GameObject* pacman);
        void placeGhost(GameObject* ghost);

        void removePacman();
        void removeGhost(GameObject *coin);

};

#endif // LOCATION_H
