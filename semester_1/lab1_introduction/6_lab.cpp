#include <algorithm>
#include <iostream>
#include <string>
int main()
{
    std::string a;
    std::cout << "Input word in English: ";
    std::cin >> a;

    std::string b = a;
    std::reverse(b.begin(), b.end());

    if (a == b) {
        std::cout << "Palindrome";
    }
    else {
        std::cout << "Not Palindrome";
    }
    return 0;
}
