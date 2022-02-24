#ifndef MODEL_H
#define MODEL_H

#include<include/Checker.h>
#include<include/Cell.h>

#include <QObject>
#include <QAbstractTableModel>

class GameController: public QAbstractTableModel
{
        Q_OBJECT
public:
    explicit GameController(QObject *parent = nullptr);

    enum Roles
    {
        RowPosition = Qt::UserRole + 1,
        ColPosition,
        IsEmptyCell,
        IsActiveCell,
        Color,
        IsKing,

    };

    Q_INVOKABLE void findWay(int rowPosition, int colPosition);

    void setStartBoard();

    virtual int rowCount(const QModelIndex &parent) const override;
    virtual QVariant data(const QModelIndex &index, int role) const override;

    virtual bool setData(const QModelIndex &index, const QVariant &value, int role) override;
    //virtual Qt::ItemFlags flags(const QModelIndex &index) const override;

    // QAbstractItemModel interface
    virtual QHash<int, QByteArray> roleNames() const override;

    virtual int columnCount(const QModelIndex& parent) const override;

private:
    QVector<Checker> m_data;
    QVector<Cell> m_cell;

};



#endif // MODEL_H
