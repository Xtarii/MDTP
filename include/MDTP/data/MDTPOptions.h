#ifndef MDTPOPTIONS_H
#define MDTPOPTIONS_H
#include <library.h>

/**
 * MDTP Data Options
 *
 * Used to change response and
 * request data headers.
 */
struct MDTPOptions {
    /**
     * MDTP Version
     */
    const char* version = MDTP_VERSION;

    /**
     * MDTP Command
     */
    const char* command;

    /**
     * MDTP Body
     */
    const char* body;
};

#endif //MDTPOPTIONS_H
