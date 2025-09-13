#include <iostream>
#include <bitset> 

int main()
{
    setlocale(LC_ALL, "Russian");
    int a, b;
    std::cout << "Введите натуральное десятичное число: ";
    std::cin >> a;


    if (std::cin.fail()) {
        std::cout << "Ошибка: введите число!" << std::endl;
    }
    else {
        std::cout << "Шестнадцатеричная форма: " << std::hex << a << std::endl;
        std::cout << "Двочиная форма: " << std::bitset<8>(a) << std::endl;
    }
    return 0;
}
