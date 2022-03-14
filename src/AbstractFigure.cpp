#include <include/AbstractFigure.h>

AbstractFigure::AbstractFigure(int* row, int* col)
{
    this->colPosition = *col;
    this->rowPosition = *row;
}

AbstractFigure::~AbstractFigure()
{

}

bool AbstractFigure::isEmpty()
{
    return false;
}
