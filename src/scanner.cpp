#include "scanner.h"
#include "signatures.h"
#include <fstream>
#include <iostream>

void scan_file(const std::string &filepath) {
    std::ifstream file(filepath);
    if (!file.is_open()) {
        std::cerr << "Failed to open file: " << filepath << std::endl;
        return;
    }

    std::string line;
    int lineNumber = 0;
    int maliciousCount = 0;

    while (std::getline(file, line)) {
        lineNumber++;
        if (is_malicious(line)) {
            maliciousCount++;
            std::cout << "Line " << lineNumber << ": suspicious content." << std::endl;

            for (const std::string &sig : load_signatures()) {
                if (line.find(sig) != std::string::npos) {
                    std::cout << "  -> Found signature: \"" << sig << "\"" << std::endl;
                }
            }
        }
    }

    if (maliciousCount == 0) {
        std::cout << "File is safe. Nothing found." << std::endl;
    } else {
        std::cout << "Total suspicious lines: " << maliciousCount << std::endl;
    }

    file.close();
}

bool is_malicious(const std::string &line) {
    for (const std::string &sig : load_signatures()) {
        if (line.find(sig) != std::string::npos) {
            return true;
        }
    }
    return false;
}
