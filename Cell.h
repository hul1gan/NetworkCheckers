#ifndef CELL_H
#define CELL_H
#include<Checker.h>

class Cell
{
public:

 int position;
 bool _isCheckerHere = false;

 void addChecker();
 void deleteChecker();
 bool color();

private:
  Checker* _element;
};

#endif // CELL_H
