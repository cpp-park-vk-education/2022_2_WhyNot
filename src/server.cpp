#include "../include/server.h"

void serverStart() {
    //WSAStartup
    WSAData wsaData{};
    char buf[256];
    WORD DLLVersion = MAKEWORD(2, 1);
    if(WSAStartup(DLLVersion, &wsaData) != 0) {
        std::cout << "Error!" << std::endl;
        exit(1);
    }
    SOCKADDR_IN addr;
    int sizeofaddr = sizeof(addr);
    addr.sin_addr.s_addr = inet_addr("127.0.0.1");
    addr.sin_port = htons(1111);
    addr.sin_family = AF_INET;
    SOCKET sListen = socket(AF_INET, SOCK_STREAM, 0);
    bind(sListen, (SOCKADDR*)&addr, sizeof(addr));
    listen(sListen, SOMAXCONN);
    SOCKET newConnection;
    newConnection = accept(sListen, (SOCKADDR*)&addr, &sizeofaddr);
    if (newConnection == 0) {
        std::cout << "Error #2\n";
    } else {
        std::cout << "client connected!\n";
        recv(newConnection, buf, sizeof(buf), 0);
        send(newConnection, buf, sizeof(buf), 0);
    }
    system("pause");
}
