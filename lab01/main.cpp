// ЛР01. Налаштування робочого місця та перевірка компілятора
// Максимишин Максим, 11КІ, 2026-10-10
#include <iostream>

int main() {
    std::cout << "Hello, C++17!\n";

#if defined(_MSC_VER)
    std::cout << "MSVC " << _MSC_VER << ", standard " << _MSVC_LANG << '\n';
#elif defined(__clang__)
    std::cout << "clang " << __clang_major__ << ", standard " << __cplusplus << '\n';
#elif defined(__GNUC__)
    std::cout << "g++ " << __GNUC__ << '.' << __GNUC_MINOR__ << ", standard " << __cplusplus
              << '\n';
#endif

    return 0;
}
