#include <json.hpp>
#include <iostream>

using nlohmann::json;

int main() {
    json j;
    j["pi"] = 3.14;
    std::cout<<j["pi"];
    return 1;
}
