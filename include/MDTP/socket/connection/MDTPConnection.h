#ifndef MDTPCONNECTION_H
#define MDTPCONNECTION_H
#include <MDTP/data/MDTPOptions.h>
#include <MDTP/socket/AbstractBaseSocket.h>

/**
 * MDTP Connection Socket
 *
 * Used by the **MDTPServer** to
 * handle connected clients.
 */
class MDTPConnection : public AbstractBaseSocket {
public:
    /**
     * Creates a MDTP connection socket
     *
     * Used to handle clients connected to
     * a server socket.
     */
    explicit MDTPConnection(SOCKET socket) : AbstractBaseSocket(socket) {}





    /**
     * Writes Data to the connected client
     */
    void write(const MDTPOptions& options) const;
};

#endif //MDTPCONNECTION_H
