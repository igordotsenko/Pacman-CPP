#include "Left.h"

Left::Left() {}

Left::~Left() {}

int Left::getNewRow(int previousRow) {
    return previousRow;
}

int Left::getNewColumn(int previousColumn) {
    return previousColumn -= 1;
}
