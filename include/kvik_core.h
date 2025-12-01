#pragma once
#include <string>
#include <unordered_map>
#include <optional>

namespace kv {
    std::string get_version();
}

class kvikCore {
public:
    kvikCore();
    bool set(const std::string& key, const std::string& value);
    std::string get(const std::string& key) const;
    bool del(const std::string& key);
    size_t size() const;

private:
    std::unordered_map<std::string, std::string> store_;
};
