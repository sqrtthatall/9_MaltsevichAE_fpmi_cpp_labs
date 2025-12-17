#include <iostream>
#include <fstream>
#include <string>
#include <sstream>

bool IsEmptyFile(std::ifstream& file)
{
    return file.peek() == std::ifstream::traits_type::eof();
}

int main()
{
    std::locale::global(std::locale("ru_RU.UTF-8"));
    std::wcin.imbue(std::locale());
    std::wcout.imbue(std::locale());
    const std::string input_file = "input.txt";
    std::ifstream fin(input_file);

    if (!IsEmptyFile) {
        std::cerr << "\033[31mError:File is empty!\033[0m\n";
        return 1;
    }

    if (!fin.is_open()) {
        std::cerr << "\033[31mError:Could not open the file: \033[0m" << "'" << input_file << "'" << "\033[31m \nCreate file or check the file name!\n\033[0m\n";
        return 2;
    }

    std::string NeedToCount;
    std::string line;

    std::getline(fin, NeedToCount);

    int counter = 0;

    while (std::getline(fin, line)) {
        std::istringstream iss(line);
        std::string word;
        while (iss >> word) {
            if (word == NeedToCount) {
                ++counter;
            }
        }
    }

    std::cout << counter << std::endl;
    return 0;
    fin.close();
    
}
