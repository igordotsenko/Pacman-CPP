#ifndef WALL_H
#define WALL_H

#include "GameObject.h"

class Wall : public GameObject {
    public:
        Wall();
        virtual ~Wall();

        virtual void action(GameObject* actionObject);
};

#endif // WALL_H
