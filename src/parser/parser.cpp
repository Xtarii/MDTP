#include "parser/parser.h"



MDTPObject parseObject(const std::string& raw) {
    MDTPObject response = {};

    std::string header;
    std::string body;
    for(char c : raw) { // Simple Data Splitter
        if(header.ends_with("\r\n\r\n")) body += c;
        else header += c;
    }

    response.header = parseHeader(header);
    response.body = body;
    return response;
}
