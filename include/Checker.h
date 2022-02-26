#ifndef CHECKER_H
#define CHECKER_H

#include <include/UnitPosition.h>

#include <QString>

struct Checker: public UnitPosition
{
public:
    QString imgPath;

    bool isKing = false;

    bool isHighlighted = false;
    bool isSelected = false;
};

#endif // CHECKER_H
