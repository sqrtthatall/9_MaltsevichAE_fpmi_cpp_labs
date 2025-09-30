#include <iostream>
#include <random>

int const size = 99;

// Функция проверки, является ли подмассив палиндромом
bool isPalindrome(int* arr, int start, int end) {
    while (start < end) {
        if (arr[start] != arr[end]) {
            return false;
        }
        start++;
        end--;
    }
    return true;
}

int main()
{
    setlocale(LC_ALL, "Russian");

    int* arr = new int[size];
    int choice;
    float a, b;
    std::cout << "Для заполнения массива есть два варианта" << std::endl;
    std::cout << "1. Вручную" << std::endl;
    std::cout << "2. При помощи рандомных чисел с указанием отрезка [a;b] где a < b" << std::endl;
    std::cin >> choice;

    int n = 0;

    if (choice == 1) {
        std::cout << "Вы выбрали непростой путь..." << std::endl;
        std::cout << "Далее вводите число -> Enter. Для остановки введите 0 (ноль)" << std::endl;

        while (n < size) {
            float input;
            std::cout << "Введите число для " << (n + 1) << "-го элемента массива: ";
            std::cin >> input;

            if (input == 0) {
                break;
            }
            arr[n] = static_cast<int>(input);
            n++;
        }

    }
    else if (choice == 2) {
        int i;
        n = i; 
        std::cout << "Введите границы интервала [a, b]:\n";
        std::cout << "a = ";
        std::cin >> a;
        std::cout << "b = ";
        std::cin >> b;
        if (a > b) {
            std::cout << "Ошибка: a должно быть <= b!\n";
            delete[] arr;
            return 1;
        }
        std::cout << "Введите количество элементов (не более " << size << "): ";
        std::cin >> i;
        if (i > size) i = size;
        if (i < 0) i = 0;

        std::random_device rd;
        std::mt19937 gen(rd());
        std::uniform_real_distribution<float> dist(a, b);
        for (int j = 0; j < i; j++) {
            arr[j] = static_cast<int>(dist(gen));
        }

    }
    else {
        std::cout << "Введите 1 либо 2 :)" << std::endl;
        delete[] arr;
        return 1;
    }

    int maxLen = 0;
    int maxStart = 0;

    for (int i = 0; i < n; ++i) {
        for (int j = i; j < n; ++j) {
            if (isPalindrome(arr, i, j)) {
                int currentLen = j - i + 1;
                if (currentLen > maxLen) {
                    maxLen = currentLen;
                    maxStart = i;
                }
            }
        }
    }

    if (maxLen == 0) {
        std::cout << "В массиве нет палиндромов длиной >= 1." << std::endl;
    }
    else {
        std::cout << "Самый длинный палиндром: ";
        for (int i = maxStart; i < maxStart + maxLen; ++i) {
            std::cout << arr[i] << " ";
        }
        std::cout << std::endl;
    }

    int lastPositiveIndex = -1;

    for (int i = 0; i < n; ++i) {
        if (arr[i] > 0) {
            lastPositiveIndex = i;
        }
    }

    if (lastPositiveIndex == -1) {
        std::cout << "В массиве нет положительных элементов." << std::endl;
        std::cout << "Сумма до последнего положительного: 0" << std::endl;
    }
    else {
        int sum = 0;
        for (int i = 0; i < lastPositiveIndex; ++i) {
            sum += arr[i];
        }

        std::cout << "Сумма элементов до последнего положительного: " << sum << std::endl;
    }

    delete[] arr;
    return 0;

}
