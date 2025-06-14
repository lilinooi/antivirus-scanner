#ifndef SIGNATURES_H
#define SIGNATURES_H

#include <vector>
#include <string>

/**
 * @file signatures.h
 * @brief Declares functions for working with the malware signature database.
 */

/**
 * @brief Loads and returns the current list of malware signatures.
 *
 * @return std::vector<std::string> A list of known malware signatures.
 */
std::vector<std::string> load_signatures();

/**
 * @brief Adds a new signature to the list.
 *
 * @param signature The signature string to be added.
 */
void add_signature(const std::string &signature);

/**
 * @brief Removes a signature from the list.
 *
 * @param signature The signature string to be removed.
 * @return true if the signature was found and removed, false otherwise.
 */
bool remove_signature(const std::string &signature);

#endif // SIGNATURES_H

