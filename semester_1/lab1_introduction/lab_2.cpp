#include <iostream>

int main()
{
    setlocale(LC_ALL, "Russian");
    int n;
    int sum_ = 0;
    int multy = 1;

    std::cout << "Введите число n: ";
    if (!(std::cin >> n)) {
        std::cout << "n должно быть числом!!!";
        exit(1);
    }
    else {
        for (int i = 0; i <= n; i += 2) {
            sum_ += i;
        }

        for (int i1 = 1; i1 <= n; i1 += 2) {
            multy *= i1;
        }

        std::cout << "Сумма чётных чисел равна: " << sum_ << std::endl;
        std::cout << "Произведение нечётных чисел равно: " << multy << std::endl;
    }
    return 0;
}

