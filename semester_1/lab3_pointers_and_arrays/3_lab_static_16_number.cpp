#include <iostream>
#include <random>

const int max_size = 99;

int main() {
    setlocale(LC_ALL, "Russian");
    float array[max_size];
    int i = 0;
    int choice;
    float a, b;
    int min_index = 0;
    float long multy = 1;
    float long sum_elems = 0;
    
    std::cout << "Выберите способ заполнения массива:\n";
    std::cout << "1. Вручную\n";
    std::cout << "2. Случайными числами\n";
    std::cout << "Ваш выбор: ";
    std::cin >> choice;

    if (choice == 1) {
        // Ввод массива вручную
        float n;
        std::cout << "Введите числа, входящие в массив, (число -> Enter)" << std::endl;
        std::cout << "Для завершения ввода введите -> 0 <- (ноль)!" << std::endl;
        while (true) {
            std::cout << "Введите " << i + 1 << "-й элемент массива: ";
            std::cin >> n;
            if (n == 0) {
                break;
            }
            if (i >= max_size) {
                std::cout << "Ошибка: массив переполнен!" << std::endl;
                break;
            }
            array[i] = n;
            i++;
        }
    }
    else if (choice == 2) {
        // Ввод границ интервала и генерация случайных чисел
        std::cout << "Введите границы интервала [a, b]:\n";
        std::cout << "a = ";
        std::cin >> a;
        std::cout << "b = ";
        std::cin >> b;
        if (a > b) {
            std::cout << "Ошибка: a должно быть <= b!\n";
            return 1;
        }
        std::cout << "Введите количество элементов (не более " << max_size << "): ";
        std::cin >> i;
        if (i > max_size) i = max_size;

        std::random_device rd;
        std::mt19937 gen(rd());
        std::uniform_real_distribution<float> dist(a, b);
        for (int j = 0; j < i; j++) {
            array[j] = dist(gen);
        }
    }
    else {
        std::cout << "Некорректный выбор!\n";
        return 1;
    }

    // Поиск индекса минимального элемента массива

    if (i > 0) {
        for (int j = 1; j < i; j++) {
            if (array[j] < array[min_index]) {
                min_index = j;
            }
        }
    }
    else {
        std::cout << "Массив пуст!" << std::endl;
        return 0;
    }

    // Произведение положительных элементов

    bool has_positive = false;
    for (int j = 0; j < i; j++) {
        if (array[j] > 0) {
            multy *= array[j];
            has_positive = true;
        }
    }

    if (has_positive) {
        std::cout << "Произведение положительных элементов массива = " << multy << std::endl;
    }
    else {
        std::cout << "В массиве нет положительных элементов!" << std::endl;
    }
    
    // Сумма элементов до первого минимального элемента

    for (int j = 0; j < min_index; j++) {
        sum_elems += array[j];
    }
    std::cout << "Сумма элементов массива до первого минимального элемента = " << sum_elems << std::endl;

    return 0;
}
