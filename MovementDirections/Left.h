#ifndef LEFT_H
#define LEFT_H

#include "MovementDirection.h"

class Left : public MovementDirection {
    public:
        Left();
        virtual ~Left();

        virtual int getNewRow(int previousRow);
        virtual int getNewColumn(int previousColumn);
};

#endif // LEFT_H
