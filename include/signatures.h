#ifndef SIGNATURES_H
#define SIGNATURES_H

#include <vector>
#include <string>

/**
 * @file signatures.h
 * @brief Объявляет функции для работы с базой сигнатур.
 */

/**
 * @brief Загружает (возвращает) текущий список сигнатур.
 * @return std::vector<std::string> Список сигнатур.
 */
std::vector<std::string> load_signatures();

/**
 * @brief Добавляет новую сигнатуру в список.
 * @param signature Строка-сигнатура.
 */
void add_signature(const std::string &signature);

#endif // SIGNATURES_H

/**
 * @brief Removes a signature from the list.
 * @param signature The signature to remove.
 * @return true if removed, false if not found.
 */
bool remove_signature(const std::string &signature);
