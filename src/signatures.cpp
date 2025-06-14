#include "signatures.h"
#include <iostream>
#include <algorithm>

static std::vector<std::string> g_signatures = {
    "system", "eval", "fork", "exec", "CreateProcess"
};

std::vector<std::string> load_signatures() {
    return g_signatures;
}

void add_signature(const std::string &signature) {
    g_signatures.push_back(signature);
    std::cout << "Signature added: \"" << signature << "\"." << std::endl;
}

bool remove_signature(const std::string &signature) {
    auto it = std::find(g_signatures.begin(), g_signatures.end(), signature);
    if (it != g_signatures.end()) {
        g_signatures.erase(it);
        std::cout << "Signature removed: \"" << signature << "\"." << std::endl;
        return true;
    } else {
        std::cout << "Signature not found: \"" << signature << "\"." << std::endl;
        return false;
    }
}
