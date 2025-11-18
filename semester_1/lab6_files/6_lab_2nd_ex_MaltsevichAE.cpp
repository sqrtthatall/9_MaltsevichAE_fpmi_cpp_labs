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
    const std::string input_file = "input.txt";
    std::ifstream fin(input_file);
    
    if (!IsEmptyFile) {
        std::cout << "File is empty!";
        exit(405);
    }

    if (!fin.is_open()) {
        std::cout << "Error: Could not open the file.";
        exit(404);
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


}
