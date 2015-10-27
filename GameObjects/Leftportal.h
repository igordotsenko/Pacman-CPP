#ifndef LEFTPORTAL_H
#define LEFTPORTAL_H

#include "GameObject.h"
#include "../MapComponents/Level.h"
#include "../Exceptions.h"

class LeftPortal : public GameObject {
    private:
        int row;
        int column;
        Level* level;
    public:
        LeftPortal(int row, int column, Level* level);
        virtual ~LeftPortal();

        virtual void action(GameObject* actionObject);
};

#endif // LEFTPORTAL_H
