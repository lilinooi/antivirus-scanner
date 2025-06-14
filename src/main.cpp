#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include "scanner.h"
#include "signatures.h"

void display_help() {
    std::cout << "\nCommands:\n";
    std::cout << "  1 - Scan file for malware\n";
    std::cout << "  2 - Add a new signature\n";
    std::cout << "  3 - Remove a signature\n";
    std::cout << "  4 - List all current signatures\n";
    std::cout << "  5 - Count signature matches in a file\n";
    std::cout << "  6 - Exit the program\n";
    std::cout << "  7 - Scan file (case-insensitive)\n";
    std::cout << "  8 - Show number of loaded signatures\n";
}

void count_signature_matches_in_file() {
    std::string filepath;
    std::cout << "Enter file path: ";
    std::getline(std::cin, filepath);
    std::vector<std::string> lines = read_lines(filepath);
    int total_matches = 0;
    for (const std::string &line : lines) {
        total_matches += count_matches(line);
    }
    std::cout << "Total signature matches: " << total_matches << "\n";
}

void scan_case_insensitive() {
    std::string filepath;
    std::cout << "Enter file path: ";
    std::getline(std::cin, filepath);
    std::ifstream file(filepath);
    if (!file.is_open()) {
        std::cout << "Unable to open file.\n";
        return;
    }
    std::string line;
    int line_num = 1;
    bool found = false;
    while (std::getline(file, line)) {
        if (is_malicious_insensitive(line)) {
            std::cout << "[!] Match (case-insensitive) on line " << line_num << ": " << line << "\n";
            found = true;
        }
        ++line_num;
    }
    if (!found) {
        std::cout << "No matches found (case-insensitive).\n";
    }
}

int main() {
    std::cout << "Welcome to the Lightweight Antivirus Scanner!\n";
    display_help();

    while (true) {
        std::cout << "\n===== Main Menu =====\n";
        std::cout << "Choose an option (type 0 for help): ";

        int choice;
        std::cin >> choice;
        std::cin.ignore();

        if (choice == 0) {
            display_help();
        } else if (choice == 1) {
            std::string filepath;
            std::cout << "Enter file path: ";
            std::getline(std::cin, filepath);
            if (is_file_empty(filepath)) {
                std::cout << "The file is empty.\n";
            } else {
                scan_file(filepath);
            }
        } else if (choice == 2) {
            std::string sig;
            std::cout << "Enter new signature: ";
            std::getline(std::cin, sig);
            add_signature(sig);
        } else if (choice == 3) {
            std::string sig;
            std::cout << "Enter signature to remove: ";
            std::getline(std::cin, sig);
            remove_signature(sig);
        } else if (choice == 4) {
            print_signatures();
        } else if (choice == 5) {
            count_signature_matches_in_file();
        } else if (choice == 6) {
            std::cout << "Exiting...\n";
            break;
        } else if (choice == 7) {
            scan_case_insensitive();
        } else if (choice == 8) {
            std::cout << "Total signatures: " << load_signatures().size() << "\n";
        } else {
            std::cout << "Invalid option. Type 0 for help.\n";
        }
    }
    return 0;
}
