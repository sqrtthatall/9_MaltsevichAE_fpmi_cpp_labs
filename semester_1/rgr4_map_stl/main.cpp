#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <map>

struct Mark {
    std::string subject; 
    size_t mark_;        
};

struct StudentData {
    std::string name;        
    size_t number;            
    std::vector<Mark> marks_; 

    double getAverage() const {
        if (marks_.empty()) return 0;
        double sum = 0;
        for (const auto& m : marks_) sum += m.mark_;
        return sum / marks_.size();
    }

    size_t getSum() const {
        size_t sum = 0;
        for (const auto& m : marks_) sum += m.mark_;
        return sum;
    }

    bool hasBadMarks() const {
        for (const auto& m : marks_) {
            if (m.mark_ <= 3) return true;
        }
        return false;
    }
};

int main() {

    return 0;
}
