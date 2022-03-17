#pragma once

#include <QString>

#include <include/AbstractFigure.h>

class Checker: public AbstractFigure
{
public:

    Checker(QObject* parent = nullptr);
    ~Checker() = default;

    bool isKing = false;

};
