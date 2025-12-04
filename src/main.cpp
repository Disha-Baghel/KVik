#include <iostream>
// #include "kvik_core.h"
#include "kvik_server.h"

int main() {
    std::cout << kv::get_version() << std::endl;

    // kvikCore store;

    // store.set("user", "disha");
    
    // std::cout<<store.get("user")<<std::endl;
    // std::cout<<"Size: "<<store.size();
    kvikServer server(6380);   // Redis-like port
    server.start();
    return 0;
}
