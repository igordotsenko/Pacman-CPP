#include "Up.h"

Up::Up() {}

Up::~Up() {}

int Up::getNewRow(int previousRow) {
    return previousRow -= 1;
}

int Up::getNewColumn(int previousColumn) {
    return previousColumn;
}
