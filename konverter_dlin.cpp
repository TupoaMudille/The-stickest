﻿#include <iostream>
#include <cmath>
#include <clocale>

using namespace std;

float length;

class Converter
{
public:

    void a()
    {
        std::cout << "Текущая длина в аршинах:"<<length*1.41;
    }

    void s()
    {
        std::cout << "Текущая длина в саженях:" << length * 0.47;
    }

    void f()
    {
        std::cout << "Текущая длина в футах:" << length * 3.28;
    }

    void y()
    {
        std::cout << "Текущая длина в ярдах:" << length * 1.09;
    }
    
};



int main()
{
    setlocale(LC_ALL, "rus");
    Converter objConverter;

    std::cout << "Установите текущую длину в метрах:\n";
    std::cin >> length;

    int input;

    std::cout << "Узнать текущую длину в:\n";
    std::cout << "1. футах\n";
    std::cout << "2. ярдах\n";
    std::cout << "3. аршинах\n";
    std::cout << "4. саженях\n";

    std::cin >> input;

    switch (input)
    {
    case 1:
    {
        objConverter.f();
        break;
    }
    case 2:
    {
        objConverter.y();
        break;
    }
    case 3:
    {
        objConverter.a();
        break;
    }

    case 4:
    {
        objConverter.s();
        break;
    }

    default:
    {
        std::cout << "error/n";
        break;
    }
    }

    return 0;
}