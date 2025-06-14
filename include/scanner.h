#ifndef SCANNER_H
#define SCANNER_H

#include <string>
#include <vector>

/**
 * @file scanner.h
 * @brief Declares functions for scanning files and signature analysis.
 */

/**
 * @brief Scans the specified file for malicious signatures.
 * @param filepath Path to the file to scan.
 */
void scan_file(const std::string &filepath);

/**
 * @brief Checks if a line contains any malicious signature.
 * @param line The line of text to analyze.
 * @return true if a signature is found; otherwise, false.
 */
bool is_malicious(const std::string &line);

/**
 * @brief Checks if a file is empty.
 * @param filepath Path to the file.
 * @return true if empty, false otherwise.
 */
bool is_file_empty(const std::string &filepath);

/**
 * @brief Prints the current list of signatures.
 */
void print_signatures();

/**
 * @brief Reads all lines from a file.
 * @param filepath Path to the file.
 * @return Vector of lines.
 */
std::vector<std::string> read_lines(const std::string &filepath);

/**
 * @brief Converts a string to lowercase.
 * @param str Input string.
 * @return Lowercase version.
 */
std::string to_lower(const std::string &str);

/**
 * @brief Case-insensitive signature match.
 * @param line The line of text to analyze.
 * @return true if a signature is found; otherwise, false.
 */
bool is_malicious_insensitive(const std::string &line);

/**
 * @brief Counts how many signatures match a line.
 * @param line Line to analyze.
 * @return Number of matches.
 */
int count_matches(const std::string &line);

#endif // SCANNER_H
