#include <include/GameController.h>

GameController::GameController(QObject *parent) : QAbstractListModel(parent)
{
    m_data.reserve(BOARDROWSIZE*BOARDROWSIZE);
    m_data.shrink_to_fit();

    boardInit();
}

GameController::~GameController(){}


void GameController::findPossibleWays(int rowPosition, int colPosition)
{

    //qDebug() << rowPosition << colPosition << "BEFORE";

    int index = (rowPosition-1) * BOARDROWSIZE + colPosition;

    if(!m_data[index - 1]->isPlayable())
    {
        return;
    }

    _cancelSelectedCells();

    m_data[index - 1]->setSelectCell(true);
    dataChanged(createIndex(0,0), createIndex(BOARDROWSIZE, BOARDROWSIZE));
    _currentSelectesCellIndex = index - 1;


    //_indexOfHightlightCells.push_back(index - 1);

    int row;

    if(rowPosition != 1)
    {
        row = rowPosition - 1;
    }
    else
    {
        return;
    }

    int colPosition1;
    int colPosition2 = 0;

    if(colPosition == 1)
    {
        colPosition1 = colPosition + 1;

    }

    else if(colPosition == BOARDROWSIZE)
    {
        colPosition1 = colPosition - 1;
    }
    else
    {
        colPosition1 = colPosition - 1;
        colPosition2 = colPosition + 1;
    }

    //qDebug() << rowPosition << col1 << col2;



    for(int i = 0; i < m_data.size(); i++){

        if(row == m_data[i]->getRow()){

            if (colPosition1 == m_data[i]->getColumn()|| colPosition2 == m_data[i]->getColumn())
            {
                m_data[i]->setHighLightCell(true);
                _indexOfHightlightCells.push_back(i);
                dataChanged(createIndex(0,0), createIndex(BOARDROWSIZE, BOARDROWSIZE));
              // qDebug() << "FIND" << m_data[i]->getRow() << m_data[i]->getColumn() << i;
            }

        }

    }

}

void GameController::checkPossibilityMove(int newRow, int newColumn)
{


    for(qsizetype i = 0; i < _indexOfHightlightCells.size(); i++)
    {
        if(m_data[_indexOfHightlightCells[i]]->getColumn() == newColumn && m_data[_indexOfHightlightCells[i]]->getRow() == newRow)
        {
            int index = ((newRow - 1) * BOARDROWSIZE + newColumn) - 1;
            swap(_currentSelectesCellIndex, index);
           //qDebug() << m_data[_currentSelectesCellIndex]->isHighLightCell();

        };
    }

}

void GameController::setCheckerColorSelection(bool isWhite)
{
    if(_isWhiteColor == isWhite)

    {
        return;
    }

    _isWhiteColor = isWhite;

}



void GameController::boardInit()
{
    int sizeBoard = BOARDROWSIZE * BOARDROWSIZE;

    int row = 1;
    int col = 1;

    for(int i = 0; i < sizeBoard; ++i){

        m_data.push_back(createFigure(row, col));

        col++;

        if(col > BOARDROWSIZE)
        {
            row++;
            col = 1;
        }

        //qDebug() << m_data[i]->isActiveCell();
    }

}

void GameController::swap(int indexPrevius, int indexNew)
{
    m_data[_currentSelectesCellIndex]->setSelectCell(false);
    _currentSelectesCellIndex = -1;

    int newPosRow = m_data[indexNew]->getRow();
    int newPosCol = m_data[indexNew]->getColumn();

    int oldPosRow = m_data[indexPrevius]->getRow();
    int oldPosCol = m_data[indexPrevius]->getColumn();

    AbstractFigure* numerousObject;
    numerousObject = m_data[indexPrevius];
    numerousObject->setPosition(newPosRow, newPosCol);

    m_data[indexNew]->setHighLightCell(false);

    m_data[indexPrevius] = m_data[indexNew];

    m_data[indexPrevius]->setPosition(oldPosRow, oldPosCol);

    m_data[indexNew] = numerousObject;

    _cancelSelectedCells();

    dataChanged(createIndex(0,0), createIndex(BOARDROWSIZE, BOARDROWSIZE));

}

int GameController::rowCount(const QModelIndex &parent) const
{
    if(parent.isValid()){

        return 0;
    }

    Q_UNUSED(parent);

    return BOARDROWSIZE;
}

QVariant GameController::data(const QModelIndex &index, int role) const
{
    if (!index.isValid())
    {
        return QVariant();
    }

    int row = index.row();
    int column = index.column();

    int elIndex = (BOARDROWSIZE * row ) + column ;

    switch (role)
    {
    case FigureRole:
    {
        return QVariant::fromValue(m_data[elIndex]);
    }


    default:
    {
        return QVariant();
    }

    }

}



QHash<int, QByteArray> GameController::roleNames() const
{
    QHash<int, QByteArray> roles = QAbstractListModel::roleNames();
    roles[FigureRole] = "figure";

    return roles;
}

int GameController::columnCount(const QModelIndex& parent) const
{
    Q_UNUSED(parent)

    return BOARDROWSIZE;
}


AbstractFigure* GameController::createFigure(int row, int col)
{
    QString path1 = "qrc:/Pictures/1.svg";
    QString path2 = "qrc:/Pictures/2.svg";

    if(_isWhiteColor)
    {
        path1.swap(path2);
    }


    if((row%2 != 0 && col%2 != 0) || (row%2 == 0 && col%2 == 0))
    {
        VoidChecker* newChecker = new VoidChecker();
        newChecker->setPosition(row, col);
        return newChecker;
    }
    else if(row < 4)
    {
        Checker* newChecker = new Checker();
        newChecker->setPosition(row, col);
        newChecker->setImgPath(path1);
        newChecker->setActiveCell(true);
        newChecker->setContainFigure(true);
        return newChecker;
    }
    else if(row > 5)
    {
        Checker* newChecker = new Checker();
        newChecker->setPosition(row, col);
        newChecker->setImgPath(path2);
        newChecker->setActiveCell(true);
        newChecker->setContainFigure(true);
        newChecker->setPlayable(true);
        return newChecker;
    }
    else
    {
        VoidChecker* newChecker = new VoidChecker();
        newChecker->setPosition(row, col);
        newChecker->setActiveCell(true);
        return newChecker;
    }
}

void GameController::_cancelSelectedCells()
{

    for(qsizetype i = 0; i < _indexOfHightlightCells.size(); i++)
    {
        m_data[_indexOfHightlightCells[i]]->setHighLightCell(false);
    }

    _indexOfHightlightCells.clear();
}
