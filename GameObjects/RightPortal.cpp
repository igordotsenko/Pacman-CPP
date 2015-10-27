#include "RightPortal.h"

RightPortal::RightPortal(int row, int column, Level *level) {
    this->row = row;
    this->column = column;
    this->level = level;
}

RightPortal::~RightPortal() {}

void RightPortal::action(GameObject *actionObject) {
    // Moves an object to new location and notifies an object about it
    level->getField(row, column-1)->setContent(NULL);
    level->getField(row, 1)->setContent(actionObject);
    throw RightPortalException();
}

