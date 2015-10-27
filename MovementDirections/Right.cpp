#include "Right.h"

Right::Right() {}

Right::~Right() {}

int Right::getNewRow(int previousRow) {
    return previousRow;
}

int Right::getNewColumn(int previousColumn) {
    return previousColumn += 1;
}
