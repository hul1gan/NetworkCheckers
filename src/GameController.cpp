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

    int index = (rowPosition-1) * 8 + colPosition;

    if(!m_data[index - 1]->isActiveCell())
    {
        return;
    }

    _cancelSelectedCells();

    m_data[index - 1]->setSelectCell(true);
    _currentSelectesCellIndex = index - 1;

    //m_data[index - 1]->setHighLightCell(true);

    //_indexOfHightlightCells.push_back(index - 1);

    int row;

    if(rowPosition != 1)
    {
        row = rowPosition - 1;
        if(_isFlippedBoard)
        {
            row = rowPosition + 1;
        }
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

    int counter = 0;

    for(auto& element: m_data){

        if(row == element->getRow()){

            if (colPosition1 == element->getColumn()|| colPosition2 == element->getColumn())
            {
                element->setHighLightCell(true);
                _indexOfHightlightCells.push_back(counter);
                dataChanged(createIndex(0,0), createIndex(8, 8));
            }

        }
        counter++;
    }
}

void GameController::checkPossibilityMove(int newRow, int newColumn)
{
    qDebug() << "checkPossibilityMove";

    for(qsizetype i = 0; i < _indexOfHightlightCells.size(); i++)
    {
        if(m_data[_indexOfHightlightCells[i]]->getColumn() == newColumn && m_data[_indexOfHightlightCells[i]]->getRow() == newRow)
        {
            int index = ((newRow - 1) * BOARDROWSIZE + newColumn) - 1;
            swap(_currentSelectesCellIndex, index);

        };
    }

    _currentSelectesCellIndex = -1;

}

bool GameController::isFlippedBoard()
{
    return _isFlippedBoard;
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

    AbstractFigure* numerousObject;
    numerousObject = m_data[indexPrevius];

    m_data[indexPrevius] = m_data[indexNew];

    m_data[indexNew] = numerousObject;

    _cancelSelectedCells();


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
    case FlippedBoard:
    {
        return QVariant::fromValue(_isFlippedBoard);
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
    roles[FlippedBoard]= "flip";

    return roles;
}

int GameController::columnCount(const QModelIndex& parent) const
{
    Q_UNUSED(parent)

    return BOARDROWSIZE;
}


AbstractFigure* GameController::createFigure(int row, int col)
{

    int blackCheckersArea = 4;
    int whiteCheckersArea = 5;

    if((row%2 != 0 && col%2 != 0) || (row%2 == 0 && col%2 == 0))
    {
        VoidChecker* newChecker = new VoidChecker();
        newChecker->setPosition(row, col);
        return newChecker;
    }
    else if(row < blackCheckersArea)
    {
        Checker* newChecker = new Checker();
        newChecker->setPosition(row, col);
        newChecker->setImgPath("qrc:/Pictures/2.svg");
        newChecker->setActiveCell(true);
        newChecker->setContainFigure(true);
        return newChecker;
    }
    else if(row > whiteCheckersArea)
    {
        Checker* newChecker = new Checker();
        newChecker->setPosition(row, col);
        newChecker->setImgPath("qrc:/Pictures/1.svg");
        newChecker->setActiveCell(true);
        newChecker->setContainFigure(true);
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
