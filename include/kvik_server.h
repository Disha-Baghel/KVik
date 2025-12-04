#pragma once
#include "kvik_core.h"
#include <string>

class kvikServer {
public:
    kvikServer(int port);
    void start();

private:
    int port_;
    kvikCore core_;

    void handle_client(int client_socket);
    std::string process_command(const std::string& command);
};
