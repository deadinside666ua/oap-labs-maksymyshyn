# oap-labs — лабораторні роботи з дисципліни «Програмування (ОАП)»

> Замініть цей блок своїми даними після клонування. Джерело шаблону: <https://github.com/YaroslavLevus/oap-labs-template>

| | |
|---|---|
| **Студент** | Прізвище Ім'я |
| **Група** | КІ-21 |
| **Варіант** | 0 |
| **Семестр** | 3 (2026–2027) |
| **Викладач** | Левус Я. |

## Структура репозиторію

```
oap-labs/
├── README.md            ← цей файл: хто ви і який у вас варіант
├── .gitignore           ← що Git НЕ зберігає (результати збірки, службові папки IDE)
├── .clang-format        ← єдиний стиль коду для всієї групи (автоформатування)
├── .editorconfig        ← відступи 4 пробіли, UTF-8, LF — для будь-якого редактора
├── .vscode/             ← налаштування VS Code: збірка (Ctrl+Shift+B) і налагодження (F5)
├── lab00-template/      ← заготовка: скопіюйте як labNN/ для кожної нової роботи
│   ├── main.cpp
│   └── report.md
├── lab01/               ← ЛР1: main.cpp + report.md
├── lab02/
└── ...
```

У кожній папці `labNN/` лежать:

- `main.cpp` — програма (для робіт з кількох завдань — `task1.cpp`, `task2.cpp` …);
- `report.md` — звіт за шаблоном з `lab00-template/report.md`;
- за потреби — файли Visual Studio `labNN.sln`, `labNN.vcxproj`, `labNN.vcxproj.filters`
  (їх зберігаємо в Git; папки `.vs/`, `x64/`, `Debug/`, `Release/` — ні, про це дбає `.gitignore`).

## Як почати нову лабораторну

```bash
git pull                              # отримати останні зміни (якщо працюєте з кількох комп'ютерів)
cp -r lab00-template lab05            # Windows PowerShell: Copy-Item -Recurse lab00-template lab05
```

Далі редагуєте `lab05/main.cpp` і `lab05/report.md`, збираєте, тестуєте і після кожного
працездатного кроку робите коміт:

```bash
git add .
git commit -m "ЛР5: табулювання функції, варіант 7"
git push
```

**Здана робота = коміт на GitHub.** Робота лише на вашому комп'ютері не вважається зданою.

## Збірка

**Visual Studio 2022.** Створіть проєкт «Console App» у папці `labNN/` (галочка
«Place solution and project in the same directory»), перейменуйте `labNN.cpp` на `main.cpp`
або замініть вміст. Стандарт мови: *Project → Properties → C/C++ → Language → C++ Language
Standard → ISO C++17*. Рівень попереджень: *C/C++ → General → Warning Level → Level4 (/W4)*.

**VS Code + g++.** Відкрийте папку `oap-labs` (File → Open Folder), відкрийте потрібний
`main.cpp` і натисніть **Ctrl+Shift+B** — задача з `.vscode/tasks.json` збере файл командою

```bash
g++ -std=c++17 -Wall -Wextra -pedantic -g main.cpp -o main
```

**F5** запускає програму під налагоджувачем (gdb у Windows/Linux, lldb у macOS).

**Термінал.** У папці роботи:

```bash
g++ -std=c++17 -Wall -Wextra -pedantic -O2 main.cpp -o main && ./main      # Windows: .\main.exe
```

## Кілька завдань в одній роботі: task1.cpp, task2.cpp, task3.cpp

Кожне завдання — окремий файл зі своєю функцією `main()`. Разом вони не збираються (два `main`
в одній програмі — помилка лінкера), тому збираємо **по одному файлу**.

**VS Code + g++.** Нічого налаштовувати не треба: Ctrl+Shift+B збирає той файл, який зараз
відкритий у редакторі (`${file}` у `tasks.json`), і кладе поруч `task2` / `task2.exe`. Відкрили
`task3.cpp` — зібрався `task3`. У терміналі те саме:

```bash
g++ -std=c++17 -Wall -Wextra -pedantic task2.cpp -o task2 && ./task2
```

**Visual Studio 2022.** Один проєкт `labNN`, у ньому всі файли завдань. Активним для збірки
має бути лише один з них, решту вимикаємо: у *Solution Explorer* правою кнопкою на файл →
**Properties** → угорі *Configuration: All Configurations* → *General* →
**Excluded From Build: Yes** → OK. Вимкнений файл позначається червоним значком, але
лишається в проєкті й у Git. Щоб перейти до наступного завдання, увімкніть його
(*Excluded From Build: No*) і вимкніть попередній. Якщо бачите
`error LNK2005: main already defined` — увімкнено два файли одночасно.

Альтернатива для Visual Studio, якщо перемикати незручно: у рішенні `labNN.sln` створити
окремий проєкт на кожне завдання (*File → Add → New Project*, Console App `task2` у папці
`labNN/`) і обирати активний через *Set as Startup Project*. Тоді нічого вимикати не треба,
але файлів проєкту більше.

## Код, що збирається і у Visual Studio, і в g++

Один і той самий `main.cpp` має збиратися в обох середовищах. Не використовуйте того, що є лише
у Visual Studio або лише в g++:

| Не пишіть | Що станеться | Замість цього |
|:--|:--|:--|
| `scanf_s`, `printf_s` | g++: `'scanf_s' was not declared in this scope` | `std::cin`, `std::cout` |
| `#include "pch.h"`, `#include "stdafx.h"` | g++: `pch.h: No such file or directory` | приберіть рядок |
| `#include <conio.h>`, `_getch()` | на macOS і Linux не збирається | приберіть або `std::cin.get()` |
| `#pragma warning(disable : 4996)` | g++ пропускає директиву і попереджає про це | приберіть рядок |
| `int a[n];`, де `n` вводиться з клавіатури | g++ збирає, Visual Studio — ні (`C2131`) | `std::vector<int> a(n);` з `<vector>` |

Задачі збірки у VS Code запускають g++ з прапорцем `-pedantic`, тому на `int a[n];` ви побачите
попередження `ISO C++ forbids variable length array`. Не залишайте його без уваги: у Visual Studio
цей код не збереться.

## Стиль коду

Правила — у лекції 3; файл `.clang-format` втілює їх автоматично:
Visual Studio — **Ctrl+K, Ctrl+D**, VS Code — **Shift+Alt+F**. Коротко:

- імена змінних і функцій `camelCase`, типів `PascalCase`, констант `kPascalCase`;
- відступ 4 пробіли, фігурні дужки завжди, відкриваюча — на тому ж рядку;
- одне оголошення на рядок, кожна змінна ініціалізована;
- явний `std::`, без `using namespace std;`;
- рядок до 100 символів; коментарі пояснюють «чому», а не «що».

## Шаблон файлу

```cpp
// ЛР05. Табулювання функції однієї змінної. Варіант 7
// Прізвище Ім'я, КІ-21, 2026-10-14
#include <iostream>

int main() {
    std::cout << "Hello, C++17!\n";
    return 0;
}
```
