# Changelog

All notable changes to this project will be documented in this file.

## EN
## [0.1.0] - 2025-07-17
### Added
- Initial interpreter implementation with basic syntax support
- Support for `START` and `END` program markers
- `SHOW('text')` command for outputting strings
- `SHOW(variable)` command for outputting variable values
- `CREATE VAR <name>` command for declaring variables
- `CALC(<var>=<expression>)` command for assigning results to variables
- `CALC(<expression>)` command for direct expression evaluation and output
- Basic error handling with descriptive messages
- Support for arithmetic operations: `+`, `-`, `*`, `/`
- Division by zero error detection
- Trim function for handling extra spaces in commands

### Changed
- Updated `CALC(...)` syntax to support both assignment and direct evaluation
- Improved error messages for better clarity and debugging
- Refined expression parser to support multiple operators
- Improved variable handling and validation

### Fixed
- Bug with incorrect parsing of variable names in `CALC(...)` due to whitespace
- Incorrect error messages for undefined variables
- Handling of command-line input and file loading
- Parsing logic for `CALC(...)` expressions
- Support for multiple operations in arithmetic evaluation

### Removed
- Old syntax `CALC(...) = VAR` in favor of `CALC(VAR=...)`

## [0.1.1] - 2025-07-18
### Added
- `IF/ELSE` constructions
- Comparison operators: `==`, `!=`, `<=`, `=>`, `<`, `>`

### Changed
- Variables can be defined not in `CALC()` function

### Fixed
- Improve fixes

### Removed
- Old syntax `CREATE VAR TEST` in favor of `VAR TEST = 10`

## [0.1.1] - 2025-07-21
### Added
- **Splitting of a project. In basic folder, old terminal interpreter**
- **GUI IDE, to write, load and run programs instantly**

## RU
## [0.1.0] - 2025-07-17
### Добавлено
- Интерпретатор цифровых перфокарт
- `START` и `END` как объявление и закрытие программ
- `SHOW('text')` команда вывода строки
- `SHOW(variable)` команда выввода переменных
- `CREATE VAR <name>` команда создания/назначения переменных
- `CALC(<var>=<expression>)` команда передачи числовых выражений переменной
- `CALC(<expression>)` команда числовых выражений
- Базовые ошибки интерпретатора и числовых выражений
- Поддержка арифметических операторов: `+`, `-`, `*`, `/`
- Отлов деления на ноль
- Очистка лишних пробелов и символов табулции для строки

### Изменено
- Обновлен `CALC(...)` синтаксис для поддержки как присваивания, так и прямого вычисления
- Упрощение сообщений об ошибках
- Усовершенствованный анализатор выражений для поддержки нескольких операторов
- Улучшенная обработка и проверка переменных

### Исправлено
- Ошибка с некорректным разбором имен переменных в `CALC(...)` из-за пробелов
- Неверные сообщения об ошибках для неопределенных переменных
- Обработка ввода командной строки и загрузка файлов
- Логика анализа выражений `CALC(...)`
- Поддержка множественных операций при арифметической оценке

### Removed
- Старый синтаксис `CALC(...) = VAR` взамену `CALC(VAR=...)`

## [0.1.1] - 2025-07-18
### Добавлено
- Условные конструкции `IF/ELSE`
- Операторы сравнения: `==`, `!=`, `<=`, `=>`, `<`, `>`

### Изменено
- Переменные могут быть объявлены независимо от функции `CALC()`

### Исправлено
- Незначительные ошибки

### Удалено
- Старый синтаксис `CREATE VAR TEST` был изменён на `VAR TEST = 10`

## [0.1.1] - 2025-07-21
### Добавлено
- **Разделение проекта. В папке basic, старый консольный интерпретатор**
- **Добавлено IDE с графическим интерфейсом**