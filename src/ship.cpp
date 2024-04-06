#include "Ship.h"

/**
 * @brief Konstruktor inicjalizuj¹cy obiekt Ship.
 *
 * @param x Pocz¹tkowa pozycja X statku.
 * @param y Pocz¹tkowa pozycja Y statku.
 * @param len D³ugoœæ statku.
 * @param vertical Okreœla, czy statek jest ustawiony pionowo (true) czy poziomo (false).
 */
Ship::Ship(unsigned int x, unsigned int y, unsigned int len, bool vertical)
    : startX(x), startY(y), length(len), isVertical(vertical), hits(0) {}


