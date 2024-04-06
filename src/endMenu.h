#pragma once
#include "Menu.h"

/**
 * @brief Klasa reprezentuj�ca menu ko�cowe gry.
 *
 * Klasa dziedziczy po klasie Menu, zawiera informacje o zwyci�zcy gry oraz opcj� wyj�cia.
 */
class EndMenu : public Menu {
public:
    /**
     * @brief Konstruktor klasy EndMenu.
     *
     * @param width Szeroko�� okna gry.
     * @param height Wysoko�� okna gry.
     */
    EndMenu(float width, float height);

    /**
     * @brief Rysuj menu ko�cowe na oknie gry.
     *
     * Metoda implementuje rysowanie menu ko�cowego na oknie gry, wy�wietlaj�c informacje o zwyci�zcy
     * oraz opcj� wyj�cia.
     *
     * @param window Okno gry, na kt�rym rysowane jest menu ko�cowe.
     */
    void draw(sf::RenderWindow& window) override;

    /**
     * @brief Ustaw szczeg�y zwyci�zcy gry.
     *
     * Metoda ustawia informacje o zwyci�zcy gry, kt�re zostan� wy�wietlone w menu ko�cowym.
     *
     * @param winnerName Nazwa zwyci�zcy gry.
     */
    void setWinnerDetails(const std::string& winnerName);

    /**
     * @brief Pozycjonuj przycisk wyj�cia w menu ko�cowym.
     *
     * Metoda ustawia pozycj� przycisku wyj�cia w menu ko�cowym, tak aby by� odpowiednio umiejscowiony
     * pod informacjami o zwyci�zcy.
     */
    void positionExitButton();

private:
    sf::Text winnerDetails; /**< Tekst zawieraj�cy informacje o zwyci�zcy. */
    sf::Text menuItems[1]; /**< Tablica tekst�w dla przycisk�w menu". */
};