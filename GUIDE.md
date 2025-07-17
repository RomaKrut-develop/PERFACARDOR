# PERFACARDOR

## RU

## Интерпретатор .txt программ, которые названы (мной) цифровыми перфокартами

### Введение

**Что это такое и зачем?**

Вдохнавляясь языками `JavaScript`, `Python`, `Mojo`, которые были так приблежны к человеческому синтаксису, мне тоже захотелось создать что-то свое. Может быть не такое применимое, полезное, но свое, и что будет работать. И имя своему детищу я дал PERFACARDOR. (Это не апечатка, я просто взял букву 'a' с 'digit**a**l punched card. Но транскрипцию решил оставить на русском языке.')
Ничего общего с настоящими перфокартами, кроме того, что их нужно загружать в, так скажем 'лоток' или 'слот' выполнения, у них (цифровыми перфокартами) нет. (А так же с цифровыми перфокартами лоялности тоже.).
Поэтому интерпретатор выступает в роли загрузчика и исполнителя одновременно. Подробнее будет сказано чуть позже.

PERFACARDOR — это **язык программирования**, разработанный как **DSL (Domain-Specific Language)** для выполнения простых вычислений и вывода информации. Язык является **императивным, высокоуровневым и динамически типизированным**, и предназначен для изучения основ построения интерпретаторов и создания собственных синтаксических конструкций.

Конечно, программы написанные на PERFACARDOR, не будут супер производительными и полезными как на других языках. Причем, прошу заметить, я не говорил что PERFACARDOR, **оффициально** является языком программирования. Будем называть его так для удобства. 

Дух разработчика, заставил меня посмотреть на синтаксис `COBOL` и `SQL`, именно поэтому, все пишется через заглавные буквы, а отсутствие знаков окончания команды `;` как в `Python`, сделало синтаксис до ужаса простым.

**Где примененить?**

Можно использовать для изучения принципов построения интерпретаторов и DSL. Ведь интерпретатор PERFACARDOR, доступен всем и каждый может внести улучшения для этого языка.

**Что нужно знать?**

Если вы совсем новенький в программировании и хотите попробывать впервые, мрачный терминал после визуального Scratch, то это будет неплоихм опытом. Бояться не надо, синтаксис очень простой а интерпретатор встроен в программу. (Точнее, программа и есть интерпретатор (КОММЕНТАРИИ В КОДЕ НЕ ПОДДЕРЖИВАЮТСЯ)).

Стоит сразу объяснить основы программы, которая загружает и выполняет виртуальную перфокарту. Это и есть интерпретатор.

### Работа с интерпретатором 

При первом запуске `interpreter.exe`, вам будет непонятно, что делать.

Давайте пройдёмся по **основному меню**:

Вы увидите такое меню с просьбой ввода команды:

---

Input command:
1. Load and run
2. Help
3. Exit

Enter option:

---

Объясню по порядку:

**Load and run**, загружает файлы из папки `tray` и сразу выполняет их.

**Help**, вызывает меню справки.

**Exit**, выход из программы.

Для запуска определённой команды, введите необходимую цифру.

Учтите, что папка `tray` пуста по умолчанию. Когда вы закончите писать ваш код, сохраните .txt файл в эту папку. 

Но, не зная синтаксис, невозможно написать программу.

### Синтаксис

**Все доступные синтаксические теги:**
1. *START* - Начало программы

2. *END* - Конец программы

3. *CREATE VAR* - Объявление переменной

4. *SHOW()* - Отображение информации на экране

5. *CALC()* - Вычислительная функция

Каждый отдельный тег мы разберем по мере убывания.

**Основы:**

Чтобы обозначить рамки для программы **PERFACARDOR**, используются теги `START` и `END`, внутри которых происходит основная логика программы.

Каждая программа на PERFACARDOR должна начинаться с ключевого слова START и заканчиваться END.

```PERFACARDOR
START
    [команды]
END
```

Зная это, напишем **первую программу**:

```PERFACARDOR
START
    SHOW('Hello, PERFACARDOR!')
END
```

**Определение переменных** происходит так:

```PERFACARDOR
START
    SHOW('Shower') <-- Отображение навзания исполняемой программы
    CREATE VAR test <-- 'test' имя переменной 
END
```

Стоит отметить, значение для переменной мы не можем задать сразу.

**Вычислительная функция CALC()**:

Готовый калькулятор. Поддерживает операторы сложения, деления, вычитания, умножения.

В параметры CALC(), можно передавать любые вычислительные выражения;

Например: `CALC(42+42)`.

**Передача переменной в CALC()**:

Можно передавать **переменные прямо в функцию**:

```PERFACARDOR
START
    SHOW('Shower') <-- Отображение навзания исполняемой программы
    CREATE VAR test <-- 'test' имя переменной 
    CALC(test=9*9) <-- Задаем переменной 'test', вычислительное выражение
END
```

Помимо числовых выражений, можно также передавать строки.

**Передача переменной в SHOW()**:

Можно передавать **переменные прямо в функцию**:

```PERFACARDOR
START
    SHOW('Shower') <-- Отображение навзания исполняемой программы
    CREATE VAR test <-- 'test' имя переменной 
    CALC(test=9*9) <-- Задаем переменной 'test', вычислительное выражение
    SHOW(test) <-- Передаем переменную и выводим на экран
END
```

Таким образом, собирается простая, алгоритмическая программа которое вычисляет выражение.

Хотя ее можно реализовать и **без передачи переменной** в **функцию**:

```PERFACARDOR
START
    SHOW('Shower') <-- Отображение навзания исполняемой программы
    CALC(1+1) <-- Автоматически выполняет и выводит операцию
END
```

**Запуск и загрузка:**

Для загрузки программы, поместите готовый txt-файл в папку `tray`.

Для запуска, откройте `interpreter.exe` и выберите пункт `Load and run`.
После этого, введите имя вашей программы, которую хотите запустить, например `test.txt`.

Нажмите ENTER на клавиатуре.

Ваша 'цифровая перфокарта' будет загружена в интерпретатор из `tray`, а результат ввыполнения будет выведен в терминале.

## EN

## Interpreter for .txt programs named (by me) digital punch cards

### Introduction

**What is this and why?**

Inspired by languages like `JavaScript`, `Python`, and `Mojo`, which were so close to human syntax, I also wanted to create something of my own. It might not be as applicable or useful, but it's mine, and it works. I named my creation PERFACARDOR. (This is not a typo - I just took the letter 'a' from 'digit**a**l punched card.' But I kept the transcription in Russian.)  

It has nothing in common with real punch cards, except that they need to be loaded into a so-called "tray" or "execution slot." (They also have nothing to do with digital loyalty punch cards.)  

Thus, the interpreter acts as both a loader and an executor. More details will be provided later.

PERFACARDOR is a **programming language**, developed as a **DSL (Domain-Specific Language)** for performing simple calculations and displaying information. The language is **imperative, high-level, and dynamically typed**, and is intended for learning the basics of interpreter design and creating custom syntactic constructs.

**Where can it be used?**

It can be used to study the principles of interpreter and DSL design. After all, the PERFACARDOR interpreter is available to everyone, and anyone can contribute improvements to this language.

**What do you need to know?**

If you're completely new to programming and want to try something beyond the visual Scratch, facing the grim terminal for the first time, this will be a decent experience.

### Working with the interpreter

When you first launch `interpreter.exe`, you might not know what to do.

Let's go through the **main menu**:

---

Input command:
1. Load and run
2. Help
3. Exit

Enter option:

---

Here's what each option does:

- **Load and run** - loads files from the `tray` folder and immediately executes them
- **Help** - opens the help menu
- **Exit** - quits the program

### Syntax

**All available syntax tags:**

1. `START` - Start of the program
2. `END` - End of the program
3. `CREATE VAR` - Variable declaration
4. `SHOW()` - Display information
5. `CALC()` - Computational function

**Basic program structure:**

```PERFACARDOR
START
    [commands]
END
```

**Variables are defined as follows**:

```PERFACARDOR
START
    SHOW('Shower') <-- Displays the program name
    CREATE VAR test <-- 'test' is the variable name
END
```

Note that we cannot assign a value to the variable during declaration.

**The CALC() function**:

A built-in calculator function that supports addition, division, subtraction, and multiplication.

You can pass any arithmetic expression to CALC():

Example: CALC(42+42)

**Passing Variables to CALC()**:

```PERFACARDOR
START
    SHOW('Shower') <-- Displays the program name
    CREATE VAR test <-- 'test' is the variable name
    CALC(test=9*9) <-- Assigns the arithmetic expression to variable 'test'
END
```

Besides numerical expressions, you can also pass strings.

**Passing Variables to SHOW()**:

Variables can be passed directly to the SHOW() function:

```PERFACARDOR
START
    SHOW('Shower') <-- Displays the program name
    CREATE VAR test <-- 'test' is the variable name
    CALC(test=9*9) <-- Assigns the arithmetic expression to variable 'test'
    SHOW(test) <-- Passes the variable and displays it
END
```

This way, we build a simple algorithmic program that evaluates expressions.

Alternatively, you can implement it **without passing variables** to functions:

```PERFACARDOR
START
    SHOW('Shower') <-- Displays the program name
    CALC(1+1) <-- Automatically evaluates and displays the operation
END
```

**Loading and Running Programs**:

To load, place your txt-program in `tray` folder.

To run, open `interpreter.exe` and input `Load and run` option.
After that, enter program name to run, example: `test.txt`.

Press ENTER pn keyboard.

Your 'digital punch card' will be loaded into the interpreter from the `tray`, and the execution result will be displayed in the terminal.