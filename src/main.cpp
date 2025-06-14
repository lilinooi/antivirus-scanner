#include <iostream>
#include <string>
#include "scanner.h"
#include "signatures.h"

/**
 * @file main.cpp
 * @brief Entry point for the antivirus scanner.
 */

int main() {
    std::cout << " ANTIVIRUS SCANNER \n";

    int choice;
    std::string filepath;
    std::string input;

    while (true) {
        std::cout << "\nMenu:\n"
                  << "1. Scan a file\n"
                  << "2. Show signatures\n"
                  << "3. Add a signature\n"
                  << "4. Exit\n"
                  << "5. Remove a signature\n"
                  << "Choice: ";

        if (!(std::cin >> choice)) {
            std::cin.clear();
            std::string dummy;
            std::getline(std::cin, dummy);
            std::cout << "Invalid input. Try again.\n";
            continue;
        }

        switch (choice) {
            case 1:
                std::cout << "Enter path to file: ";
                std::getline(std::cin >> std::ws, filepath);
                scan_file(filepath);
                break;
            case 2:
                std::cout << "Current signatures:\n";
                for (const auto &sig : load_signatures()) {
                    std::cout << " - " << sig << "\n";
                }
                break;
            case 3:
                std::cout << "Enter new signature to add: ";
                std::getline(std::cin >> std::ws, input);
                if (!input.empty()) {
                    add_signature(input);
                } else {
                    std::cout << "Signature cannot be empty.\n";
                }
                break;
            case 4:
                std::cout << "Exiting...\n";
                return 0;
            case 5:
                std::cout << "Enter signature to remove: ";
                std::getline(std::cin >> std::ws, input);
                remove_signature(input);
                break;
            default:
                std::cout << "Invalid option. Try again.\n";
        }
    }

    return 0;
}
