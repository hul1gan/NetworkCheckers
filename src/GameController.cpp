#include <include/GameController.h>

GameController::GameController(QObject *parent) : QAbstractTableModel(parent){

    m_data.reserve(64);
    m_cell.reserve(64);

    setStartBoard();
}

void GameController::findWay(int rowPosition, int colPosition)
{
    qDebug() << "SEARCHING";
//    QVector<int> positions;
//    return positions;
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
            startColPosition++;

            if(counter == 1||counter == 2||counter == 3)
            {
                m_cell[i].isEmptyCell = false;
                m_data[i].checkerPath = "qrc:/Pictures/CowHead.svg";
            }
            else if(counter == 6||counter == 7||counter == 8)
            {

                m_cell[i].isEmptyCell = false;
                m_data[i].checkerPath = "qrc:/Pictures/HorseHead.svg";

            }

        }
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

        //qDebug() << m_data[i].rowPosition << m_data[i].columnPosition;
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
    case Roles::Color:
    {
        return QVariant::fromValue(m_data[elIndex].checkerPath);
    }
    case Roles::IsKing:
    {
        return QVariant::fromValue(m_data[elIndex].isKing);
    }
    case Roles::IsActiveCell:
    {
        return QVariant::fromValue(m_cell[elIndex].isActiveCell);
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
    case Roles::Color:
    {
        m_data[index.row()].checkerPath = value.toString();
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

    }

    emit dataChanged(index, index, QVector<int>() << role);

    return true;
}

//Qt::ItemFlags GameControllerModel::flags(const QModelIndex &index) const
//{
//    if (!index.isValid())
//        return Qt::ItemIsEnabled;

//    return QAbstractTableModel::flags(index) | Qt::ItemIsEditable;
//}

QHash<int, QByteArray> GameController::roleNames() const
{

    QHash<int, QByteArray> roles = QAbstractTableModel::roleNames();
    roles[RowPosition] = "rowPosition";
    roles[IsEmptyCell] = "isEmptyCell";
    roles[Color] = "color";
    roles[IsKing] = "isKing";
    roles[IsActiveCell] = "isActiveCell";
    roles[ColPosition] = "colPosition";


    return roles;
}

int GameController::columnCount(const QModelIndex& parent) const
{
    Q_UNUSED(parent)
    return 8;
}

