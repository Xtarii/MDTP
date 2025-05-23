#include "parser/header/MDTPHeader.h"

#include <library.h>
#include <parser/parser.h>


NodeToken convertToToken(std::string& raw) {
    if(raw == "MDTP") return NodeToken::VERSION;
    if(raw == "body-length") return NodeToken::BODY_LENGTH;
    return NodeToken::COMMAND;
}



MDTPNode parseNode(const std::string& rawNode) {
    MDTPNode node;

    bool isValue = false;
    for(const char c : rawNode) {
        if(c == ' ' && !isValue) {
            isValue = true;
            continue; // Skips Space
        }

        // Appends Character to Node
        if(isValue) node.value += c;
        else node.name += c;
    }
    node.type = convertToToken(node.name);
    return node;
}



std::vector<MDTPNode> getNodesFromHeader(const std::string& raw) {
    std::vector<MDTPNode> nodes;
    std::string current;

    for(const char c : raw) {
        if(c == '|') {
            nodes.push_back(parseNode(MDTP::trim(current)));
            current.clear();
            continue;
        }
        current += c;
    }
    nodes.push_back(parseNode(MDTP::trim(current)));
    current.clear(); // Adds Last Header Node
    return nodes;
}



MDTPHeader parseHeader(const std::string& raw) {
    MDTPHeader header = {};
    std::vector<MDTPNode> nodes = getNodesFromHeader(raw);
    for(auto& [type, name, value] : nodes) {
        switch(type) {
            case NodeToken::VERSION:
                header.version = name + " " += value;
            break;
            case NodeToken::BODY_LENGTH:
                header.bodyLength = std::stoi(value);
            break;


            default: // Command Type
                if(header.command.operation.empty()) {
                    header.command.operation = name;
                    header.command.argument = value;
                }else {
                    throw ParserException("Invalid Header");
                }
            break;
        }
    }
    return header;
}
