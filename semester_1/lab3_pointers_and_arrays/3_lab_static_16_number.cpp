#include <iostream>
#include <random>

const int max_size = 99;

// Функция для ручного ввода массива
int fillArrayManually(float array[]) {
    float n;
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
    return i;
}

// Функция для заполнения массива случайными числами
int fillArrayRandomly(float array[], float a, float b) {
    int count;
    std::cout << "Введите количество элементов (не более " << max_size << "): ";
    std::cin >> count;
    if (count > max_size) count = max_size;

    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_real_distribution<float> dist(a, b);
    for (int j = 0; j < count; j++) {
        array[j] = dist(gen);
    }
    return count;
}

// Поиск индекса первого минимального элемента
int findMinIndex(const float array[], int size) {
    int min_index = 0;
    for (int j = 1; j < size; j++) {
        if (array[j] < array[min_index]) {
            min_index = j;
        }
    }
    return min_index;
}

// Вычисление произведения положительных элементов
void computePositiveProduct(const float array[], int size) {
    long double multy = 1; 
    bool has_positive = false;
    for (int j = 0; j < size; j++) {
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
}

// Вычисление суммы элементов до первого минимального
void computeSumBeforeMin(const float array[], int min_index) {
    long double sum_elems = 0; 
    for (int j = 0; j < min_index; j++) {
        sum_elems += array[j];
    }
    std::cout << "Сумма элементов массива до первого минимального элемента = " << sum_elems << std::endl;
}

int main() {
    setlocale(LC_ALL, "Russian");
    float array[max_size];
    int choice;
    float a, b;

    std::cout << "Выберите способ заполнения массива:\n";
    std::cout << "1. Вручную\n";
    std::cout << "2. Случайными числами\n";
    std::cout << "Ваш выбор: ";
    std::cin >> choice;

    int i = 0; 

    if (choice == 1) {
        i = fillArrayManually(array);
    }
    else if (choice == 2) {
        std::cout << "Введите границы интервала [a, b]:\n";
        std::cout << "a = ";
        std::cin >> a;
        std::cout << "b = ";
        std::cin >> b;
        if (a > b) {
            std::cout << "Ошибка: a должно быть <= b!\n";
            exit(1);
        }
        i = fillArrayRandomly(array, a, b);
    }
    else {
        std::cout << "Некорректный выбор!\n";
        return 1;
    }

    if (i == 0) {
        std::cout << "Массив пуст!" << std::endl;
        exit(3);
    }

    int min_index = findMinIndex(array, i);

    computePositiveProduct(array, i);
    computeSumBeforeMin(array, min_index);

    return 0;
}

 

