#pragma once

/**
 * @brief Klasa reprezentująca statek.
 */
class Ship {
public:
    /**
     * @brief Konstruktor inicjalizujący obiekt Ship.
     *
     * @param startX Początkowa pozycja X statku.
     * @param startY Początkowa pozycja Y statku.
     * @param length Długość statku.
     * @param isVertical Określa, czy statek jest ustawiony pionowo (true) czy poziomo (false).
     */
    Ship(unsigned int startX, unsigned int startY, unsigned int length, bool isVertical);

    //do dostepu do elementow planszy
    friend class Board;

private:
    /**
     * @brief Początkowa pozycja X statku.
     */
    unsigned int startX;

    /**
     * @brief Początkowa pozycja Y statku.
     */
    unsigned int startY;

    /**
     * @brief Długość statku.
     */
    unsigned int length;

    /**
     * @brief Określa, czy statek jest ustawiony pionowo (true) czy poziomo (false).
     */
    bool isVertical;

    /**
     * @brief Liczba trafień w statek.
     */
    unsigned int hits;
};
