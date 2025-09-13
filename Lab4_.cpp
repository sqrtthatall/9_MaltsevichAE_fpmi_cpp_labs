#include <iostream>

int main()
{
    setlocale(LC_ALL, "Russian");
    int k;
    long long m = 1;
    std::cout << "Чтобы вычислить двойной факториал числа, введите его далее >>> ";
    if (!(std::cin >> k)) {
        std::cout << "Введите число!!!";
        exit(1);
    }
    else {

        if (k % 2 == 0) {

            for (int long i = 2; i <= k; i += 2) {
                m *= i;
            }

        }
        else {
            
            for (int long i = 1; i <= k; i += 2) {
                m *= i;
            }

        }
        std::cout << "=================================================" << std::endl;
        std::cout << "Двойной факториал числа " << k << " равен: " << m << std::endl;
        std::cout << "=================================================" << std::endl;
    }
    return 0;
}

