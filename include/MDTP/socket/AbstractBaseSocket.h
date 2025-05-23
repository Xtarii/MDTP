#ifndef ABSTRACTBASESOCKET_H
#define ABSTRACTBASESOCKET_H

#include <MDTP/parser/parser.h>

#include <MDTP/core.h>

#ifdef _WIN32
#include <winsock2.h>
#endif



/**
 * Abstract Base Socket
 *
 * A basic MDTP socket base.
 * Used to create Server and
 * Client Sockets for MDTP
 * communication.
 */
class AbstractBaseSocket {
protected:
#ifdef _WIN32
    /**
     * Socket Instance
     */
    SOCKET socket;
#endif

    /**
     * Socket Connection Service Information
     */
    sockaddr_in service{};



public:
    /**
     * Abstract Base Socket
     *
     * Creates a socket instance
     *
     * @throw MDTP::NetworkException Socket creation exceptions.
     */
    AbstractBaseSocket();
    /**
     * Abstract Base Socket
     *
     * Creates a socket instance from
     * a socket pointer.
     */
    explicit AbstractBaseSocket(SOCKET socket);





    virtual ~AbstractBaseSocket();


    /**
     * Reads {@link MDTPObject}
     *
     * Reads data sent to this socket
     * and parses it into {@link MDTPObject}.
     *
     * @return Data Object
     * @throw ParserException If the parsing of the object
     * sent to this socket fails a {@link ParserException} is thrown.
     */
    [[nodiscard]] MDTPObject read() const;
};

#endif //ABSTRACTBASESOCKET_H
