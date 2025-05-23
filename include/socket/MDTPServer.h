#ifndef MDTPSERVERSOCKET_H
#define MDTPSERVERSOCKET_H

#include "AbstractBaseSocket.h"
#include "connection/MDTPConnection.h"

/**
 * MDTP Server Socket
 *
 * Simple Socket for communication
 * with MDTP Clients.
 */
class MDTPServer : AbstractBaseSocket {
public:
    /**
     * Creates a MDTP Server Socket Instance
     *
     * @param port The port on which the server should communicate on
     * @throw MDTP::NetworkException Server Initialization Exceptions, typically
     * thrown if the port is already used and so the socket binding was unsuccessful.
     */
    explicit MDTPServer(int port = MDTP_PORT);



#ifdef _WIN32
    /**
     * Accept Method
     *
     * Accepts incoming connection requests and
     * returns the socket.
     *
     * @return Socket that connected to this server socket.
     * @throw MDTP::NetworkException Client Connection Exception if there was
     * any error when accepting clients connecting to this server socket.
     */
    [[nodiscard]] MDTPConnection accept() const;
#endif
};

#endif //MDTPSERVERSOCKET_H
