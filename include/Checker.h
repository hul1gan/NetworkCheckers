#ifndef CHECKER_H
#define CHECKER_H

#include <QString>

#include <include/AbstractFigure.h>

class Checker: public AbstractFigure
{
public:

    Checker(int* col, int* row): AbstractFigure(col, row){};

    bool isKing = false;

    bool isSelected = false;

    virtual bool isEmpty() override;
};

#endif // CHECKER_H
