#include "MDTP/socket/MDTPServer.h"

#include <MDTP/core.h>


MDTPServer::MDTPServer(const int port) {
    service.sin_family = AF_INET;
    service.sin_addr.s_addr = INADDR_ANY;
    service.sin_port = htons(port);


#ifdef _WIN32 // Windows : Server Listener
    if(::bind(socket, reinterpret_cast<SOCKADDR*>(&service), sizeof(service)) == SOCKET_ERROR)
        throw MDTP::NetworkException("Binding failed: " + WSAGetLastError());

    if(::listen(this->socket, SOMAXCONN) == SOCKET_ERROR)
        throw MDTP::NetworkException("Listen Failed: " + WSAGetLastError());
#endif
}





MDTPConnection MDTPServer::accept() const {
    const SOCKET client = ::accept(this->socket, nullptr, nullptr);
    if(client == INVALID_SOCKET) {
        throw MDTP::NetworkException("Invalid client: " + WSAGetLastError());
    }
    return MDTPConnection(client);
}
