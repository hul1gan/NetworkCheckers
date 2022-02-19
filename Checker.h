#ifndef CHECKER_H
#define CHECKER_H

struct Checker
{
public:
    bool color = false;    //0 - white, 1 - black

    bool isKing = false;  //0 - false, 1 - true


    bool isEmptyCell = true;
    bool isActiveCell = false;

    int position = 90;
};

#endif // CHECKER_H
