#ifndef MODEL_H
#define MODEL_H

#include<Checker.h>

#include <QObject>
#include <QAbstractTableModel>

class GameControllerModel: public QAbstractTableModel
{
        Q_OBJECT
public:
    explicit GameControllerModel(QObject *parent = nullptr);

    enum Roles
    {
        Position = Qt::UserRole + 1,
        IsEmptyCell,
        IsActiveCell,
        Color,
        IsKing,

    };

private:
    QVector<Checker> m_data;

public:

    void setTheStartBoard();

    virtual int rowCount(const QModelIndex &parent) const override;
    virtual QVariant data(const QModelIndex &index, int role) const override;

    virtual bool setData(const QModelIndex &index, const QVariant &value, int role) override;
    //virtual Qt::ItemFlags flags(const QModelIndex &index) const override;

    // QAbstractItemModel interface
    virtual QHash<int, QByteArray> roleNames() const override;

    virtual int columnCount(const QModelIndex& parent) const override;
};



#endif // MODEL_H
