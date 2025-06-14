#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include "scanner.h"
#include "signatures.h"
#include <algorithm>

TEST_CASE("Проверка начальных сигнатур") {
    auto sigs = load_signatures();
    CHECK(std::find(sigs.begin(), sigs.end(), "system") != sigs.end());
    CHECK(std::find(sigs.begin(), sigs.end(), "eval") != sigs.end());
}

TEST_CASE("is_malicious находит сигнатуры") {
    CHECK(is_malicious("This line uses system command") == true);
    CHECK(is_malicious("This line is clean") == false);
}

TEST_CASE("add_signature работает") {
    std::string testSig = "virus_test";
    add_signature(testSig);
    CHECK(is_malicious("Some virus_test code") == true);
}
