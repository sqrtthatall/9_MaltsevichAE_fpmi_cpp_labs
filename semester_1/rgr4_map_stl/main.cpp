#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <map>
#include <algorithm>
#include <numeric>


struct Mark {
    std::string subject;
    size_t mark_;       
};

struct StudentData {
    std::string name;           
    size_t number;               
    std::vector<Mark> marks_;     


    double getAverage() const {
        if (marks_.empty()) return 0.0;
        double sum = 0;
        for (size_t i = 0; i < marks_.size(); ++i) {
            sum += marks_[i].mark_;
        }
        return sum / marks_.size();
    }
};


typedef std::map<size_t, StudentData> StudentMap;

int main() {
    StudentMap students;

    std::ifstream file("students.txt");
    if (!file.is_open()) {
        std::cout << "file not found!" << std::endl;
        return -1;
    }

    std::string name;
    size_t number, numMarks;
    while (file >> name >> number >> numMarks) {
        StudentData sd;
        sd.name = name;
        sd.number = number;
        for (size_t i = 0; i < numMarks; ++i) {
            Mark m;
            file >> m.subject >> m.mark_;
            sd.marks_.push_back(m);
        }
        students[number] = sd;
    }
    file.close();



    std::cout << "--- Sorted by ID ---" << std::endl;
    for (StudentMap::iterator it = students.begin(); it != students.end(); ++it) {
        std::cout << it->first << ": " << it->second.name << std::endl;
    }




    std::cout << "\n--- Average marks ---" << std::endl;
    for (StudentMap::iterator it = students.begin(); it != students.end(); ++it) {
        std::cout << it->second.name << ": " << it->second.getAverage() << std::endl;
    }


    std::vector<StudentData> sortedList;
    for (StudentMap::iterator it = students.begin(); it != students.end(); ++it) {
        sortedList.push_back(it->second);
    }

    std::sort(sortedList.begin(), sortedList.end(), [](const StudentData& a, const StudentData& b) {
        if (a.name != b.name) return a.name < b.name;
        return a.getAverage() > b.getAverage();
        });

    std::cout << "\n--- Alphabet List ---" << std::endl;
    for (size_t i = 0; i < sortedList.size(); ++i) {
        std::cout << i + 1 << ". " << sortedList[i].name << ", "
            << sortedList[i].number << ", " << sortedList[i].getAverage() << std::endl;
    }


    int minR = 7, maxR = 10;
    std::vector<StudentData> rangeList;
    for (StudentMap::iterator it = students.begin(); it != students.end(); ++it) {
        double avg = it->second.getAverage();
        if (avg >= minR && avg <= maxR) rangeList.push_back(it->second);
    }
    std::sort(rangeList.begin(), rangeList.end(), [](const StudentData& a, const StudentData& b) {
        return a.getAverage() > b.getAverage();
        });

    std::cout << "\n--- Average in range ---" << std::endl;
    for (size_t i = 0; i < rangeList.size(); ++i) {
        std::cout << rangeList[i].name << " (" << rangeList[i].getAverage() << ")" << std::endl;
    }



    std::string target = "Math";
    int count = 0;
    std::cout << "\n--- Subject: " << target << " ---" << std::endl;
    for (StudentMap::iterator it = students.begin(); it != students.end(); ++it) {
        for (size_t j = 0; j < it->second.marks_.size(); ++j) {
            if (it->second.marks_[j].subject == target) {
                std::cout << it->second.name << std::endl;
                count++;
                break;
            }
        }
    }
    std::cout << "Total: " << count << std::endl;




    std::map<std::string, std::vector<size_t> > subjMarks;
    for (StudentMap::iterator it = students.begin(); it != students.end(); ++it) {
        for (size_t j = 0; j < it->second.marks_.size(); ++j) {
            subjMarks[it->second.marks_[j].subject].push_back(it->second.marks_[j].mark_);
        }
    }

    std::cout << "\n--- Subject Averages ---" << std::endl;
    for (std::map<std::string, std::vector<size_t> >::iterator it = subjMarks.begin(); it != subjMarks.end(); ++it) {
        double sum = 0;
        for (size_t i = 0; i < it->second.size(); ++i) sum += it->second[i];
        std::cout << it->first << ": " << sum / it->second.size() << std::endl;
    }


    size_t maxS = 0;
    for (StudentMap::iterator it = students.begin(); it != students.end(); ++it) {
        size_t currentSum = 0;
        for (size_t j = 0; j < it->second.marks_.size(); ++j) currentSum += it->second.marks_[j].mark_;
        if (currentSum > maxS) maxS = currentSum;
    }

    std::cout << "\n--- Max total sum (" << maxS << ") ---" << std::endl;
    for (StudentMap::iterator it = students.begin(); it != students.end(); ++it) {
        size_t currentSum = 0;
        for (size_t j = 0; j < it->second.marks_.size(); ++j) currentSum += it->second.marks_[j].mark_;
        if (currentSum == maxS) std::cout << it->second.name << std::endl;
    }

    std::cout << "\n--- Failing students ---" << std::endl;
    for (StudentMap::iterator it = students.begin(); it != students.end(); ++it) {
        for (size_t j = 0; j < it->second.marks_.size(); ++j) {
            if (it->second.marks_[j].mark_ <= 4) {
                std::cout << it->second.name << std::endl;
                break;
            }
        }
    }

    return 0;
}
