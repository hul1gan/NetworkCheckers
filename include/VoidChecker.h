#pragma once

#include <include/AbstractFigure.h>
#include <QObject>

class VoidChecker: public AbstractFigure
{
public:

    VoidChecker(QObject* parent = nullptr);
    ~VoidChecker();

    bool isHighlighted = false;

};



