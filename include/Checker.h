#pragma once

#include <QString>

#include <include/AbstractFigure.h>

class Checker: public AbstractFigure
{
public:

    Checker(QObject* parent = nullptr);

    bool isKing = false;

    bool isSelected = false;

};
