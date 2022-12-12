#include "../include/client.h"

int connectClient() {
    //WSAStartup
    WSAData wsaData{};
    WORD DLLVersion = MAKEWORD(2, 1);
    if (WSAStartup(DLLVersion, &wsaData) != 0) {
        std::cout << "Error!" << std::endl;
        exit(1);
    }
    SOCKADDR_IN addr;
    int sizeofaddr = sizeof(addr);
    addr.sin_addr.s_addr = inet_addr("127.0.0.1");
    addr.sin_port = htons(1111);
    addr.sin_family = AF_INET;
    SOCKET Connection = socket(AF_INET, SOCK_STREAM, NULL);
    if(connect(Connection, (SOCKADDR*)&addr, sizeof(addr)) != 0) {
        std::cout << "Error: failed to connect to server!\n";
        return 1;
    }
    std::cout << "OK!\n";
    char Function[256];
    std::cin >> Function;
    send(Connection, Function, sizeof(Function), 0);
    system("pause");
    return 0;
}

