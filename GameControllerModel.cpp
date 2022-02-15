#include <GameControllerModel.h>

GameControllerModel::GameControllerModel(QObject *parent) : QAbstractListModel(parent){



}

void GameControllerModel::setTheStartBoard()
{

}


int GameControllerModel::rowCount(const QModelIndex &parent) const
{
    if(parent.isValid()){

        return 0;
    }

    return m_data.size();
}

QVariant GameControllerModel::data(const QModelIndex &index, int role) const
{
    if (!index.isValid())
    {
        return QVariant();
    }

    switch (role)
    {
    case Roles::TypeNameRole:
    {
        return QVariant::fromValue(m_data.at(index.row()).typeName);
    }
    case Roles::MakerNameRole:
    {
        return QVariant::fromValue(m_data.at(index.row()).makerName);
    }
    case Roles::MaterialNameRole:
    {
        return QVariant::fromValue(m_data.at(index.row()).materialName);
    }
    case Roles::ScoreRole:
    {
        return QVariant::fromValue(m_data.at(index.row()).score);
    }
    case Roles::CostRole:
    {
        return QVariant::fromValue(m_data.at(index.row()).cost);
    }
    case Roles::PathRole:
    {
        return QVariant::fromValue(m_data.at(index.row()).path);
    }
    case Roles::NumInStorageRole:
    {
      return QVariant::fromValue(m_data.at(index.row()).numberInStotage);
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
    case Roles::TypeNameRole:
    {
        m_data[index.row()].typeName = value.toString();
        break;
    }
    case Roles::MakerNameRole:
    {
        m_data[index.row()].makerName = value.toString();
        break;
    }
    case Roles::MaterialNameRole:
    {
        m_data[index.row()].materialName = value.toString();
        break;
    }
    case Roles::ScoreRole:
    {
        m_data[index.row()].score = value.toInt();
        break;
    }
    case Roles::CostRole:
    {
        m_data[index.row()].cost = value.toDouble();
        break;
    }
    case Roles::PathRole:
    {
        m_data[index.row()].path = value.toString();
        break;
    }
    case Roles::NumInStorageRole:
    {
        m_data[index.row()].numberInStotage = value.toInt();
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
    roles[TypeNameRole] = "typeText";
    roles[MakerNameRole] = "creator";
    roles[MaterialNameRole] = "materialText";
    roles[ScoreRole] = "score";
    roles[CostRole] = "costText";

    roles[PathRole] = "sourceImg";
    roles[NumInStorageRole] = "numOfStorage";

    return roles;
}
