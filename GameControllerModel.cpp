#include <GameControllerModel.h>

GameControllerModel::GameControllerModel(QObject *parent) : QAbstractTableModel(parent){

    m_data.reserve(64);

    setTheStartBoard();

}

void GameControllerModel::setTheStartBoard()
{

    bool col = false;
    int counter = 1;

    for(int i = 0; i < 64; i++){

        m_data.push_back(Checker{});

        if(col == true){
            m_data[i].isActiveCell = true;

            qDebug() << counter;

             if(counter == 1||counter == 2||counter == 3){
                 m_data[i].isEmptyCell = false;
                 m_data[i].checkerPath = "qrc:/Pictures/CowHead.svg";
             }
             else if(counter == 6||counter == 7||counter == 8){

                 m_data[i].isEmptyCell = false;
                 m_data[i].checkerPath = "qrc:/Pictures/HorseHead.svg";
             }

        }
        if(((i+1)%8) == 0){

            counter++;

        }else{
            col = !col;}
    }
}

int GameControllerModel::rowCount(const QModelIndex &parent) const
{
    if(parent.isValid()){

        return 0;
    }
    Q_UNUSED(parent);
    return 8;
}

QVariant GameControllerModel::data(const QModelIndex &index, int role) const
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
    case Roles::Position:
    {
        return QVariant::fromValue(m_data[elIndex].position);
    }
    case Roles::IsEmptyCell:
    {
        return QVariant::fromValue(m_data[elIndex].isEmptyCell);
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
        return QVariant::fromValue(m_data[elIndex].isActiveCell);
    }

    default:
    {
        return QVariant();
    }

    }

}

bool GameControllerModel::setData(const QModelIndex &index, const QVariant &value, int role)
{
    if (!index.isValid()) {
        return false;
    }

    switch (role) {
    case Roles::Position:
    {
        m_data[index.row()].position = value.toInt();
        break;
    }
    case Roles::IsEmptyCell:
    {
        m_data[index.row()].isEmptyCell = value.toBool();
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
        m_data[index.row()].isActiveCell = value.toBool();
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

QHash<int, QByteArray> GameControllerModel::roleNames() const
{

    QHash<int, QByteArray> roles = QAbstractTableModel::roleNames();
    roles[Position] = "position";
    roles[IsEmptyCell] = "isEmptyCell";
    roles[Color] = "color";
    roles[IsKing] = "isKing";
    roles[IsActiveCell] = "isActiveCell";


    return roles;
}

int GameControllerModel::columnCount(const QModelIndex& parent) const
{
    Q_UNUSED(parent)
    return 8;
}
