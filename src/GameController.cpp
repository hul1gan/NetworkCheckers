#include <include/GameController.h>

GameController::GameController(QObject *parent) : QAbstractListModel(parent)
{
    m_data.reserve(BOARDROWSIZE*BOARDROWSIZE);
    m_data.shrink_to_fit();

    boardInit();
}

GameController::~GameController(){}


void GameController::findPossibleMoves(int rowPosition, int colPosition)
{
    int indexSelectedChecker = _calculateindex(rowPosition, colPosition);

    checkCutDownMoves(rowPosition, colPosition);

    if(!m_data[indexSelectedChecker]->isPlayable())
    {
        return;
    }

    if(m_data[indexSelectedChecker]->_enemyСhecker) //temporary
    {
        _currentSelectesCellIndex = indexSelectedChecker;
        return;
    }

    //_cancelSelectedCells();

    m_data[indexSelectedChecker]->setSelectCell(true);
    _currentSelectesCellIndex = indexSelectedChecker;

    int rowPossibleMove;
    int columnPossibleMove;
    int columnPossibleMove2 = 0;

    if(rowPosition != 1)
    {
        rowPossibleMove = rowPosition - 1;
    }
    else
    {
        return;
    }

    if(colPosition == 1)
    {
        columnPossibleMove = colPosition + 1;

    }

    else if(colPosition == BOARDROWSIZE)
    {
        columnPossibleMove = colPosition - 1;
    }
    else
    {
        columnPossibleMove = colPosition - 1;
        columnPossibleMove2 = colPosition + 1;
    }

    _highlightCheckerCells(rowPossibleMove, columnPossibleMove, columnPossibleMove2);


}

void GameController::tryToSwap(int newRow, int newColumn)
{

    if(m_data[_currentSelectesCellIndex]->_enemyСhecker)  //temporary
    {
        int index = ((newRow - 1) * BOARDROWSIZE + newColumn) - 1;
        swap(_currentSelectesCellIndex, index);
    }
    for(qsizetype i = 0; i < _indexOfCutDown.size(); i++)
    {
        if(m_data[_indexOfCutDown[i].newIndex]->getColumn() == newColumn && m_data[_indexOfCutDown[i].newIndex]->getRow() == newRow)
        {
            _cutDown(_indexOfCutDown[i].indexOfChecker);
        }
    }
    for(qsizetype i = 0; i < _indexOfHightlightCells.size(); i++)
    {

        if(m_data[_indexOfHightlightCells[i]]->getColumn() == newColumn && m_data[_indexOfHightlightCells[i]]->getRow() == newRow)
        {
            int index = ((newRow - 1) * BOARDROWSIZE + newColumn) - 1;
            swap(_currentSelectesCellIndex, index);
        };
    }

}

void GameController::checkCutDownMoves(int row, int col)
{
    if(m_data[_calculateindex(row, col)]->_enemyСhecker)
    {
        return;
    }
    int possibleRow1 = row - 1;
    int possibleRow2 = row + 1;
    int possibleCol1 = col - 1;
    int possibleCol2 = col + 1;

    if(_isCellExist(possibleRow1, possibleCol1))
    {
        if(m_data[_calculateindex(possibleRow1, possibleCol1)]->_enemyСhecker){

            if(_isCellExist(possibleRow1 - 1, possibleCol1 - 1))
            {

                if(!m_data[_calculateindex(possibleRow1 - 1, possibleCol1 - 1)]->isContainFigure())
                {
                    _indexOfCutDown.push_back(MyPair{_calculateindex(possibleRow1 - 1, possibleCol1 - 1), _calculateindex(possibleRow1, possibleCol1)});
                    _highlightCheckerCells(possibleRow1 - 1, possibleCol1 - 1);
                    //checkCutDownMoves(possibleRow1 - 1, possibleCol1 - 1);
                }
            }

        }
    }
    if(_isCellExist(possibleRow1, possibleCol2))
    {
        if(m_data[_calculateindex(possibleRow1, possibleCol2)]->_enemyСhecker){

            if(_isCellExist(possibleRow1 - 1, possibleCol2 + 1))
            {
                if(!m_data[_calculateindex(possibleRow1 - 1, possibleCol2 + 1)]->isContainFigure())
                {
                    _indexOfCutDown.push_back(MyPair{_calculateindex(possibleRow1 - 1, possibleCol2 + 1), _calculateindex(possibleRow1, possibleCol2)});
                    _highlightCheckerCells(possibleRow1 - 1, possibleCol2 + 1);
                    //checkCutDownMoves(possibleRow1 - 1, possibleCol2 + 1);
                }
            }

        }

    }

    if(_isCellExist(possibleRow2, possibleCol1))
    {
        if(m_data[_calculateindex(possibleRow2, possibleCol1)]->_enemyСhecker){

            if(_isCellExist(possibleRow2 + 1, possibleCol1 - 1))
            {
                if(!m_data[_calculateindex(possibleRow2 + 1, possibleCol1 - 1)]->isContainFigure())
                {
                    _indexOfCutDown.push_back(MyPair{_calculateindex(possibleRow2 + 1, possibleCol1 - 1), _calculateindex(possibleRow2, possibleCol1)});
                    _highlightCheckerCells(possibleRow2 + 1, possibleCol1 - 1);
                }
            }

        }


    }
    if(_isCellExist(possibleRow2, possibleCol2))
    {
        if(m_data[_calculateindex(possibleRow2, possibleCol2)]->_enemyСhecker){

            if(_isCellExist(possibleRow2 + 1, possibleCol2 + 1))
            {
                if(!m_data[_calculateindex(possibleRow2 + 1, possibleCol2 + 1)]->isContainFigure())
                {
                    _indexOfCutDown.push_back(MyPair{_calculateindex(possibleRow2 + 1, possibleCol2 + 1), _calculateindex(possibleRow2, possibleCol2)});
                    _highlightCheckerCells(possibleRow2 + 1, possibleCol2 + 1);
                }
            }

        }
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
        newChecker->setContainFigure(false);
        return newChecker;

    }
    else if(row < 4)
    {
        Checker* newChecker = new Checker();
        newChecker->setPosition(row, col);
        newChecker->setImgPath(path1);
        newChecker->setActiveCell(true);
        newChecker->setContainFigure(true);


        newChecker->_enemyСhecker = true; //temporary
        newChecker->setPlayable(true); //temporary

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
        newChecker->setContainFigure(false);
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

void GameController::_highlightCheckerCells(int row, int col1, int col2)
{
    int index1 = _calculateindex(row, col1);
    int index2 = _calculateindex(row, col2);

    if(_isCellExist(row, col1))
    {
        if(!m_data[index1]->isPlayable()){

            m_data[index1]->setHighLightCell(true);
            _indexOfHightlightCells.push_back(index1);
            dataChanged(createIndex(0,0), createIndex(BOARDROWSIZE, BOARDROWSIZE));
        }
        if(_isCellExist(row, col2))
        {

            if(!m_data[index2]->isPlayable()){

                m_data[index2]->setHighLightCell(true);
                _indexOfHightlightCells.push_back(index2);
                dataChanged(createIndex(0,0), createIndex(BOARDROWSIZE, BOARDROWSIZE));
            }
        }

    }
}

inline int GameController::_calculateindex(int row, int col)
{
    return ((row-1) * BOARDROWSIZE + col) - 1;
}

bool GameController::_isCellExist(int row, int col)
{

    if(row <= 0 || col <= 0 || col > BOARDROWSIZE || row > BOARDROWSIZE)
    {
        return false;
    }

    return true;
}

void GameController::_cutDown(int index)
{

    m_data[index]->setImgPath("");
    m_data[index]->_enemyСhecker = false;

    _indexOfCutDown.clear();

    dataChanged(createIndex(0,0), createIndex(BOARDROWSIZE, BOARDROWSIZE));

}
