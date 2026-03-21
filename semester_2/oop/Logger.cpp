#include "Logger.h"
#include <fstream>

int MoveLogger::nextId = 1;

MoveLogger::MoveLogger() : id(nextId++){}

MoveLogger::~MoveLogger() {
	std::ofstream outputLogs("game_" + std::to_string(id) + "_log.txt");

	if (!outputLogs.is_open()) { std::cerr << "Error: could not to create file"; return; }

	for (size_t i = 0; i < moveHistory.size(); ++i) {
		outputLogs << i + 1 << ". " << moveHistory[i] << std::endl;
		std::cout << i << "Log saved!" << std::endl;
	}
	outputLogs.close();
}

void MoveLogger::AddMove(const std::string& piece, const std::string& from, const std::string& to, const std::string& color) {
	moveHistory.push_back(color + ": " + piece + from + " - " + to);
}

void MoveLogger::AddMove(const std::string& fullMove) {
	moveHistory.push_back(fullMove);
}