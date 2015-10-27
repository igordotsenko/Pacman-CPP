#ifndef MOVEMENTDIRECTION_H
#define MOVEMENTDIRECTION_H

class MovementDirection {
    public:
        MovementDirection();
        virtual ~MovementDirection();

        virtual int getNewRow(int previousRow);
        virtual int getNewColumn(int previousColumn);
};

#endif // MOVEMENTDIRECTION_H
