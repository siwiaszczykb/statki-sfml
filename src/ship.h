#pragma once

/**
 * @brief Klasa reprezentuj�ca statek.
 */
class Ship {
public:
    /**
     * @brief Konstruktor inicjalizuj�cy obiekt Ship.
     *
     * @param startX Pocz�tkowa pozycja X statku.
     * @param startY Pocz�tkowa pozycja Y statku.
     * @param length D�ugo�� statku.
     * @param isVertical Okre�la, czy statek jest ustawiony pionowo (true) czy poziomo (false).
     */
    Ship(unsigned int startX, unsigned int startY, unsigned int length, bool isVertical);

    //do dostepu do elementow planszy
    friend class Board;

private:
    /**
     * @brief Pocz�tkowa pozycja X statku.
     */
    unsigned int startX;

    /**
     * @brief Pocz�tkowa pozycja Y statku.
     */
    unsigned int startY;

    /**
     * @brief D�ugo�� statku.
     */
    unsigned int length;

    /**
     * @brief Okre�la, czy statek jest ustawiony pionowo (true) czy poziomo (false).
     */
    bool isVertical;

    /**
     * @brief Liczba trafie� w statek.
     */
    unsigned int hits;
};
