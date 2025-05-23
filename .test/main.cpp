#include <library.h>

#include <thread>
#include <parser/parser.h>
#include <sstream>
#include <socket/MDTPClient.h>

#include <socket/MDTPServer.h>



void runServer() {
    MDTPServer serverSocket = MDTPServer(8080);
    std::cout << "Server Listening on Port 8080 ..." << std::endl;

    MDTPConnection client = serverSocket.accept();
    std::cout << "Client Connected" << std::endl;




    MDTPObject request = client.read();
    if(request.header.command.operation == "GET") {
        std::cout << "GET request FROM client" << std::endl;
        client.write({ .command = STATUS_OK, .body = "# Hello World\r\nA markdown protocol" });
    }
}



void runClient() {
    MDTPClient client("127.0.0.1", 8080);
    MDTPObject data = client.fetch("/test");

    std::cout << data.body << std::endl;
}





int main() {
    // MDTP::init();
    //
    //
    //
    // // Server Thread
    // std::thread serverThread(runServer);
    // std::this_thread::sleep_for(std::chrono::seconds(1)); // Server Startup delay
    //
    // // Client Thread
    // std::thread clientThread(runClient);
    //
    //
    // clientThread.join();
    // serverThread.join();
    // MDTP::clean();


    MDTPServer server = MDTPServer();
    MDTPConnection connection = server.accept();
    connection.write({ .command = STATUS_OK, .body = "# Hello World" });
}
