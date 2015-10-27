#ifndef RIGHT_H
#define RIGHT_H

#include "MovementDirection.h"

class Right : public MovementDirection {
    public:
        Right();
        virtual ~Right();

        virtual int getNewRow(int previousRow);
        virtual int getNewColumn(int previousColumn);
};

#endif // RIGHT_H
