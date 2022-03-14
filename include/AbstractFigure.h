#ifndef ABSTRACTFIGURE_H
#define ABSTRACTFIGURE_H

#include <QString>

class AbstractFigure
{
public:

    AbstractFigure(int* row, int* col);
    virtual ~AbstractFigure();

    bool isActivePosition = false;

    int rowPosition;
    int colPosition;

    QString imgPath = "";

    virtual bool isEmpty();

};


#endif // ABSTRACTFIGURE_H
