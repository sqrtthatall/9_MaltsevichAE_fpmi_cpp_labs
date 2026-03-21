#include "ChessPiece.h"
#include "Logger.h"

MoveLogger ChessPiece::globalLog;

ChessPiece::ChessPiece(int x, int y, Color c)
    : currentX(x), currentY(y), color(c) {
}

ChessPiece::ChessPiece(const ChessPiece& other)
    : ChessPiece(other.currentX, other.currentY, other.color) {
}

void ChessPiece::Log(uint16_t x, uint16_t y) const {
    std::string from = std::string(1, Desk[currentX]) + std::to_string(currentY);
    std::string to = std::string(1, Desk[x]) + std::to_string(y);
    globalLog.AddMove(GetPieceSymbol(), from, to, enumToString(color));
}


Bishop::Bishop(int x, int y, Color c) :
    ChessPiece(x, y, c) {
};

void Bishop::getInfo() const {
    std::cout << 'B' << Desk[currentX] << currentY << std::endl;
}
bool Bishop::CanMove(uint16_t x, uint16_t y) const {
    if ((abs(x - currentX) == abs(y - currentY)) && isOnBoard(x, y)) return true;
    return false;
}
void Bishop::Move(uint16_t x, uint16_t y) {
    if (this->CanMove(x, y) == true) {
        currentX = x;
        currentY = y;
        Log(x, y);
    }
    else {
        throw std::invalid_argument("Error: can't move Bishop like this!");
    }
}

Rook::Rook(int x, int y, Color c) :
    ChessPiece(x, y, c) {
};

bool Rook::CanMove(uint16_t x, uint16_t y) const {
    if ((x == currentX || y == currentY) && isOnBoard(x, y)) return true;
    return false;
}
void Rook::getInfo() const {
    std::cout << 'R' << Desk[currentX] << currentY << std::endl;
}
void Rook::Move(uint16_t x, uint16_t y) {
    if (this->CanMove(x, y) == true) {
        currentX = x;
        currentY = y;
        Log(x, y);
    }
    else {
        throw std::invalid_argument("Error: can't move Rook like this!");
    }
}

Queen::Queen(int x, int y, Color c) :
    ChessPiece(x, y, c), Bishop(x, y, c), Rook(x, y, c) {
};

bool Queen::CanMove(uint16_t x, uint16_t y) const {
    if ((Bishop::CanMove(x, y) || Rook::CanMove(x, y)) && (isOnBoard(x, y)) == true) {
        return true;
    }
    else {
        return false;
    }
}

void Queen::getInfo() const {
    std::cout << "Q" << Desk[currentX] << currentY << std::endl;
}

void Queen::Move(uint16_t x, uint16_t y) {
    if (this->CanMove(x, y) == true) {
        currentX = x;
        currentY = y;
        Log(x, y);
    }
    else {
        throw std::invalid_argument("Error: can't move Queen like this!");
    }
}



int main()
{
    Bishop b(2, 2, Color::White);

    Rook r(5, 4, Color::Black);

    Queen q(4, 5, Color::White);

    try {
        r.getInfo();
        q.getInfo();
        q.Move(1, 2);
        q.Move(3, 4);
        b.getInfo();
    }
    catch (std::exception& e) {
        std::cerr << e.what();
    }

}


