#include <iostream>

int main()
{
    int number;
    std::cout << "Input number: ";
    if(!(std::cin >> number)){
        std::cout << "Введите число";
            }
    else{
    int original = number;

    for (int digit = 0; digit < 10; ++digit) {
        int count = 0;
        int temp = original;

        while (temp > 0) {
            if (temp % 10 == digit) {
                count++;
            }
            temp /= 10;
        }

        if (count > 0) {
            std::cout << digit << " - " << count << " times" << std::endl;
        }
    }

    int result = 0;
    int multiplier = 1;
    number = original;

    while (number > 0) {
        int current_digit = number % 10;
        int count = 0;
        int temp = original;

        while (temp > 0) {
            if (temp % 10 == current_digit) {
                count++;
            }
            temp /= 10;
        }

        if (count % 2 != 0) {
            result = current_digit * multiplier + result;
            multiplier *= 10;
        }

        number /= 10;
    }

    if (result == 0) {
        result = 0;
    }

    std::cout << "Result: " << result << std::endl;

    return 0;
    }
}

