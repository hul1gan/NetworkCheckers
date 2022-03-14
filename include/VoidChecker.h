#ifndef VOIDCHECKER_H
#define VOIDCHECKER_H

#include <include/AbstractFigure.h>
#include <QObject>

class VoidChecker:public AbstractFigure
{
public:

    VoidChecker(int* col, int* row): AbstractFigure(col, row){};
    virtual bool isEmpty() override;

    bool isHighlighted = false;
};


#endif // VOIDCHECKER_H
