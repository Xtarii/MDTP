#include <MDTP/socket/MDTPClient.h>

#include <ws2tcpip.h>
#include <sstream>



MDTPClient::MDTPClient(const char* host, const int port) {
    service.sin_family = AF_INET;
    service.sin_port = htons(port);
    inet_pton(AF_INET, host, &service.sin_addr);
}





MDTPObject MDTPClient::fetch(const char* data, const MDTPOptions& options) {
    if(connect(socket, reinterpret_cast<sockaddr*>(&service), sizeof(service)) == SOCKET_ERROR)
        throw MDTP::NetworkException("Connect failed: " + WSAGetLastError());
    std::stringstream buffer;

    // Creates Header
    buffer << options.version << " | ";
    buffer << "body-length " << (options.body ? strlen(options.body) : 0) << " | ";
    buffer << options.command << " " << data << "\r\n";
    buffer << "\r\n"; // End of Header

    // Constructs Body
    buffer << (options.body ? options.body : "") << "\r\n";
    buffer << MDTP_EOD; // Ends MDTP Data


    const std::string res = buffer.str();
    ::send(socket, res.c_str(), static_cast<int>(res.size()), 0);


    // Cleanup and Response
    MDTPObject response = read();
    closesocket(socket);
    return response;
}
