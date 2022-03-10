#include <include/GameController.h>

GameController::GameController(QObject *parent) : QAbstractTableModel(parent)
{
    m_data.reserve(boardSize*boardSize);
    m_data.shrink_to_fit();

    setStartBoard();
}

GameController::~GameController(){}

void GameController::findWay(int rowPosition, int colPosition)
{
    //    int index = (rowPosition-1) * 8 + colPosition;

    //    m_cell[index - 1].isSelected = true;

    //    int row;

    //    if(rowPosition != 1)
    //    {
    //        row = rowPosition - 1;
    //    }

    //    int col1;
    //    int col2;

    //    if(colPosition == 1)
    //    {
    //        col1 = colPosition + 1;
    //    }

    //    else if(colPosition == 8)
    //    {
    //        col1 = colPosition - 1;
    //    }
    //    else
    //    {
    //        col1 = colPosition - 1;
    //        col2 = colPosition + 1;
    //    }

    //    //qDebug() << rowPosition << colPosition;


    //    for(auto& element: m_cell){

    //        if(row == element.rowPosition){

    //            if (col1 == element.columnPosition || col2 == element.columnPosition)
    //            {
    //                element.isHighlighted = true;
    //                dataChanged(createIndex(0,0), createIndex(8, 8));
    //            }

    //        }



}




void GameController::setStartBoard()
{
    int sizeBoard = boardSize * boardSize;

    int row = 1;
    int col = 1;

    for(int i = 0; i < sizeBoard; ++i){

        AbstractFigure* element = new AbstractFigure(std::move(row), std::move(col));
        setFigure(element, row, col);

        m_data.push_back(element);

        col++;

        if(col > boardSize)
        {
           row++;
           col = 1;
        }


    }

}

void GameController::setFigure(AbstractFigure* ptr, int& rowPosition, int& colPosition)
{
    if(rowPosition%2 != 0 && colPosition%2 == 0)
    {
        ptr->isActivePosition = true;
    }
    else if(rowPosition%2 == 0 && colPosition%2 != 0)
    {
        ptr->isActivePosition = true;
    }
}

int GameController::rowCount(const QModelIndex &parent) const
{
    if(parent.isValid()){

        return 0;
    }

    Q_UNUSED(parent);

    return boardSize;
}

QVariant GameController::data(const QModelIndex &index, int role) const
{
    if (!index.isValid())
    {
        return QVariant();
    }

        int row = index.row();
        int column = index.column();

        int elIndex = (boardSize * row ) + column ;

        switch (role)
        {
    //    case Roles::RowPosition:
    //    {
    //        return QVariant::fromValue(m_cell[elIndex].rowPosition);
    //    }
    //    case Roles::ColPosition:
    //    {
    //        return QVariant::fromValue(m_cell[elIndex].columnPosition);
    //    }
    //    case Roles::IsEmptyCell:
    //    {
    //        return QVariant::fromValue(m_cell[elIndex].isEmptyCell);
    //    }
    //    case Roles::IsHighlightedCell:
    //    {
    //        return QVariant::fromValue(m_cell[elIndex].isHighlighted);
    //    }
    //    case Roles::Color:
    //    {
    //        return QVariant::fromValue(m_cell[elIndex].imgPath);
    //    }
    //    case Roles::IsKing:
    //    {
    //        return QVariant::fromValue(m_cell[elIndex].isKing);
    //    }
        case Roles::IsActiveCell:
        {
            return QVariant::fromValue(m_data[elIndex]->isActivePosition);
        }
    //    case Roles::IsSelected:
    //    {
    //        return QVariant::fromValue(m_cell[elIndex].isSelected);
    //    }

        default:
        {
            return QVariant();
        }

        }

}

bool GameController::setData(const QModelIndex &index, const QVariant &value, int role)
{
        if (!index.isValid()) {
            return false;
        }

    switch (role) {
    //    case Roles::RowPosition:
    //    {
    //        m_cell[index.row()].rowPosition = value.toInt();
    //        break;
    //    }
    //    case Roles::ColPosition:
    //    {
    //        m_cell[index.row()].columnPosition = value.toInt();
    //        break;
    //    }
    //    case Roles::IsEmptyCell:
    //    {
    //        m_cell[index.row()].isEmptyCell = value.toBool();
    //        break;
    //    }
    //    case Roles::IsHighlightedCell:
    //    {
    //        m_cell[index.row()].isHighlighted = value.toBool();
    //        break;
    //    }
    //    case Roles::Color:
    //    {
    //        m_cell[index.row()].imgPath = value.toString();
    //        break;
    //    }
    //    case Roles::IsKing:
    //    {
    //        m_cell[index.row()].isKing = value.toBool();
    //        break;
    //    }
    case Roles::IsActiveCell:
    {
        m_data[index.row()]->isActivePosition = value.toBool();
        break;
    }
//    }
        //    case Roles::IsSelected:
        //    {
        //        m_cell[index.row()].isSelected = value.toBool();
        //        break;
        //    }
        //    }

//        emit dataChanged(index, index, QVector<int>() << role);

//        return true;

}}

QHash<int, QByteArray> GameController::roleNames() const
{
    QHash<int, QByteArray> roles = QAbstractTableModel::roleNames();
    //roles[RowPosition] = "rowPosition";
    //roles[IsEmptyCell] = "isEmptyCell";
    //roles[IsHighlightedCell] = "isHighlightedCell";
    //roles[Color] = "color";
    // roles[IsKing] = "isKing";
     roles[IsActiveCell] = "isActiveCell";
    //roles[ColPosition] = "colPosition";
    //roles[IsSelected] = "isSelected";


    return roles;
}

int GameController::columnCount(const QModelIndex& parent) const
{
    Q_UNUSED(parent)

    return boardSize;
}

bool GameController::isFlippedBoard()
{
    return _isFlippedBoard;
}

