#ifndef COIN_H
#define COIN_H

#include "GameObject.h"
#include "../MapComponents/Level.h"

class Level;

class Coin : public GameObject {
    private:
        int row;
        int column;
        Level* level;

    public:
        Coin(int row, int column, Level* level);
        virtual ~Coin();

        virtual void action(GameObject* actionObject);
};

#endif // COIN_H
