#pragma once

#include <include/AbstractFigure.h>
#include <include/Checker.h>
#include <include/VoidChecker.h>
#include <include/Server.h>

#include <QObject>
#include <QAbstractListModel>

#include <algorithm>

class GameController: public QAbstractListModel
{
    Q_OBJECT

public:

    explicit GameController(QObject *parent = nullptr);
    ~GameController();

    enum Roles
    {
        FigureRole = Qt::UserRole + 1
    };

    Q_INVOKABLE void findPossibleMoves(int rowPosition, int colPosition);
    Q_INVOKABLE void tryToSwap(int newRow, int newColumn);

    void checkCutDownMoves(int row, int col);

    void setCheckerColorSelection(bool isWhite);


    void boardInit();
    void swap(int indexPrevius, int indexNew);

    virtual int rowCount(const QModelIndex &parent) const override;
    virtual QVariant data(const QModelIndex &index, int role) const override;
    virtual QHash<int, QByteArray> roleNames() const override;
    virtual int columnCount(const QModelIndex& parent) const override;


    AbstractFigure* createFigure(int row, int cal);

    static const int BOARDROWSIZE = 8;

private:

    QVector<AbstractFigure*> m_data;
    QVector<int> _indexOfHightlightCells;

    int _currentSelectesCellIndex;

    void _cancelSelectedCells();
    void _highlightCheckerCells(int row, int col1, int col2 = 0);

    bool _isWhiteColor = true;

    Server* _server;


    bool _isMyLine = true;    //temporary

    int _calculateindex(int row, int col);

    bool _isCellExist(int row, int col);
};





