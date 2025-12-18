#include <iostream>
#include <vector>
#include <numeric>
#include <algorithm>

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
    return std::accumulate(vec.begin(), vec.end(), 0);
}



size_t QuantityOfNumGiven(const std::vector<int>& vec, int num_given) {
    return static_cast<size_t>(std::count(vec.begin(), vec.end(), num_given));
}

size_t QuantityOfPredicatGiven(const std::vector<int>& vec) {
    return static_cast<size_t>(std::count_if(vec.begin(), vec.end(), [](int x) {return x >= 5; }));
}

void RellocateNuls(std::vector<int>& vec) {
    if (vec.empty()) {
        throw "Can't relocate nuls, your vector is empty!";
    }
    int sum = std::accumulate(vec.begin(), vec.end(), 0);
    int medium_result = sum / static_cast<int>(vec.size());
    std::replace(vec.begin(), vec.end(), 0, medium_result);
}

void RellocateEvenNums(std::vector<int>& vec) {
    if (vec.empty()) throw "Can;t Relocate even nums, vector is empty!";

    std::vector<int>::const_iterator min_it = std::min_element(vec.begin(), vec.end());
    std::vector<int>::const_iterator max_it = std::max_element(vec.begin(), vec.end());


    int difference = *max_it - *min_it;

    std::replace_if(vec.begin(), vec.end(),
        [](int x) -> bool {
            return std::abs(x) % 2 == 0;
        },
        difference
    );
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





