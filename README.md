# MDTP ( Markdown Transfer Protocol )

MDTP is a simple network protocol inspired by **HTTP**.

MDTP includes a Server Socket and a Client Socket for
communicating back and forth with a server and clients.

It builds on **TCP** and is just a fun little project
I made to learn more about the concept.

MDTP communication listens on port **50** by default.





### Usage

If you for some reason wants to use MDTP to send data
and receive data you are more than welcome to.

```cmake
# Installation
FetchContent_Declare(
    MDTP
    GIT_REPOSITORY https://github.com/Xtarii/MDTP.git
    GIT_TAG <tag>
)
```



Creating a Server
```cpp
// Creating a Server ( PORT is set by default and therefore not required )
MDTPServer serverSocket = MDTPServer(50);


// Accepting Clients
MDTPConnection client = serverSocket.accept();


// Reads Data from Client
MDTPObject request = client.read();


// Writes Data back to client
client.write({ .command = STATUS_OK, .body = "# Hello World\r\nA markdown protocol" });
```

Creating a Client
```cpp
MDTPClient client("127.0.0.1", 50); // The Port is not needed as the default is 50
MDTPObject data = client.fetch("/test");
```
