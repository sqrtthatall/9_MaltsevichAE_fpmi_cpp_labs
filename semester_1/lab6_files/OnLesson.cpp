#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <numeric>

bool IsEmptyFile(std::ifstream& file) {
	return file.peek() == std::ifstream::traits_type::eof();
}


std::vector<int32_t> ReadDataFromFile(const std::string& filename)
{
	std::ifstream in(filename);
	if (!in.is_open()) throw "Error: Could not open file";
	if (IsEmptyFile(in)) throw "Error: File is empty";
	
	std::vector<int32_t> numbers;
	int x;
	while (in >> x) {
		numbers.push_back(x);
	}
	in.close();
	return numbers;

}

void PrintVector(const std::vector<int32_t>& vec)
{
	for (size_t i = 0; i < vec.size(); ++i) {
		std::cout << vec[i] << " ";
	}
	std::cout << std::endl;
}

double CalculateAvg(const std::vector<int32_t>& numbers)
{

	int64_t sum = std::accumulate(numbers.begin(), numbers.end(), int64_t());
	return static_cast<double>(sum) / numbers.size();
}

void WriteAverageToFile(const std::string& filename, double avg) {
	std::ofstream out(filename);
	if (!out.is_open()) throw "Error: Could not open file";

	out << avg;
	out.close();
}

int main()
{
	const std::string input_file = "Input.txt";
	const std::string output_file = "Output.txt";

	try {
		std::vector<int32_t> numbers = ReadDataFromFile(input_file);
		std::cout << "----------------------\n";
		PrintVector(numbers);
		std::cout << "----------------------\n";
		double avg = CalculateAvg(numbers);
		WriteAverageToFile(output_file, avg);
		std::cout << "Result was saved to " << output_file;
	}
	catch (const std::string& msg) {
		std::cerr << msg << std::endl;
	}

	return 0;
}


