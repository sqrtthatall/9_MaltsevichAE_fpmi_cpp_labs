#include <iostream>
#include <ctime>
#include <cstdlib>
const int max_size = 99;

void FillArrayManual(float* array, int size)
{
    if (size > max_size) {
        std::cout << "Максимальное кол-во элементов - " << max_size;
        throw " !!!More elems that can keep array!!! ";
    }
    else {
        for (int i = 0; i < size; i++) {
            std::cout << "Введите " << i + 1 << " элемент массива: ";
            std::cin >> array[i];
        }
    }
}

void FillArrayByRandomNumbersFromAToB(float* array, int size, float a, float b)
{
    if (a >= b) throw "a must be bigger than b";
    if (size > max_size) {
        std::cout << "Максимальное кол-во элементов - " << max_size << std::endl;
        exit(0);
    }

    std::srand(static_cast<unsigned int>(std::time(nullptr)));
    for (int i = 0; i < size; i++) {
        array[i] = a + static_cast<float>(std::rand()) / RAND_MAX * (b - a);
    }
}

void PrintArray(float* array, int size)
{
    for (int i = 0; i < size; i++) {
        std::cout << array[i] << " ";
    }
}



int FindMinIndex(float* array, int size)
{
    int MinIndex = 0;
    for (int i = 1; i < size; i++)
    {
        if (array[i] < array[MinIndex]) {
            MinIndex = i;
        }
    }
    return MinIndex;
}


double ComputePositiveProduct(const float* array, int size)
{
    long double multy = 1;
    for (int i = 0; i < size; i++) {
        if (array[i] > 0) {
            multy *= array[i];
        }
    }
    return multy;
}

double SumForFirstMinIndex(const float* array, int size, int min)
{
    double sum = 0;
    for (int i = 0; i < min; i++) {
        sum += array[i];
    }
    return sum;
}




int main()
{
    setlocale(LC_ALL, "Russian");

    try {
        int size;
        std::cout << "Введите количество элементов массива: ";
        std::cin >> size;

        float array[max_size];
        int choice;
        std::cout << "Выберите способ заполнения массива:\n1 — вручную\n2 — случайными числами\nВаш выбор: ";
        std::cin >> choice;

        if (choice == 1) {
            FillArrayManual(array, size);
        }
        else if (choice == 2) {
            float a, b;
            std::cout << "Введите границы диапазона [a, b]:\na = ";
            std::cin >> a;
            std::cout << "b = ";
            std::cin >> b;
            FillArrayByRandomNumbersFromAToB(array, size, a, b);
        }
        else {
            std::cout << "Неверный выбор!" << std::endl;
            return 1;
        }

        PrintArray(array, size);
        std::cout << std::endl;
        int minIndex = FindMinIndex(array, size);
        long double product = ComputePositiveProduct(array, size);
        float sumBeforeMin = SumForFirstMinIndex(array, size, minIndex);

        std::cout << "Индекс минимального элемента: " << minIndex << std::endl;
        std::cout << "Произведение положительных элементов: " << product << std::endl;
        std::cout << "Сумма элементов до первого минимального: " << sumBeforeMin << std::endl;
    }
    catch (const char* msg) {
        std::cout << msg;
    }
    return 0;
}
