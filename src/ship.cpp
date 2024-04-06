#include "Ship.h"

/**
 * @brief Konstruktor inicjalizuj�cy obiekt Ship.
 *
 * @param x Pocz�tkowa pozycja X statku.
 * @param y Pocz�tkowa pozycja Y statku.
 * @param len D�ugo�� statku.
 * @param vertical Okre�la, czy statek jest ustawiony pionowo (true) czy poziomo (false).
 */
Ship::Ship(unsigned int x, unsigned int y, unsigned int len, bool vertical)
    : startX(x), startY(y), length(len), isVertical(vertical), hits(0) {}


