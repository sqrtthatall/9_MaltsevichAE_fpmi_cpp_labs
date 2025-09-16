#include <iostream>

int main()
{
    int n;
    int original;
    int m = 0;

    std::cout << "Input a number: ";
    if (!(std::cin >> n)) {
        std::cout << "Input a NUMBER!!!";
        return 1;
    }
    else {
        original = n;

        while (n != 0) {
            m = (m * 10) + (n % 10);
            n /= 10;
        }

        if (original == m) {
            std::cout << original << " is a palindrome.";
        }
        else {
            std::cout << original << " is NOT a palindrome.";
        }
    }
    return 0;
}

