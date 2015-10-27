#ifndef RIGHTPORTAL_H
#define RIGHTPORTAL_H

#include "GameObject.h"
#include "../MapComponents/Level.h"
#include "../Exceptions.h"

class RightPortal : public GameObject {
    private:
        int row;
        int column;
        Level* level;
    public:
        RightPortal(int row, int column, Level* level);
        virtual ~RightPortal();

        virtual void action(GameObject* actionObject);
};

#endif // RIGHTPORTAL_H
