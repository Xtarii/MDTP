#include <socket/connection/MDTPConnection.h>

#include <sstream>



void MDTPConnection::write(const MDTPOptions& options) const {
    std::stringstream buffer;

    // Constructs Header
    buffer << options.version << " | ";
    buffer << "body-length " << (options.body ? strlen(options.body) : 0) << " | ";
    buffer << options.command << "\r\n";
    buffer << "\r\n"; // End of Header


    // Constructs Body
    buffer << (options.body ? options.body : "") << "\r\n";
    buffer << MDTP_EOD;


    const std::string res = buffer.str(); // Constructs String and Sends to Client
    ::send(socket, res.c_str(), static_cast<int>(res.size()), 0);
}
