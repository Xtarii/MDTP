#include "library.h"

#ifdef _WIN32
#include <winsock2.h>
#include <ws2tcpip.h>

#pragma comment (lib, "Ws2_32.lib")
#endif


namespace MDTP {
    void init() {
    #ifdef _WIN32
        WSADATA wsaData;
        if(const int res = WSAStartup(MAKEWORD(2, 2), &wsaData); res != 0) {
            std::cerr << "WSAStartup failed: " << res << std::endl;
            throw std::exception();
        }
    #endif
    }



    void clean() {
    #ifdef _WIN32
        WSACleanup();
    #endif
    }





    /**
     * Trims spaces from string
     *
     * @param str String Object
     * @return Trimmed version of String
     */
    std::string trim(const std::string& str) {
        const auto strBegin = std::ranges::find_if_not(str, ::isspace);
        const auto strEnd = std::ranges::find_if_not(str.rbegin(), str.rend(), ::isspace).base();
        if (strBegin >= strEnd)
            return "";
        return std::string(strBegin, strEnd);
    }
}
