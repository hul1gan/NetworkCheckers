#include <include/AbstractFigure.h>

AbstractFigure::AbstractFigure(QObject *parent): QObject(parent)
{

}

AbstractFigure::~AbstractFigure()
{

}

void AbstractFigure::setPosition(int row, int col)
{
    this->_column = col;
    this->_row = row;
}

int AbstractFigure::getRow()
{
    return _row;
}

int AbstractFigure::getColumn()
{
    return _column;
}


bool AbstractFigure::isActiveCell() const
{
    return m_isActiveCell;
}

void AbstractFigure::setActiveCell(bool newIsActiveCell)
{
    if (m_isActiveCell == newIsActiveCell)
    {
        return;
    }

    m_isActiveCell = newIsActiveCell;

    emit activeCellChanged();
}

bool AbstractFigure::isSelectedCell() const
{
    return m_isSelected;
}

void AbstractFigure::setSelectCell(bool newIsSelected)
{
    if (m_isSelected == newIsSelected)
    {
        return;
    }

    m_isSelected = newIsSelected;

    emit selectCellChanged();
}

const QString &AbstractFigure::getImgPath() const
{
    return m_imgPath;
}

void AbstractFigure::setImgPath(const QString &newImgPath)
{
    if (m_imgPath == newImgPath)
    {
        return;
    }

    m_imgPath = newImgPath;

    emit imgPathChanged();
}

bool AbstractFigure::isContainFigure() const
{
    return m_isContainFigure;
}

void AbstractFigure::setContainFigure(bool newIsContainFigure)
{
    if (m_isContainFigure == newIsContainFigure)
    {
        return;
    }

    m_isContainFigure = newIsContainFigure;

    emit containFigureChanged();
}


