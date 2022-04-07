#pragma once

#include <QString>
#include <QObject>

class AbstractFigure: public QObject
{
    Q_OBJECT
    Q_PROPERTY(bool isActiveCell READ isActiveCell WRITE setActiveCell NOTIFY activeCellChanged)
    Q_PROPERTY(bool isSelectedCell READ isSelectedCell WRITE setSelectCell NOTIFY selectCellChanged)
    Q_PROPERTY(QString imgPath READ getImgPath WRITE setImgPath NOTIFY imgPathChanged)
    Q_PROPERTY(bool isContainFigure READ isContainFigure WRITE setContainFigure NOTIFY containFigureChanged)
    Q_PROPERTY(bool isHighLightCell READ isHighLightCell WRITE setHighLightCell NOTIFY highLightCellChanged)

public:

    AbstractFigure(QObject* parent = nullptr);
    virtual ~AbstractFigure();

    AbstractFigure(AbstractFigure& other) = default;


    void setPosition(int row, int col);
    int getRow();
    int getColumn();


    bool isActiveCell() const;
    void setActiveCell(bool newIsActiveCell);

    bool isSelectedCell() const;
    void setSelectCell(bool newIsSelected);

    const QString &getImgPath() const;
    void setImgPath(const QString &newImgPath);

    bool isContainFigure() const;
    void setContainFigure(bool newIsContainFigure);


    bool isHighLightCell() const;
    void setHighLightCell(bool newIsHighLightCell);

    void setPlayable(bool isPlayable);
    bool isPlayable();

    bool _enemyСhecker = false; //temporary

signals:
    void activeCellChanged();

    void selectCellChanged();

    void imgPathChanged();

    void containFigureChanged();

    void highLightCellChanged();

private:

    bool m_isActiveCell = false;
    bool m_isSelected = false;
    bool m_isContain = false;
    bool m_isHighLightCell = false;

    QString m_imgPath = "";

    bool m_isContainFigure;

    int _row;
    int _column;

    bool _isPlayable = false;

};



