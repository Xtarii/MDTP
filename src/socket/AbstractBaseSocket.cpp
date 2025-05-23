#include "socket/AbstractBaseSocket.h"

#include <library.h>


AbstractBaseSocket::AbstractBaseSocket() {
    MDTP::init();

#ifdef _WIN32 // Windows Sockets
    this->socket = ::socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
    if(this->socket == INVALID_SOCKET) {
        throw MDTP::NetworkException("Could not create a socket instance: " + WSAGetLastError());
    }
#endif
}

AbstractBaseSocket::AbstractBaseSocket(const SOCKET socket) {
    MDTP::init();
    this->socket = socket;
}





MDTPObject AbstractBaseSocket::read() const {
    char buffer[2048];
    std::string complete;

    int bytes; // Reads a message unknown of the size
    while((bytes = recv(this->socket, buffer, 2048, 0)) > 0) {
        complete.append(buffer, bytes);
        if(complete.ends_with(MDTP_EOD)) {
            complete.erase(complete.size() - strlen(MDTP_EOD));
            break; // END OF DATA
        }
    }
    return parseObject(complete);
}





AbstractBaseSocket::~AbstractBaseSocket() {
    closesocket(this->socket);
    MDTP::clean();
}
