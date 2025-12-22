#include <set>
#include <iostream>

std::set<int> FinderOfPrimeNumbers(int num) {
    if (num < 2 || isdigit(num)) throw "Invalid input!!!\n";
    else {
        std::set<int> MayBeePrime;
        for (int i = 2; i <= num; ++i) {
            MayBeePrime.insert(i);
        }

        std::set<int> Primes;

        while (!MayBeePrime.empty()) {
            int p = *MayBeePrime.begin();
            Primes.insert(p);
            MayBeePrime.erase(MayBeePrime.begin());

            for (long long x = p * p; x <= num; x += p) {
                MayBeePrime.erase(x);
            }
        }
        return Primes;
    }
}


int main()
{
    try {
        std::set<int> PrimeNums = FinderOfPrimeNumbers(200);
        std::cout << "Prime nums: ";
        for (int nums : PrimeNums) {
            std::cout << nums << " ";
        }
    }
    catch (const char* msg) {
        std::cerr << "Error: " << msg;
    }
}
