#pragma once
#include <iostream>
#include <vector>
#include <string>
#include <fstream>

class MoveLogger {
private:
	static int nextId;
	const int id;

	std::vector<std::string> moveHistory;

public:
	MoveLogger();
	~MoveLogger();

	void AddMove(const std::string& piece, const std::string& from, const std::string& to, const std::string& color);
	void AddMove(const std::string& fullMove);

	MoveLogger(const MoveLogger& other) = delete;
	MoveLogger& operator=(const MoveLogger& other) = delete;
};