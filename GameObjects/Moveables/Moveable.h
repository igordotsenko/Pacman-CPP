#ifndef MOVEABLE_H
#define MOVEABLE_H

#include <map>

#include "../../MovementDirections/Down.h"
#include "../../MovementDirections/Up.h"
#include "../../MovementDirections/Left.h"
#include "../../MovementDirections/Right.h"

class Level;
class MovementDirections;

class Moveable {
    protected:
        int currentRow;
        int currentColumn;
        Level* level;
        std::map<char, MovementDirection*>* directions;
        MovementDirection* direction;

    protected:
        void initDirections();

    public:
        Moveable(int row, int column, Level* level);
        virtual ~Moveable();

        virtual void move() = 0;
        virtual void changeDirection();
};

#endif // MOVEABLE_H
