#pragma once

#include <QTcpServer>
#include <QObject>

class Server: public QObject {
    Q_OBJECT

public:
    Server();
private:
    QTcpServer* m_ptcpServer;


};
