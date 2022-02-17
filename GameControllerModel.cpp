#include <GameControllerModel.h>

GameControllerModel::GameControllerModel(QObject *parent) : QAbstractListModel(parent){

    m_data.reserve(64);

    setTheStartBoard();


}

void GameControllerModel::setTheStartBoard()
{

    for(int i = 0; i < 64; i++){

    //qDebug() << "m_data.push_back(Checker{});" << i;

        m_data.push_back(Checker{});

    }
}



int GameControllerModel::rowCount(const QModelIndex &parent) const
{
    if(parent.isValid()){

        return 0;
    }

    return 8;
}

QVariant GameControllerModel::data(const QModelIndex &index, int role) const
{
    if (!index.isValid())
    {
        return QVariant();
    }

    switch (role)
    {
    case Roles::Position:
    {
        return QVariant::fromValue(m_data.at(index.row()).position);
    }
    case Roles::IsEmptyCell:
    {
        return QVariant::fromValue(m_data.at(index.row()).isEmptyCell);
    }
    case Roles::Color:
    {
        return QVariant::fromValue(m_data.at(index.row()).color);
    }
    case Roles::IsKing:
    {
        return QVariant::fromValue(m_data.at(index.row()).isKing);
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
        m_data[index.row()].color = value.toBool();
        break;
    }
    case Roles::IsKing:
    {
        m_data[index.row()].isKing = value.toBool();
        break;
    }

    }

    emit dataChanged(index, index, QVector<int>() << role);

    return true;
}

Qt::ItemFlags GameControllerModel::flags(const QModelIndex &index) const
{
    if (!index.isValid())
        return Qt::ItemIsEnabled;

    return QAbstractListModel::flags(index) | Qt::ItemIsEditable;
}

QHash<int, QByteArray> GameControllerModel::roleNames() const
{

    QHash<int, QByteArray> roles = QAbstractListModel::roleNames();
    roles[Position] = "position";
    roles[IsEmptyCell] = "isEmptyCell";
    roles[Color] = "color";
    roles[IsKing] = "isKing";


    return roles;
}

int GameControllerModel::columnCount(const QModelIndex &) const
{
    return 8;
}
