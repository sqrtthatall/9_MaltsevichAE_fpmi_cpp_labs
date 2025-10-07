#include <iostream>
#include <random>
#include <clocale>

const int MAX_SIZE = 99;

//Функция проверки является ли подмассив палиндромом
bool isPalindrome(const int* arr, int start, int end) {
    while (start < end) {
        if (arr[start] != arr[end]) {
            return false;
        }
        ++start;
        --end;
    }
    return true;
}

// Заполнение массива вручную
int fillManually(int* arr, int maxSize) {
    std::cout << "Вы выбрали непростой путь...\n";
    std::cout << "Далее вводите число -> Enter. Для остановки введите 0 (ноль)\n";

    int count = 0;
    while (count < maxSize) {
        float input;
        std::cout << "Введите число для " << (count + 1) << "-го элемента массива: ";
        std::cin >> input;

        if (input == 0) {
            break;
        }
        arr[count] = static_cast<int>(input);
        ++count;
    }
    return count;
}

// Заполнение массива случайными числами от а до б
int fillRandomly(int* arr, int maxSize) {
    float a, b;
    std::cout << "Введите границы интервала [a, b]:\n";
    std::cout << "a = ";
    std::cin >> a;
    std::cout << "b = ";
    std::cin >> b;

    if (a > b) {
        std::cout << "Ошибка: a должно быть <= b!\n";
        return -1; // ошибка
    }

    int count;
    std::cout << "Введите количество элементов (не более " << maxSize << "): ";
    std::cin >> count;

    if (count < 0) count = 0;
    if (count > maxSize) count = maxSize;

    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<int> dist(static_cast<int>(a), static_cast<int>(b));

    for (int i = 0; i < count; ++i) {
        arr[i] = dist(gen);
    }

    return count;
}

// Находим самый длинный палиндромный подмассив и выводит его
void findAndPrintLongestPalindrome(const int* arr, int n) {
    if (n == 0) {
        std::cout << "Массив пуст.\n";
        return;
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
        std::cout << "В массиве нет палиндромов длиной >= 1.\n";
    } else {
        std::cout << "Самый длинный палиндром: ";
        for (int i = maxStart; i < maxStart + maxLen; ++i) {
            std::cout << arr[i] << " ";
        }
        std::cout << "\n";
    }
}

// Вычисляем сумму элементов до последнего положительного
void printSumBeforeLastPositive(const int* arr, int n) {
    int lastPositiveIndex = -1;
    for (int i = 0; i < n; ++i) {
        if (arr[i] > 0) {
            lastPositiveIndex = i;
        }
    }

    if (lastPositiveIndex == -1) {
        std::cout << "В массиве нет положительных элементов.\n";
        std::cout << "Сумма до последнего положительного: 0\n";
    } else {
        long long sum = 0; 
        for (int i = 0; i < lastPositiveIndex; ++i) {
            sum += arr[i];
        }
        std::cout << "Сумма элементов до последнего положительного: " << sum << "\n";
    }
}

int main() {
    std::setlocale(LC_ALL, "Russian");

    int* arr = new int[MAX_SIZE];
    int n = 0;

    std::cout << "Для заполнения массива есть два варианта:\n";
    std::cout << "1. Вручную\n";
    std::cout << "2. Случайными числами из отрезка [a; b] (a <= b)\n";
    int choice;
    std::cin >> choice;

    if (choice == 1) {
        n = fillManually(arr, MAX_SIZE);
    } else if (choice == 2) {
        n = fillRandomly(arr, MAX_SIZE);
        if (n == -1) {
            delete[] arr;
            return 1;
        }
    } else {
        std::cout << "Неверный выбор. Введите 1 или 2.\n";
        delete[] arr;
        return 1;
    }

    // Вывод результатов
    findAndPrintLongestPalindrome(arr, n);
    printSumBeforeLastPositive(arr, n);

    delete[] arr;
    return 0;
}
