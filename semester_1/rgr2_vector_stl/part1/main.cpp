#include <iostream>
#include <vector>

int MyAbs(int x) {
    if (x < 0) return -x;
    else if (x == 0) return 0;
    else {
        return x;
    }
}


std::vector<int> LocaleVector() {
    std::vector<int> vec;
    int numbers;
    std::cout << "Input numbers into vector (For end enter something other than a number): ";
    while (std::cin >> numbers) {
        vec.push_back(numbers);
    }
    return vec;
}

void PrintVector(const std::vector<int>& vec) {
    std::cout << "[";
    for (size_t i = 0; i < vec.size(); ++i) {
        if (i > 0) {
            std::cout << ", ";
        }
        std::cout << vec[i];
    }
    std::cout << "]" << std::endl;
}

int SumOfNumbers(const std::vector<int>& vec) {
    int sum = 0;
    for (int x : vec) {
        sum += x;
    }
    return sum;
}



size_t QuantityOfNumGiven(const std::vector<int>& vec, int num_given) {
    size_t result = 0;
    for (int x : vec) {
        if (x == num_given) {
            result++;
        }
    }
    return result;
}
size_t QuantityOfPredicatGiven(const std::vector<int>& vec) {
    size_t result = 0;
    for (int x : vec) {
        if (x >= 5)  
        {
            result++;
        }
    }
    return result;
}

void RellocateNuls(std::vector<int>& vec) {
    if (vec.empty()) throw "Can't relocate nuls, your vector is empty!";
    int medium_result = SumOfNumbers(vec) / vec.size();
    for (size_t i = 0; i < vec.size(); i++) {
        if (vec[i] == 0) {
            vec[i] = medium_result;
        }
    }
}

void RellocateEvenNums(std::vector<int>& vec) {
    if (vec.empty()) throw "Can't relocate even nums, your vector is empty!";

    int difference = 0;
    int maxima = vec[0];
    int minima = vec[0];

    for (size_t i = 1; i < vec.size(); ++i) {
        if (vec[i] > maxima) maxima = vec[i];
        if (vec[i] < minima) minima = vec[i];
    }
    difference = maxima - minima;
    for (size_t k = 0; k < vec.size(); k++) {
        if (MyAbs(vec[k]) % 2 == 0) {
            vec[k] = difference;
        }
    }
}

void RemoveEqualByModul(std::vector<int>& vec) {
    if (vec.empty()) return;

    std::vector<int> result;
    std::vector<int> seen_mods;

    for (int x : vec) {
        int mod_x = MyAbs(x);

        bool found = false;
        for (int m : seen_mods) {
            if (m == mod_x) {
                found = true;
                break;
            }
        }

        if (!found) {
            result.push_back(x);
            seen_mods.push_back(mod_x);
        }
    }

    vec = result;
}

int main()
{
    try {
        std::vector<int> ya = LocaleVector();
        PrintVector(ya);
        std::cout << "Sum equals: " << SumOfNumbers(ya) << std::endl;
        std::cout << "Quantity: " << ya.size() << std::endl;
        int n = 4;
        std::cout << "QuantityOfNumGiven (Num = " << n << "): " << QuantityOfNumGiven(ya, n) << std::endl;
        std::cout << "QuantityOfPredicatGiven (x >=5): " << QuantityOfPredicatGiven(ya) << std::endl;

        RellocateNuls(ya);
        std::cout << "\nVector after relocate nuls to arithmetic mean ---> ";
        PrintVector(ya);

        RellocateEvenNums(ya);
        std::cout << "\nVector after relocate even nums to difference between max and min ---> ";
        PrintVector(ya);

        RemoveEqualByModul(ya);
        std::cout << "\nVector after delete equals nums ---> ";
        PrintVector(ya);
    }
    catch (const char* msg) {
        std::cout << "Error: " << msg << std::endl;
    }
    return 0;
}



