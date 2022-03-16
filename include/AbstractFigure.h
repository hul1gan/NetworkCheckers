#pragma once

#include <QString>
#include <QObject>

class AbstractFigure: public QObject
{
    Q_OBJECT
    Q_PROPERTY(bool isActiveCell READ isActiveCell WRITE setActive NOTIFY activeCellChanged)
    Q_PROPERTY(bool isSelected READ isSelected WRITE setSelectCell NOTIFY selectChanged)
    Q_PROPERTY(QString imgPath READ getImgPath WRITE setImgPath NOTIFY imgPathChanged)
    Q_PROPERTY(bool isContainFigure READ isContainFigure WRITE setContainFigure NOTIFY containFigureChanged)

public:

    AbstractFigure(QObject* parent = nullptr);

    virtual ~AbstractFigure();

    int rowPosition;
    int colPosition;

    void setPosition(int row, int col);


    bool isActiveCell() const;
    void setActive(bool newIsActiveCell);

    bool isSelected() const;
    void setSelectCell(bool newIsSelected);

    const QString &getImgPath() const;
    void setImgPath(const QString &newImgPath);

    bool isContainFigure() const;
    void setContainFigure(bool newIsContainFigure);

signals:
    void activeCellChanged();

    void selectChanged();

    void imgPathChanged();

    void containFigureChanged();

private:

    bool m_isActiveCell = false;
    bool m_isSelected = false;
    bool m_isContain = false;

    QString m_imgPath = "";

    bool m_isContainFigure;
};



