#ifndef CELL_H
#define CELL_H

#include <include/UnitPosition.h>

struct Cell: public UnitPosition
{
    bool isEmptyCell = true;
    bool isActiveCell = false;

};

#endif // CELL_H
