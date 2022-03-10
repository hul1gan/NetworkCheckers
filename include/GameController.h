#ifndef MODEL_H
#define MODEL_H

#include <include/AbstractFigure.h>

#include <QObject>
#include <QAbstractTableModel>

#include <algorithm>



class GameController: public QAbstractTableModel
{
    Q_OBJECT

    Q_PROPERTY(bool isFlippedBoard READ isFlippedBoard)

public:
    explicit GameController(QObject *parent = nullptr);
    ~GameController();

    enum Roles
    {
        RowPosition = Qt::UserRole + 1,
        ColPosition,
        IsEmptyCell,
        IsActiveCell,
        IsHighlightedCell,
        Color,
        IsKing,
        IsSelected
    };

    Q_INVOKABLE void findWay(int rowPosition, int colPosition);

    void setStartBoard();
    void setFigure(AbstractFigure* ptr, int& rowPosition, int& colPosition);

    virtual int rowCount(const QModelIndex &parent) const override;
    virtual QVariant data(const QModelIndex &index, int role) const override;

    virtual bool setData(const QModelIndex &index, const QVariant &value, int role) override;

    virtual QHash<int, QByteArray> roleNames() const override;

    virtual int columnCount(const QModelIndex& parent) const override;

    bool isFlippedBoard();

    static const int boardSize = 8;

private:

    QVector<AbstractFigure*> m_data;

    bool _isFlippedBoard = false;
};



#endif // MODEL_H
