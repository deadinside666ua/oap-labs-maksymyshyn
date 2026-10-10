// ЛРNN. Назва лабораторної роботи. Варіант N
// Прізвище Ім'я, КІ-21, РРРР-ММ-ДД
//
// Постановка задачі (коротко):
//   Вхід:  ...
//   Вихід: ...
//   Обмеження / особливі випадки: ...
#include <iostream>

// Константи програми (kPascalCase, constexpr замість #define)
constexpr int kAnswer = 42;

int main() {
    // Змінні оголошуємо там, де вони потрібні, і завжди ініціалізуємо
    int value = 0;

    std::cout << "Enter a number: ";
    std::cin >> value;

    std::cout << "You entered " << value << ", the answer is " << kAnswer << '\n';
    return 0;
}
