#include <iostream>
#include <string>
#include <vector>
#include <sstream>


int CounterUppers(const std::string& word);
char SwapCase(char c);
std::string InvertCase(std::string& s);
void SortWords(std::vector<std::string>& words);
std::vector<std::string> SplitByWords(const std::string& s);
std::string JoinWordsIntoString(const std::vector<std::string> words);



int main()
{
    std::string input;
    std::cout << "Input your text here: ";
    std::getline(std::cin, input);
    std::string Swapped = InvertCase(input);

    std::vector<std::string> words = SplitByWords(Swapped);

    SortWords(words);

    std::cout << JoinWordsIntoString(words);
    return 0;
}


















int CounterUppers(const std::string& word)
{
    int count = 0;
    for (char c : word) {
        if (std::isupper(static_cast<unsigned char>(c))) {
            count++;
        }
    }
    return count;
}

char SwapCase(char c)
{
    if (std::islower(static_cast<unsigned char>(c))) {
        return (std::toupper(static_cast<unsigned char>(c)));
    }
    else if (std::isupper(static_cast<unsigned char>(c))) {
        return (std::tolower(static_cast<unsigned char>(c)));
    }
}


std::string InvertCase(std::string& s)
{
    std::string result;
    result.reserve(s.size());
    for (char c : s) {
        result += SwapCase(c);
    }
    return result;
}

void SortWords(std::vector<std::string>& words)
{
    for (int i = 0; i < words.size() - 1; ++i) {
        for (int j = 0; j < words.size() - 1 - i; ++j) {
            int up1st = CounterUppers(words[i]);
            int up2nd = CounterUppers(words[j + 1]);

            bool swap = false;
            if (up1st > up2nd) {
                swap = true;
            }
            else if (up1st == up2nd && words[i] > words[j + 1]) {
                swap = true;
            }

            if (swap) {
                std::string temp;
                words[i] = words[j + 1];
                words[j + 1] = temp;
            }
        }
    }
}

std::vector<std::string> SplitByWords(const std::string& s)
{
    std::istringstream iss(s);
    std::vector <std::string> words;
    std::string word;

    while (iss >> word) {
        words.push_back(word);
    }
    return words;
}

std::string JoinWordsIntoString(const std::vector<std::string> words)
{
    if (words.empty()) return " ";
    std::string result = words[0];
    for (size_t i = 1; i < words.size(); ++i) {
        result += " " + words[i];
    }
    return result;
}
