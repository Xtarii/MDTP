#ifndef MDTPHEADER_H
#define MDTPHEADER_H

#include <string>
#include <vector>
#include <cstdint>



class ParserException;



/**
 * Node Tokens
 */
enum class NodeToken {
    /**
     * Version Token
     */
    VERSION,
    /**
     * Data Body length Token
     */
    BODY_LENGTH,

    /**
     * Command Token
     */
    COMMAND,
};

/**
 * Converts Raw String to Node Token
 *
 * @param raw Raw String
 * @return Token
 */
NodeToken convertToToken(std::string& raw);



/**
 * MDTP Node
 */
struct MDTPNode {
    /**
     * Node Token Type
     */
    NodeToken type;

    /**
     * Node Name
     */
    std::string name;
    /**
     * Node Value
     */
    std::string value;



    /**
     * Converts the Node Object to a string
     *
     * @return The Node Object as a String
     */
    [[nodiscard]] std::string toString() const {
        return std::string("{ " + name + " " + value + " }");
    }
};

/**
 * MDTP Command Object
 */
struct MDTPCommand {
    /**
     * Command Operation
     */
    std::string operation;
    /**
     * Command Argument
     */
    std::string argument;



    /**
     * Converts the Command Object to a string
     *
     * @return The Command Object as a String
     */
    [[nodiscard]] std::string toString() const {
        return std::string("{ " + operation + ", " + argument + " }");
    }
};

/**
 * MDTP Header Object
 */
struct MDTPHeader {
    /**
     * MDTP Version
     */
    std::string version;
    /**
     * Data body length
     */
    uint16_t bodyLength;
    /**
     * Command
     *
     * The command indicates what the
     * request stands for. That could
     * be the response status or the
     * request operation.
     */
    MDTPCommand command;



    /**
     * Converts the Header Object to a string
     *
     * @return The Header Object as a String
     */
    [[nodiscard]] std::string toString() const {
        return std::string("{ " + version + ", body-length " + std::to_string(bodyLength) + ", command " + command.toString() + " }");
    }
};





/**
 * Parse Node
 *
 * @param rawNode Raw Node String
 * @return Parsed Node
 */
MDTPNode parseNode(const std::string& rawNode);

/**
 * Extracts all nodes from raw header string
 *
 * @param raw Raw Header String
 * @return Header Nodes
 */
std::vector<MDTPNode> getNodesFromHeader(const std::string& raw);

/**
 * Parses Header String
 *
 * @param raw Raw Header String
 * @return Parsed Header
 * @throws ParserException If there was an error parsing the header, can be caused
 * by the header containing **unkown** data.
 */
MDTPHeader parseHeader(const std::string& raw);

#endif //MDTPHEADER_H
