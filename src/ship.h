#pragma once

/**
 * @brief Klasa reprezentuj¹ca statek.
 */
class Ship {
public:
    /**
     * @brief Konstruktor inicjalizuj¹cy obiekt Ship.
     *
     * @param startX Pocz¹tkowa pozycja X statku.
     * @param startY Pocz¹tkowa pozycja Y statku.
     * @param length D³ugoœæ statku.
     * @param isVertical Okreœla, czy statek jest ustawiony pionowo (true) czy poziomo (false).
     */
    Ship(unsigned int startX, unsigned int startY, unsigned int length, bool isVertical);

    //do dostepu do elementow planszy
    friend class Board;

private:
    /**
     * @brief Pocz¹tkowa pozycja X statku.
     */
    unsigned int startX;

    /**
     * @brief Pocz¹tkowa pozycja Y statku.
     */
    unsigned int startY;

    /**
     * @brief D³ugoœæ statku.
     */
    unsigned int length;

    /**
     * @brief Okreœla, czy statek jest ustawiony pionowo (true) czy poziomo (false).
     */
    bool isVertical;

    /**
     * @brief Liczba trafieñ w statek.
     */
    unsigned int hits;
};
