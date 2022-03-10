#ifndef ABSTRACTFIGURE_H
#define ABSTRACTFIGURE_H

class AbstractFigure
{
public:

    AbstractFigure(int&& row, int&& col);

    bool isActivePosition = false;

    int rowPosition;
    int colPosition;

};

#endif // ABSTRACTFIGURE_H
