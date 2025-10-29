#include <iostream>
#include <string>
#include <vector>

//Все строчные -> заглавные

void Capitalize()
{

}

//Все заглавные -> строчные

void Minimalize()
{

}

//

void SortByCountDigits()
{

}



size_t Count(const std::string& text)
{
    size_t count = 0;
    unsigned long start_index = 0;
    unsigned long finish_index = text.find_first_of(" ", start_index);
    while (start_index != std::string::npos)
    {
        std::string word = text.substr(start_index, (finish_index - start_index));
        if (!word.empty()) {
            count++;
        }
        start_index = text.find_first_not_of(" ", finish_index);
        finish_index = text.find_first_of(" ", finish_index + 1);
    }
    return count;
}   



int main()
{
    std::string text;
    std::cout << ".....: ";
    std::getline(std::cin, text);
    
    size_t words = Count(text);
    std::cout << words;


    return 0;
}
