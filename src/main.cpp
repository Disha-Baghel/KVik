#include <iostream>
#include "kvik_core.h"

int main() {
    std::cout << kv::get_version() << std::endl;

    kvikCore store;

    store.set("user", "disha");
    
    std::cout<<store.get("user")<<std::endl;
    std::cout<<"Size: "<<store.size();
    return 0;
}
