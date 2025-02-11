// Example.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <string>

int main()
{
    std::string message;
    std::string message1{"ABC"};
    std::string message2 = { "TMP" };
    std::string message3("RRRR");
    std::string message4(5, 'Q'); // QQQQQ
    std::string message5{ "hello world", 4 }; // берем первые 4 символа - message5 = hell
    std::string message6{ "hello world", 6, 5 }; // 5 символов начиная с 6 символа - message6 = world

    // считывание всей строки 
    std::string name;
    std::cout << "Input your name: ";
    getline(std::cin, name);
    std::cout << "Your name: " << name << std::endl;

    // размер строки
    std::string message7{ "Hello" };
    std::cout << "Length: " << message7.length() << std::endl;   // Length: 5
    std::cout << "Size: " << message7.size() << std::endl;       // Size: 5

    // пустая ли строка
    std::string message8;
    if (message8.empty())
        std::cout << "string is empty " << std::endl;
    else
        std::cout << "string is not empty" << std::endl;

    // объединение строк
    std::string hello{ "hello" };
    std::string world{ "world" };
    std::string msg{ hello + " " + world };
    std::cout << msg << std::endl;    // hello world
    // std::string tmp{ "hello " + "world" + "!"};   // ! Ошибка
    // std::string tmp{ hello + " world" "!" };   // hello world!
    using namespace std::string_literals; // строки в std::string
    std::string foo{ "hello "s + "world"s + "!"s };

    // спец символы
    std::string text{ "Name: \t\"Tom\"\nAge:\t38" };
    std::cout << text << std::endl;

    // raw
    std::string text2
    { R"(Name:   "Tom"
         Age:    38)" };
    std::cout << text2 << std::endl;

    // методы строк
    std::string test{"Too much"};
    test.resize(5);
    std::cout << test << " " << test.size() << std::endl;
    test.resize(10);
    std::cout << test << " " << test.size() << " '" << test[9] << "' " << std::endl;
    test.resize(12, 'w');
    std::cout << test << " " << test.size() << std::endl;
    // .clear(), .push_back('a')
    test.append("FEFM"); // .append(n, c), .append(T, pos, count)
    std::cout << test << " " << test.size() << std::endl;
    // S.erase(pos) - удаляет из строки S  с символа с индексом pos и до конца строки.
    // S.erase(pos, count) - удаляет из строки S  с символа с индексом pos количеством count или до конца строки, если pos + count > S.size().
    /*
     S.insert(i, n, c) - вставить n одинаковых символов, равных с. n имеет целочисленный тип, c - char.
     S.insert(i, T) - вставить содержимое строки T. T может быть объектом класса string или C-строкой.
     S.insert(i, T, pos, count) - вставить символы строки T начиная с символа с индексом pos количеством count.
     
     S.substr(pos) - возвращает подстроку данной строки начиная с символа с индексом pos и до конца строки.
     S.substr(pos, count) - возвращает подстроку данной строки начиная с символа с индексом pos количеством count или до конца строки, если pos + count > S.size().
     
     S.replace(pos, count, n, c) - вставить n одинаковых символов, равных с. n имеет целочисленный тип, c - char.
     S.replace(pos, count, T) - вставить содержимое строки T. T может быть объектом класса string или C-строкой.
     S.replace(pos, count, T, pos2, count2) - вставить символы строки T начиная с символа с индексом pos количеством count.
    
    S.find(str, pos = 0) - искать первое входение строки str начиная с позиции pos. Если pos не задано - то начиная с начала строки S.
    S.find(str, pos, n) - искать в данной строке подстроку, равную первым n символам строки str. Значение pos должно быть задано.

    rfind: Ищет последнее вхождение подстроки ("правый" поиск). Способы вызова аналогичны способам вызова метода find.

    S.find_first_of(str, pos = 0) - искать первое входение любого символа строки str начиная с позиции pos. Если pos не задано - то начиная с начала строки S.
    
    find_last_of: Ищет в данной строке последнее появление любого из символов данной строки str.

    find_first_not_of / find_last_not_of

    c_str: Возвращает указать на область памяти, в которой хранятся символы строки, возвращает значение типа char*. Возвращаемое значение можно рассматривать как C-строку и использовать в функциях, которые должны получать на вход C-строку.
    */
}