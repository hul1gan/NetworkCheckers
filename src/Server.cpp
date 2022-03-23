#include <include/Server.h>


Server::Server()
{
    m_ptcpServer = new QTcpServer(this);

    if (!m_ptcpServer->listen(QHostAddress::Any)) {
        m_ptcpServer->close();
        return;
    }
    //connect(m_ptcpServer, &QTcpServer::newConnection, this, SLOT(slotNewConnection()));

}
