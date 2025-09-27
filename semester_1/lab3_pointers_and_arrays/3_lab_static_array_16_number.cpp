#include <iostream>
const int max_size = 99;

int main() {
    setlocale(LC_ALL, "Russian");
    float array[max_size];
    float n;
    float long multy = 1;
    float long sum_elems = 0;
    int i = 0;

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

    // Поиск индекса минимального элемента массива
    int min_index = 0;
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
            // Проверка на наличие положительных числе в массиве
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
