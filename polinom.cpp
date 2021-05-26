﻿#include <iostream>
#include <cmath>
#include <clocale>

using namespace std;

class Converter
{
public:

    void koef(int n)
    {
        int k[n];
        std::cout<<"Введите коэффициенты мономов\n";
        for (int i=0;i<=n;i++)
           std::cin>>k[i];    
        
        polin(n,k); 
    }
    
      

    void polin(int n, int *k)
    {
        int m=n;
        for (int i=0;i<n;i++)
            {std::cout<<k[i]<<"*x^("<<m<<") + ";
            m--;}
        std::cout<<k[n]<<"\n";
        
        std::cout<<"Поиск коэффициента по его номеру, введите номер\n";
        int h;
        std::cin>>h;
        if (h>n+1||h<0) 
        {
        std::cout<<"Вышли за пределы разряда";
        exit(true);
        }
        std::cout<<"Коэффициент "<<k[h-1]<<"\n"; 
        int hlobal=n;     
        
        pcount(n, k, hlobal);
    }   
    
    void pcount(int n, int *k, int hlobal)
    {
        
        std::cout<<"Введите х:\n";
        int x;
        
        std::cin>>x;
        int res=0;
        for (int i=0;i<n;i++)
            {
                res=res+k[i]*pow(x,hlobal);
                hlobal--;
            }
        res=res+k[n];       
        std::cout<<res; 
        
        pproizv(n, k);      
    }
    
    void pproizv(int n, int *k)    
    {
        std::cout<<"\nПроизводная ";
        int m=n;
        for (int i=0;i<n;i++)
            {std::cout<<k[i]*m<<"*x^("<<m-1<<") + ";
            m--;}
        std::cout<<"0\n";
    }
};
    

int main()
{
    setlocale(LC_ALL, "rus");
    Converter objConverter;

    int n,hlobal;
    int k[n];
    std::cout << "Введите значение степени полинома:\n";
    std::cin>>n;
     
    objConverter.koef(n);
     
    
    
    
}