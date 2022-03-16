#include <include/GameController.h>

GameController::GameController(QObject *parent) : QAbstractListModel(parent)
{
    m_data.reserve(boardSize*boardSize);
    m_data.shrink_to_fit();

    boardInit();
}

GameController::~GameController(){}


void GameController::findWay(int rowPosition, int colPosition)
{


    cancelSelectedCells();

    int index = (rowPosition-1) * 8 + colPosition;

    m_data[index - 1]->setSelectCell(true);
    _selectedCells.push_back(index - 1);

    int row;

    if(rowPosition != 1)
    {
        row = rowPosition - 1;
    }

    int col1;
    int col2;

    if(colPosition == 1)
    {
        col1 = colPosition + 1;
    }

    else if(colPosition == boardSize)
    {
        col1 = colPosition - 1;
    }
    else
    {
        col1 = colPosition - 1;
        col2 = colPosition + 1;
    }

    //qDebug() << rowPosition << colPosition;

    int counter = 0;

    for(auto& element: m_data){

        if(row == element->rowPosition){

            if (col1 == element->colPosition || col2 == element->colPosition)
            {
                element->setSelectCell(true);
                _selectedCells.push_back(counter);
                dataChanged(createIndex(0,0), createIndex(8, 8));
            }

        }
        counter++;
    }
}




void GameController::boardInit()
{
    int sizeBoard = boardSize * boardSize;

    int row = 1;
    int col = 1;

    for(int i = 0; i < sizeBoard; ++i){

        m_data.push_back(createFigure(row, col));

        col++;

        if(col > boardSize)
        {
            row++;
            col = 1;
        }

        //qDebug() << m_data[i]->isActiveCell();
    }

}


int GameController::rowCount(const QModelIndex &parent) const
{
    if(parent.isValid()){

        return 0;
    }

    Q_UNUSED(parent);

    return boardSize;
}

QVariant GameController::data(const QModelIndex &index, int role) const
{
    if (!index.isValid())
    {
        return QVariant();
    }

    int row = index.row();
    int column = index.column();

    int elIndex = (boardSize * row ) + column ;

    switch (role)
    {
    case Roles::RowPosition:
    {
        return QVariant::fromValue(m_data[elIndex]->rowPosition);
    }
    case Roles::ColPosition:
    {
        return QVariant::fromValue(m_data[elIndex]->colPosition);
    }
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

bool GameController::setData(const QModelIndex &index, const QVariant &value, int role)
{
    if (!index.isValid()) {
        return false;
    }

    switch (role) {
    case Roles::RowPosition:
    {
        m_data[index.row()]->rowPosition = value.toInt();
        break;
    }
    case Roles::ColPosition:
    {
        m_data[index.row()]->colPosition = value.toInt();
        break;
    }

        emit dataChanged(index, index, QVector<int>() << role);

        return true;

    }
}

QHash<int, QByteArray> GameController::roleNames() const
{
    QHash<int, QByteArray> roles = QAbstractListModel::roleNames();
    roles[RowPosition] = "rowPosition";
    roles[ColPosition] = "colPosition";
    roles[FigureRole] = "figure";


    return roles;
}

int GameController::columnCount(const QModelIndex& parent) const
{
    Q_UNUSED(parent)

    return boardSize;
}

bool GameController::isFlippedBoard()
{
    return _isFlippedBoard;
}

AbstractFigure* GameController::createFigure(int row, int col)
{
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
        newChecker->setImgPath("qrc:/Pictures/2.svg");
        newChecker->setActive(true);
        newChecker->setContainFigure(true);
        return newChecker;
    }
    else if(row > 5)
    {
        Checker* newChecker = new Checker();
        newChecker->setPosition(row, col);
        newChecker->setImgPath("qrc:/Pictures/1.svg");
        newChecker->setActive(true);
        newChecker->setContainFigure(true);
        return newChecker;
    }
    else
    {
        VoidChecker* newChecker = new VoidChecker();
        newChecker->setPosition(row, col);
        newChecker->setActive(true);
        return newChecker;
    }
}

void GameController::cancelSelectedCells()
{
    for(int i = 0; i < _selectedCells.size(); ++i)
    {
        m_data[_selectedCells.at(i)]->setSelectCell(false);
        qDebug() << i;
    }

    _selectedCells.clear();
}

