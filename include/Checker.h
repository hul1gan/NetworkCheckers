#ifndef CHECKER_H
#define CHECKER_H

#include <QString>

struct Checker
{
public:
    QString checkerPath;

    bool isKing = false;

    int rowPosition = 0;
    int columnPosition = 0;
};

#endif // CHECKER_H
