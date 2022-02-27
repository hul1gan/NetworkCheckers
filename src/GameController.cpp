#include <include/GameController.h>

GameController::GameController(QObject *parent) : QAbstractTableModel(parent)
{
    m_data.reserve(64);
    m_cell.reserve(64);

    setStartBoard();
}

void GameController::findWay(int rowPosition, int colPosition)
{
    int index = (rowPosition-1) * 8 + colPosition;

    m_data[index - 1].isSelected = true;

    int row;

    if(rowPosition != 1)
    {
        row = rowPosition - 1;
    }

    int col1;
    int col2;

    if(colPosition == 1)
    {
        col1 = colPosition + 1;
    }

    else if(colPosition == 8)
    {
        col1 = colPosition - 1;
    }
    else
    {
        col1 = colPosition - 1;
        col2 = colPosition + 1;
    }

    //qDebug() << rowPosition << colPosition;


    for(auto& element: m_data){

        if(row == element.rowPosition){

            if (col1 == element.columnPosition || col2 == element.columnPosition)
            {
                element.isHighlighted = true;
                dataChanged(createIndex(0,0), createIndex(8, 8));
            }

        }



    }
}



void GameController::setStartBoard()
{

    bool isActiveCell = false;
    int counter = 1;

    int startColPosition = 1;

    int startRowPosition = 1;

    for(int i = 0; i < 64; i++){

        m_data.push_back(Checker{});
        m_cell.push_back(Cell{});

        if(isActiveCell == true)
        {
            m_cell[i].isActiveCell = true;
            m_data[i].rowPosition = startRowPosition;
            m_data[i].columnPosition = startColPosition;

            m_cell[i].rowPosition = startRowPosition;
            m_cell[i].columnPosition = startColPosition;


            if(counter == 1||counter == 2||counter == 3)
            {
                m_cell[i].isEmptyCell = false;
                m_data[i].imgPath = "qrc:/Pictures/2.svg";
            }
            else if(counter == 6||counter == 7||counter == 8)
            {

                m_cell[i].isEmptyCell = false;
                m_data[i].imgPath = "qrc:/Pictures/1.svg";

            }

        }

        startColPosition++;

        if(((i+1)%8) == 0)
        {
            counter++;
            startRowPosition++;
            startColPosition = 1;

        }
        else
        {
            isActiveCell = !isActiveCell;
        }

    }

}

int GameController::rowCount(const QModelIndex &parent) const
{
    if(parent.isValid()){

        return 0;
    }

    Q_UNUSED(parent);

    return 8;
}

QVariant GameController::data(const QModelIndex &index, int role) const
{
    if (!index.isValid())
    {
        return QVariant();
    }

    int row = index.row();
    int column = index.column();

    int elIndex = (8 * row ) + column ;

    switch (role)
    {
    case Roles::RowPosition:
    {
        return QVariant::fromValue(m_data[elIndex].rowPosition);
    }
    case Roles::ColPosition:
    {
        return QVariant::fromValue(m_data[elIndex].columnPosition);
    }
    case Roles::IsEmptyCell:
    {
        return QVariant::fromValue(m_cell[elIndex].isEmptyCell);
    }
    case Roles::IsHighlightedCell:
    {
        return QVariant::fromValue(m_data[elIndex].isHighlighted);
    }
    case Roles::Color:
    {
        return QVariant::fromValue(m_data[elIndex].imgPath);
    }
    case Roles::IsKing:
    {
        return QVariant::fromValue(m_data[elIndex].isKing);
    }
    case Roles::IsActiveCell:
    {
        return QVariant::fromValue(m_cell[elIndex].isActiveCell);
    }
    case Roles::IsSelected:
    {
        return QVariant::fromValue(m_data[elIndex].isSelected);
    }

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
    case Roles::RowPosition:
    {
        m_data[index.row()].rowPosition = value.toInt();
        break;
    }
    case Roles::ColPosition:
    {
        m_data[index.row()].columnPosition = value.toInt();
        break;
    }
    case Roles::IsEmptyCell:
    {
        m_cell[index.row()].isEmptyCell = value.toBool();
        break;
    }
    case Roles::IsHighlightedCell:
    {
        m_data[index.row()].isHighlighted = value.toBool();
        break;
    }
    case Roles::Color:
    {
        m_data[index.row()].imgPath = value.toString();
        break;
    }
    case Roles::IsKing:
    {
        m_data[index.row()].isKing = value.toBool();
        break;
    }
    case Roles::IsActiveCell:
    {
        m_cell[index.row()].isActiveCell = value.toBool();
        break;
    }
    case Roles::IsSelected:
    {
        m_data[index.row()].isSelected = value.toBool();
        break;
    }
    }

    emit dataChanged(index, index, QVector<int>() << role);

    return true;
}

QHash<int, QByteArray> GameController::roleNames() const
{
    QHash<int, QByteArray> roles = QAbstractTableModel::roleNames();
    roles[RowPosition] = "rowPosition";
    roles[IsEmptyCell] = "isEmptyCell";
    roles[IsHighlightedCell] = "isHighlightedCell";
    roles[Color] = "color";
    roles[IsKing] = "isKing";
    roles[IsActiveCell] = "isActiveCell";
    roles[ColPosition] = "colPosition";
    roles[IsSelected] = "isSelected";


    return roles;
}

int GameController::columnCount(const QModelIndex& parent) const
{
    Q_UNUSED(parent)
    return 8;
}

bool GameController::isFlippedBoard()
{
    return _isFlippedBoard;
}

