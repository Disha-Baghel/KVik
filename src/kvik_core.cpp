#include "kvik_core.h"
#include<iostream>

namespace kv {
    std::string get_version() {
        return "kvik v0.1";
    }
}

kvikCore::kvikCore() {
    // You can initialize data structures here if needed
}

bool kvikCore::set(const std::string& key, const std::string& value) {

    store_[key] = value;
    return true;
}

std::string kvikCore::get(const std::string& key) const {
    auto it = store_.find(key);
    if (it != store_.end())
        return it->second;
    return "Not found";
}

bool kvikCore::del(const std::string& key) {
    if (store_.find(key) == store_.end()) {
        std::cout<<"Key not found";
        return false;
    }

    store_.erase(key);
    return true;
}

size_t kvikCore::size() const {
    return store_.size();
}
