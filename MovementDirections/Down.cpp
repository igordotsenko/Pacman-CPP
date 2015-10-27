#include "Down.h"

Down::Down() {}

Down::~Down() {}

int Down::getNewRow(int previousRow) {
    return previousRow += 1;
}

int Down::getNewColumn(int previousColumn) {
    return previousColumn;
}
