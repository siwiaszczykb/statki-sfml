#include "Ship.h"

/**
 * @brief Konstruktor inicjalizujący obiekt Ship.
 *
 * @param x Początkowa pozycja X statku.
 * @param y Początkowa pozycja Y statku.
 * @param len Długość statku.
 * @param vertical Określa, czy statek jest ustawiony pionowo (true) czy poziomo (false).
 */
Ship::Ship(unsigned int x, unsigned int y, unsigned int len, bool vertical)
    : startX(x), startY(y), length(len), isVertical(vertical), hits(0) {}


