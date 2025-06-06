#ifndef PARSER_H
#define PARSER_H

#include <string>

#include "header/MDTPHeader.h"



/**
 * Parser Exception
 */
class ParserException : public std::exception {
    /**
     * Error Message
     */
    const char* error;



    public:
        /**
         * Casts a Parser Exception with the message **cause**
         */
        explicit ParserException(const char* cause) { this->error = cause; }

        const char* what() const noexcept override {
            return (std::string(exception::what()) + error).c_str(); // Not good I know
        }
};



/**
 * MDTP Response and Request Object
 *
 * Both Requests and Responses uses
 * the same layout and structure.
 */
struct MDTPObject {
    /**
     * Header Data
     */
    MDTPHeader header;
    /**
     * Body
     */
    std::string body;



    /**
     * Converts the Header Object to a string
     *
     * @return The Header Object as a String
     */
    [[nodiscard]] std::string toString() const {
        return std::string("{ header " + header.toString() + ", body " + body + " }");
    }
};





/**
 * Parses MDTP Objects from raw string
 *
 * @return MDTP Object
 * @throws ParserException A parser exception gets thrown if there
 * was an exception during parsing.
 */
MDTPObject parseObject(const std::string& raw);

#endif //PARSER_H
