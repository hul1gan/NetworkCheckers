#ifndef CHECKER_H
#define CHECKER_H

#include <QString>

struct Checker
{
public:
    QString checkerPath;

    bool isKing = false;  //0 - false, 1 - true


    bool isEmptyCell = true;
    bool isActiveCell = false;

    int position = 90;
};

#endif // CHECKER_H
