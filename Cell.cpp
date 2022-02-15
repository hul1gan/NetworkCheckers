#include <Cell.h>

#include <QDebug>

void Cell::addChecker()
{
    if(_isCheckerHere == false)
    {
    _element = new Checker();
    _isCheckerHere = true;
    } else {
     qDebug() << "its not possible to create checker" ;
    }
}

void Cell::deleteChecker()
{
    if(_isCheckerHere == true)
    {
    _isCheckerHere = false;
    delete _element;
    } else {
        qDebug() << "the element is deleted";
    }
}

bool Cell::color()
{
    if(_isCheckerHere == true)
    {
        return _element->_color;
    } else {
     qDebug() << "the checker is not exist" ;
     return 0;
    }
}
