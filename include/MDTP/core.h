#ifndef MDTP_LIBRARY_H
#define MDTP_LIBRARY_H

#include <iostream>


/**
 * MDTP Version
 */
#define MDTP_VERSION "MDTP 1.0"

/**
 * MDTP Default Port
 */
#define MDTP_PORT 50

/**
 * MDTP END OF DATA
 */
#define MDTP_EOD "\\EOD\r\n\r\n"





#define GET "GET"
#define STATUS_OK "200 OK"
#define STATUS_FAIL "400 FAIL"





#ifdef _WIN32
#endif





/**
 * MDTP Communication Namespace
 *
 * Data and Base functions used
 * by MDTP **( Markdown Transfer Protocol )**
 * sockets and methods.
 */
namespace MDTP {
    /**
     * Network Exception
     */
    class NetworkException : public std::exception {
        /**
         * Error Message
         */
        const char* error;



        public:
            /**
             * Throws a Network Exception
             */
            explicit NetworkException(const char* cause) { this->error = cause; }

            const char* what() const noexcept override {
                return (std::string(exception::what()) + error).c_str(); // Not good I know
            }
    };



    /**
     * Network Communication Base Initializer
     *
     * This is called before any socket creation
     * inorder to link and setup networking
     * on the operative system level
     *
     * @throws std::exception if there was an error during initialization
     */
    void init();

    /**
     * Network Communication Cleanup
     *
     * This is called to clean up
     * any network configs after
     * the {@link init()} method has been called.
     */
    void clean();





    /**
     * Trims spaces from string
     *
     * @param str String Object
     * @return Trimmed version of String
     */
    std::string trim(const std::string& str);
}

#endif //MDTP_LIBRARY_H
