#include "leftportal.h"

LeftPortal::LeftPortal(int row, int column, Level *level) {
    this->row = row;
    this->column = column;
    this->level = level;
}

LeftPortal::~LeftPortal() {}

void LeftPortal::action(GameObject *actionObject) {
    // Moves an object to new location and notifies an object about it
    level->getField(row, column+1)->setContent(NULL);
    level->getField(row, MAP_WIDTH-2)->setContent(actionObject);
    throw LeftPortalException();
}
