#ifndef CHECKER_H
#define CHECKER_H

class Checker
{
public:
    bool color = false;    //0 - white, 1 - black

    bool isKing = false;  //0 - false, 1 - true

    bool isEmptyCell = true;


    int position;
};

#endif // CHECKER_H