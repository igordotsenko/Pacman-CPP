#ifndef UP_H
#define UP_H

#include "MovementDirection.h"

class Up : public MovementDirection {
    public:
        Up();
        virtual ~Up();

        virtual int getNewRow(int previousRow);
        virtual int getNewColumn(int previousColumn);
};

#endif // UP_H
