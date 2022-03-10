#ifndef CHECKER_H
#define CHECKER_H

#include <QString>

#include <include/AbstractFigure.h>

struct Checker: public AbstractFigure
{
    QString imgPath;

    bool isKing = false;

    bool isSelected = false;
};

#endif // CHECKER_H
