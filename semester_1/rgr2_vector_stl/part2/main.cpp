#include "time_utility.h"
#include "train.h"

#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <iomanip>

std::string TrainTypeToString(TrainType type) {
    if (type == TrainType::PASSENGER) {
        return "Passenger";
    } 
    else if (type == TrainType::FREIGHT) {
        return "Freight";
    } 
    else if (type == TrainType::HIGH_SPEED) {
        return "High speed";
    } 
    else if (type == TrainType::SUBWAY) {
        return "Subway";
    } 
    else if (type == TrainType::SPECIALIZED) {
        return "Specialized";
    } 
    else {
        return "UnknownTypeOfTrain";
    }
}

//Функцию снизу писала нейронка (Хотел сделать вывод еще более красивым)
std::string FormatTimeHHMM(std::time_t t) {
    std::tm* tm_info = std::localtime(&t);
    if (!tm_info) {
        return "??:??"; // на случай ошибки (маловероятно)
    }

    std::ostringstream oss;
    oss << std::setfill('0')
        << std::setw(2) << tm_info->tm_hour << ":"
        << std::setw(2) << tm_info->tm_min;
    return oss.str();
}

void PrintTrainInfo(const Train& train) {
    std::string id_str_for_print = std::to_string(train.GetTrainId());
    std::string type_str_for_print = TrainTypeToString(train.GetTrainType());
    
    std::cout << " | ID: " << id_str_for_print << " | " << type_str_for_print << " | "
        << train.GetDestination() << " | " << FormatTimeHHMM(train.GetDispatchTime()) << " | " << FormatTimeHHMM(train.GetTravellingTime()) << " | \n";
}

std::time_t ParsingTime(const std::string& time) {
    if (time.length() != 5 || (!(time[2] == ':'))) {
        throw "Invalid time!";
    }
    if (!std::isdigit(static_cast<unsigned char>(time[0])) ||
        !std::isdigit(static_cast<unsigned char>(time[1]))) {
        throw "Invalid hour!";
    }
    if (!std::isdigit(static_cast<unsigned char>(time[3])) ||
        !std::isdigit(static_cast<unsigned char>(time[4]))) {
        throw "Invalid minute!";
    }
    std::string hour = time.substr(0, 2);
    std::string minute = time.substr(3);

    int hour_int = std::stoi(hour);
    int minute_int = std::stoi(minute);

    size_t finaly_h = static_cast<size_t>(hour_int);
    size_t finaly_m = static_cast<size_t>(minute_int);

    std::time_t result = SetTime(finaly_h, finaly_m);
    return result;
}

Train Parsing_TXT(const std::string& train_info) {
    std::string id_str;
    std::string type_str;
    std::string destination_str;
    std::string dispatch_time_str;
    std::string travelling_time_str;
    std::string try_to_find_mistake;

    std::istringstream ss(train_info);
    std::getline(ss, id_str, '/');
    std::getline(ss, type_str, '/'); 
    std::getline(ss, destination_str, '/');
    std::getline(ss, dispatch_time_str, '/'); 
    std::getline(ss, travelling_time_str, '/');

    if (std::getline(ss, try_to_find_mistake, '/')) {
        throw "More than 5 params in line! Check and rewrite input.txt";
    }
    
    size_t id = static_cast<size_t>(std::stoul(id_str));
    
    time_t dispatch_time = ParsingTime(dispatch_time_str);
    time_t travelling_time = ParsingTime(travelling_time_str);

    if (type_str == "PASSENGER") {
        return Train(id, TrainType::PASSENGER, destination_str, dispatch_time, travelling_time);
    } 
    else if (type_str == "FREIGHT") {
        return Train(id, TrainType::FREIGHT, destination_str, dispatch_time, travelling_time);
    } 
    else if (type_str == "HIGH_SPEED") {
        return Train(id, TrainType::HIGH_SPEED, destination_str, dispatch_time, travelling_time);
    } 
    else if (type_str == "SUBWAY") {
        return Train(id, TrainType::SUBWAY, destination_str, dispatch_time, travelling_time);
    } 
    else if (type_str == "SPECIALIZED"){
        return Train(id, TrainType::SPECIALIZED, destination_str, dispatch_time, travelling_time);
    } 
    else {
        throw "Invalid type of train, please check input.txt";
    }

}

std::vector<Train> ParsingIntoVector(std::ifstream& fin) {
    std::string line;
    std::vector<Train> result;
    while (std::getline(fin, line)) {
        if (line.empty())
            continue;
        result.push_back(Parsing_TXT(line));
    }
    return result;
}

void SortTrainVector(std::vector<Train>& vec) {
    std::sort(vec.begin(), vec.end(), [](const Train& a, const Train& b) {
        return a.GetDispatchTime() < b.GetDispatchTime();
    });
}

void PrintTrainsAtTimeGiven(const std::vector<Train>& vec, std::time_t start, std::time_t end) {
    std::for_each(vec.begin(), vec.end(), [start, end](const Train& train) {
        std::time_t dispatch = train.GetDispatchTime();
        if (dispatch >= start && dispatch <= end) {
            PrintTrainInfo(train);
        }
    });
}

void PrintTrainsInDestinationGiven(const std::vector<Train>& vec, const std::string& destination) {
    std::for_each(vec.begin(), vec.end(), [destination](const Train& train) {
        if (destination == train.GetDestination())
            PrintTrainInfo(train);
        });
}

void PrintTrainsSameTypeAndDestanationGiven(const std::vector<Train>& vec, const std::string& destination,
                                            TrainType type) {
    std::for_each(vec.begin(), vec.end(), [destination, type](const Train& train) {
        if (destination == train.GetDestination() && type == train.GetTrainType())
            PrintTrainInfo(train);
    });
}



void PrintTheFastestTrainToDestanation(const std::vector<Train>& vec,
                                       const std::string& destination) {
    std::vector<Train> TrainsWeNeed;
    for (size_t i = 0; i < vec.size(); i++) {
        if (vec[i].GetDestination() == destination) {
            TrainsWeNeed.push_back(vec[i]);
        }
    }
    if (TrainsWeNeed.size() == 0) {
        std::cout << "No trains to this destination :(\n";
    } 
    else {
        Train train = *std::min_element(TrainsWeNeed.begin(), TrainsWeNeed.end(),
                         [](const Train& a, const Train& b) {
                             return a.GetTravellingTime() < b.GetTravellingTime();
                         });
        PrintTrainInfo(train);
    }
}

int main() {

    using namespace time_utility;

    std::random_device rd;
    std::mt19937 generator(rd());

    std::time_t t1 = SetTime(12, 23);
    try {
        t1 = SetTime(12, 60);
    } catch (const std::out_of_range& err) {
        std::cerr << err.what() << std::endl;
    }

    std::time_t t2 = GenerateRandomTime(generator);

    std::cout << "t1: ";
    PrintTime(t1);
    
    std::cout << "t2: ";
    PrintTime(t2);
    
    std::cout << "t1 < t2: " << std::boolalpha << (t1 < t2) <<'\n';
    std::cout << "t2 < t1: " << std::boolalpha << (t2 < t1) << '\n';








    //-=-=-=-=-=-=-=-=-=-==-=-=-=-=-Mine=-==-=Part=-=-=-=-=-=

    std::cout << "\n \n \n \n";

    std::ifstream fin("input.txt");
    
    if (!fin.is_open()) {
        std::cout << "Can't open the file input.txt" << std::endl;
        return EXIT_FAILURE;
    }

    std::vector<Train> Trains;
    try {
        Trains = ParsingIntoVector(fin);
        SortTrainVector(Trains);
        
        std::cout << "=====...Sorted trains...=====\n";
        for (size_t i = 0; i < Trains.size(); i++) {
            PrintTrainInfo(Trains[i]);
        }


        std::time_t start = SetTime(12, 30);
        std::time_t end = SetTime(18, 45);

        std::cout << "\n=====...Trains at the " << FormatTimeHHMM(start) << " To " << FormatTimeHHMM(end) <<  " ...=====\n";
        PrintTrainsAtTimeGiven(Trains, start, end);







        std::string d1 = "Moscow";
        std::cout << "\n=====...Trains goes to " << d1 << " ...=====\n";
        PrintTrainsInDestinationGiven(Trains, d1);

        TrainType tt = TrainType::HIGH_SPEED;
        std::string d2 = "Minsk";
        std::cout << "\n=====..." << TrainTypeToString(tt) << " Train which goes to " << d2 << "...=====\n";
        PrintTrainsSameTypeAndDestanationGiven(Trains, d2, tt);

        std::string d3 = "Brest";
        std::cout << "\nFastes train to " << d3 << '\n';
        PrintTheFastestTrainToDestanation(Trains, d3);



    }
    catch (const char* msg) {
        std::cerr << "Error: " << msg << std::endl;
        return EXIT_FAILURE;
    }
    
    return EXIT_SUCCESS;
}
