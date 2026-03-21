#pragma once
#include <iostream>
#include <map>
#include <vector>
#include <string>

class MoveLogger;

std::map<int, char> Desk = { {1, 'a'}, {2, 'b'}, {3, 'c'},{4, 'd'}, {5, 'e'}, {6, 'f'}, {7, 'g'}, {8, 'h'} };

enum class Color { White, Black };

class ChessPiece {
protected:
	int currentX;
	int currentY;
	Color color;
	bool isOnBoard(uint16_t x, uint16_t y) const {
		return (x >= 1 && x <= 8 && y >= 1 && y <= 8);
	}
	static MoveLogger globalLog;

public:
	ChessPiece(int x, int y, Color c);
	ChessPiece(const ChessPiece& other);
	virtual ~ChessPiece() = default;

	virtual void getInfo()const = 0;

	virtual bool CanMove(uint16_t x, uint16_t y) const = 0;

	virtual void Move(uint16_t x, uint16_t y) = 0;
	void Log(uint16_t x, uint16_t y) const;
	virtual std::string GetPieceSymbol() const = 0;
};

class Bishop : virtual public ChessPiece {
public:
	Bishop(int x, int y, Color c);
	void getInfo()const override;
	bool CanMove(uint16_t x, uint16_t y)const override;
	void Move(uint16_t x, uint16_t y)override;
	std::string GetPieceSymbol() const override { return "B"; }
};

class Rook : virtual public ChessPiece {
public:
	Rook(int x, int y, Color c);
	void getInfo()const override;
	bool CanMove(uint16_t x, uint16_t y)const override;
	void Move(uint16_t x, uint16_t y)override;
	std::string GetPieceSymbol() const override { return "R"; }
};

class Queen : public Bishop, public Rook {
public:
	Queen(int x, int y, Color c);
	void getInfo()const override;
	bool CanMove(uint16_t x, uint16_t y)const override;
	void Move(uint16_t x, uint16_t y)override;
	std::string GetPieceSymbol() const override { return "Q"; }
};

std::string enumToString(Color c) {
	if (c == Color::White) return "White";
	if (c == Color::Black) return "Black";
}