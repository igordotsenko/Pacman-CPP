#ifndef DOWN_H
#define DOWN_H

#include "MovementDirection.h"

class Down : public MovementDirection {
    public:
        Down();
        virtual ~Down();

        virtual int getNewRow(int previousRow);
        virtual int getNewColumn(int previousColumn);
};

#endif // DOWN_H
