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

3. *VAR* - Объявление переменной

4. *IF* - Условный оператор ЕСЛИ

5. *ELSE* - Условный оператор ИНАЧЕ

6. *ENDIF* - Маркировачный оператор конца условий. Необязателен

7. *SHOW()* - Отображение информации на экране

8. *CALC()* - Вычислительная функция

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

**Условные конструкции**:

Чтобы обозначить рамки для условий, используются теги `IF` и `ELSE`. Что бы передать параметры условия, после `IF`, прописываются аргументы для успешного выполнения условия, обязательно ставим синтаксическую связку `THEN` дабы показать, какие команды будут происходить. `ELSE` будет работать в том случае, если результаты условия не были удволетворены.

```PERFACARDOR
START
    VAR A = 42 <-- Объявление переменной
    SHOW(A) <-- Выводим содержание переменной
    IF A < 10 THEN <-- Объявляем условие, задаем аргументы для выполнения, ЕСЛИ условие ввыполняется, ТОГДА
        SHOW('End') <-- Показываем 'End'
    ELSE <-- В ином случае
        SHOW('Keep') <-- Показываем 'Keep'
    ENDIF <-- Можно обозначить, что условие закончилось, для удобства компилятора 
END
```

**Определение переменных** происходит так:

```PERFACARDOR
START
    SHOW('Shower') <-- Отображение навзания исполняемой программы
    VAR test = 10 <-- 'test' имя переменной 
END
```

Мы можем передать в переменную ТОЛЬКО числовое значение

**Вычислительная функция CALC()**:

Готовый калькулятор. Поддерживает операторы сложения, деления, вычитания, умножения.

После вычисления, выводит результат на экран.

В параметры CALC(), можно передавать любые вычислительные выражения;

Например: `CALC(42+42)`.

**Передача переменной в SHOW()**:

Можно передавать **переменные прямо в функцию**:

```PERFACARDOR
START
    SHOW('Shower') <-- Отображение навзания исполняемой программы
    VAR test = 90 <-- 'test' имя переменной 
    SHOW(test) <-- Передаем переменную и выводим на экран
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

To run program, enter `1` in main menu.

Note, `tray` folder is empty for first start. save .txt program to this folder. 

Enter name of your program and press ENTER

But without syntax's knownledge, no ways to write programs

### Syntax

**All available syntax tags:**
1. *START* - Program start

2. *END* - Program end

3. *VAR* - Variable declaration

4. *IF* - IF conditional operator

5. *ELSE* - ELSE conditional operator

6. *ENDIF* - Marker for the end of conditions. Optional

7. *SHOW()* - Display information on screen

8. *CALC()* - Calculation function

We'll examine each tag in descending order.

**Basics:**

To define program boundaries in **PERFACARDOR**, use the `START` and `END` tags, which contain the main program logic.

Every PERFACARDOR program must begin with the keyword START and end with END.

```PERFACARDOR
START
    [commands]
END
```

Knowing this, let's write our **first program**:

```PERFACARDOR
START
    SHOW('Hello, PERFACARDOR!')
END
```

**Conditional constructs**:

To define condition boundaries, use the `IF` and `ELSE` tags. To pass condition parameters, arguments for successful execution are written after `IF`, followed by the syntactic link `THEN` to indicate which commands will execute. `ELSE` will work if the condition results are not satisfied.

```PERFACARDOR
START
    VAR A = 42 <-- Variable declaration
    SHOW(A) <-- Display variable content
    IF A < 10 THEN <-- Declare condition, set arguments for execution, IF condition is met, THEN
        SHOW('End') <-- Show 'End'
    ELSE <-- Otherwise
        SHOW('Keep') <-- Show 'Keep'
    ENDIF <-- Can mark the end of the condition for compiler convenience
END
```

**Variable definition** works like this:

```PERFACARDOR
START
    SHOW('Shower') <-- Display program name
    VAR test = 10 <-- 'test' variable name
END
```

We can **only** assign numerical values to variables.

Calculation **function CALC()**:

A ready-made calculator. Supports addition, division, subtraction, and multiplication operators.

After calculation, displays the result on screen.

Any computational expressions can be passed to CALC() parameters:

For example: `CALC(42+42)`.

Passing variables to SHOW():

```PERFACARDOR
START
    SHOW('Shower') <-- Display program name
    VAR test = 90 <-- 'test' variable name
    SHOW(test) <-- Pass the variable and display it
END
```

**Launch and loading**:

To load a program, place the ready txt-file in the `tray` folder.

To run, open `interpreter.exe` and select `Load and run`.

Then enter your program name you want to run, for example `test.txt`.

Press ENTER on your keyboard.

Your 'digital punch card' will be loaded into the interpreter from tray, and the execution result will be displayed in the terminal.