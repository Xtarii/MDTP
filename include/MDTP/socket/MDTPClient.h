#ifndef MDTPCLIENT_H
#define MDTPCLIENT_H

#include <data/MDTPOptions.h>

#include "AbstractBaseSocket.h"


/**
 * MDTP Client
 */
class MDTPClient : public AbstractBaseSocket {
public:
    /**
     * Creates MDTP Client
     *
     * @param host Server Host, can also be domain
     * @param port Server Port, default is MDTP port
     * @throw MDTP::NetworkException Client Initialization Exceptions, typically
     * thrown if the connection could not be established.
     */
    explicit MDTPClient(const char* host, int port = MDTP_PORT);





    /**
     * Fetches Data
     *
     * Sends a data request to the connected endpoint
     * and returnes the response.
     *
     * @return Response from the connected endpoint
     */
    MDTPObject fetch(const char* data, const MDTPOptions& options = { .command = GET });
};

#endif //MDTPCLIENT_H
