#include "scanner.h"
#include "signatures.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <algorithm>

bool is_malicious(const std::string &line) {
    for (const auto &sig : load_signatures()) {
        if (line.find(sig) != std::string::npos) {
            return true;
        }
    }
    return false;
}

bool is_malicious_insensitive(const std::string &line) {
    std::string lower_line = to_lower(line);
    for (const auto &sig : load_signatures()) {
        if (lower_line.find(to_lower(sig)) != std::string::npos) {
            return true;
        }
    }
    return false;
}

std::string to_lower(const std::string &str) {
    std::string result = str;
    std::transform(result.begin(), result.end(), result.begin(), ::tolower);
    return result;
}

void scan_file(const std::string &filepath) {
    std::ifstream file(filepath);
    if (!file.is_open()) {
        std::cerr << "Failed to open file: " << filepath << std::endl;
        return;
    }
    std::string line;
    int line_number = 1;
    while (std::getline(file, line)) {
        if (is_malicious(line)) {
            std::cout << "[!] Malicious code detected on line " << line_number << ": " << line << std::endl;
        }
        ++line_number;
    }
    file.close();
}

int count_matches(const std::string &line) {
    int count = 0;
    for (const auto &sig : load_signatures()) {
        if (line.find(sig) != std::string::npos) {
            ++count;
        }
    }
    return count;
}

bool is_file_empty(const std::string &filepath) {
    std::ifstream file(filepath, std::ios::ate);
    return file.tellg() == 0;
}

std::vector<std::string> read_lines(const std::string &filepath) {
    std::ifstream file(filepath);
    std::vector<std::string> lines;
    std::string line;
    while (std::getline(file, line)) {
        lines.push_back(line);
    }
    return lines;
}

void print_signatures() {
    auto sigs = load_signatures();
    std::cout << "Current signatures:\n";
    for (const auto &sig : sigs) {
        std::cout << " - " << sig << "\n";
    }
}
