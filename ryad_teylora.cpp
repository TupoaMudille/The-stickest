﻿#include <iostream>
#include <cmath>
#include <clocale>

using namespace std;


double x, res = 1;
int n;
int i = 1, j = 1, f = 0, fi = 1;

class Converter
{
public:

    void exp1()
    {
        double result=0;
        std::cout << "Текущая функция exp(x)\n";

        std::cout << "Введите текущее значение ряда:\n";
        std::cin >> n;
        
        std::cout << "\nВведите значение х:\n";
        std::cin >> x;

        std::cout << "Формула данной функции:\n";
        while (i <= n)
        {
            res = res * i;
            std::cout << "x^" << i << " / " << res << "  +  ";
            result=result+(pow(x,i)/res);     
            i++;
        }
        std::cout << "  o(x)";

        std::cout << "\nЗначение ряда:";

        std::cout << result;

        std::cout << "\nЭталонное значение:\n" << exp(x);

        std::cout << "\nРазница между результатами:\n" << abs(exp(x) - result);

    }

    void sin1()
    {
        double result=0;
        
        std::cout << "Текущая функция sin(x)\n";

        std::cout << "Введите текущее значение ряда:\n";
        std::cin >> n;
        
        std::cout << "\nВведите значение х:\n";
        std::cin >> x;
        
        std::cout << "Формула данной функции:\n";
        while (i <= n)
        {
            std::cout << pow(-1, i + 1) << "*x^" << 2 * i - 1 << " / " << res << "  +  ";
            result=result+(pow(-1,i+1) * pow(x,2*i-1))/res;
            res = res * (j + 1) * (j + 2);
            j = j + 2;
            i++;
        }
        std::cout << "  o(x)";

        std::cout << "\nЗначение ряда:";
        std::cout << result;

        std::cout << "\nЭталонное значение:\n" << sin(x);

        std::cout << "\nРазница между результатами:\n" << abs(sin(x) - result);
    
    }

    void cos1()
    {
        double result=0;
        
        std::cout << "Текущая функция cos(x)\n";

        std::cout << "Введите текущее значение ряда:\n";
        std::cin >> n;

        std::cout << "\nВведите значение х:\n";
        std::cin >> x;
        
        std::cout << "Формула данной функции:\n";

        while (fi <= n)
        {

            std::cout << pow(-1, fi + 1) << "*x^" << 2 * fi << " / " << res << "  +  ";
            result=result+pow(-1, fi + 1) * pow(x, 2 * n) / res;
            res = res * (2 * f + 1) * (2 * f + 2);
            
            f++;
            fi++;

        }
        std::cout << "  o(x)";

        std::cout << "\nЗначение ряда:\n";
        std::cout << result;

        std::cout << "\nЭталонное значение:\n" << cos(x);

        std::cout << "\nРазница между результатами:\n" << abs(cos(x) - result);
    
    }
};



int main()
{
    setlocale(LC_ALL, "rus");
    Converter objConverter;

    int input;

    std::cout << "Выбор функции:\n";
    std::cout << "1. Экспонента\n";
    std::cout << "2. Синус\n";
    std::cout << "3. Косинус\n";

    std::cin >> input;

    switch (input)
    {
    case 1:
    {
        objConverter.exp1();
        break;
    }
    case 2:
    {
        objConverter.sin1();
        break;
    }
    case 3:
    {
        objConverter.cos1();
        break;
    }

    default:
    {
        std::cout << "error/n";
        break;
    }
    }
}