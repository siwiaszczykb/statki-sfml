#include "board.h"

//konstruktor domyslny - wypelnia kropkami
Board::Board() {    
    width = boardSize.width;
    height = boardSize.height;
    boardArray = new char* [height];
    for (unsigned int i = 0; i < height; ++i) {
        boardArray[i] = new char[width];
        std::fill(boardArray[i], boardArray[i] + width, '.'); 
    }
}

//destruktor usuwajacy array z plansza
Board::~Board() {
    for (unsigned int i = 0; i < height; ++i) {
        delete[] boardArray[i];
    }
    delete[] boardArray;
}

//postaw statek, z warunkami czy sie miesci i czy jest poziomy/pionowy
bool Board::placeShip(unsigned int startX, unsigned int startY, unsigned int shipLength, bool isVertical) {
    if (isVertical) {
        if (startY + shipLength > height) return false;
        for (unsigned int i = startY; i < startY + shipLength; i++) {
            if (!isCellAvailable(i, startX)) return false;
        }
        for (unsigned int i = startY; i < startY + shipLength; i++) {
            boardArray[i][startX] = 'S';
        }
    }
    else {
        if (startX + shipLength > width) return false;
        for (unsigned int i = startX; i < startX + shipLength; i++) {
            if (!isCellAvailable(startY, i)) return false;
        }
        for (unsigned int i = startX; i < startX + shipLength; i++) {
            boardArray[startY][i] = 'S';
        }
    }
    return true;
}

//czy komorka i komorka obok sa dostepne
bool Board::isCellAvailable(unsigned int y, unsigned int x) const {
    if (boardArray[y][x] != '.') return false;
    for (int dy = -1; dy <= 1; dy++) {
        for (int dx = -1; dx <= 1; dx++) {
            int checkY = y + dy;
            int checkX = x + dx;
            if (checkY >= 0 && checkY < height && checkX >= 0 && checkX < width) {
                if (boardArray[checkY][checkX] == 'S') return false;
            }
        }
    }
    return true;
}

//strzel i zmien w arrayu
bool Board::shootAt(unsigned int x, unsigned int y) {
    if (x >= width || y >= height) return false;

    if (boardArray[y][x] == 'S') {
        boardArray[y][x] = 'X'; 
        return true;
    }
    else if (boardArray[y][x] == '.') {
        boardArray[y][x] = 'M'; 
    }
    return false;
}

//bool czy statek zatopiony
bool Board::isShipSunk(unsigned int x, unsigned int y) {
    for (auto& ship : ships) {
        if (ship.isVertical) {
            if (x == ship.startX && y >= ship.startY && y < ship.startY + ship.length) {
                return ship.hits == ship.length;  
            }
        }
        else {
            if (y == ship.startY && x >= ship.startX && x < ship.startX + ship.length) {
                return ship.hits == ship.length;
            }
        }
    }
    return false;  
}

//bool czy zatopione wszystkie statki, jezeli brak s w planszy
bool Board::areAllShipsSunk() {
    for (unsigned int i = 0; i < height; ++i) {
        for (unsigned int j = 0; j < width; ++j) {
            if (boardArray[i][j] == 'S') {
                return false; 
            }
        }
    }
    return true; 
}

//zwroc wartosc komorki dla x i y
char Board::getCellValue(unsigned int x, unsigned int y) const {
    if (x < width && y < height) {
        return boardArray[y][x];
    }
    return ' '; 
}

//getter szerokosci planszy
unsigned int Board::getWidth() const {
    return width;
}

//getter wysokosci planszy
unsigned int Board::getHeight() const {
    return height;
}