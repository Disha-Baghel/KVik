#include "kvik_server.h"
#include <iostream>
#include <sstream>
#include <vector>
#include <sys/socket.h>
#include <netinet/in.h>
#include <unistd.h>

kvikServer::kvikServer(int port) : port_(port) {}

void kvikServer::start() {
    int server_fd = socket(AF_INET, SOCK_STREAM, 0);
    if (server_fd < 0) {
        std::cerr << "Failed to create socket\n";
        return;
    }

    sockaddr_in address {};
    address.sin_family = AF_INET;
    address.sin_addr.s_addr = INADDR_ANY;
    address.sin_port = htons(port_);

    if (bind(server_fd, (struct sockaddr*)&address, sizeof(address)) < 0) {
        std::cerr << "Bind failed" << std::endl;
        close(server_fd);
        return ;
    }

    if (listen(server_fd, 5) < 0) {
        std::cerr << "Listen failed" << std::endl;
        close(server_fd);
        return ;
    }

    std::cout<< "KVik Server running on port " << port_ << "..." << std::endl;

    while(true) {
        int client_socket = accept(server_fd, nullptr, nullptr);
        if (client_socket >= 0) {
            handle_client(client_socket);
        }
    }
    close(server_fd);
}

void kvikServer::handle_client(int client_socket) {
    char buffer[1024] = {0};
    read(client_socket, buffer, sizeof(buffer));

    std::string command(buffer);
    std::cout << "Client sent: " << command << std::endl;

    std::string response = "Echo: " + command;

    send(client_socket, response.c_str(), response.size(), 0);
    close(client_socket);
}

std::string(kvikServer::process_command(const std::string& command)) {
    // set/get/del implementation

    return "implementation";
}

