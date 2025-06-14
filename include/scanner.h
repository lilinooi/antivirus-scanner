#ifndef SCANNER_H
#define SCANNER_H

#include <string>

/**
 * @file scanner.h
 * @brief Объявления функций сканирования для антивирусного сканера.
 */

/**
 * @brief Сканирует указанный файл на наличие вредоносных сигнатур.
 * @param filepath Путь к файлу.
 */
void scan_file(const std::string &filepath);

/**
 * @brief Проверяет строку на наличие сигнатур.
 * @param line Строка текста.
 * @return true, если строка содержит сигнатуру.
 */
bool is_malicious(const std::string &line);

#endif // SCANNER_H
