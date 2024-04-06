#pragma once
#include "Menu.h"

/**
 * @brief Klasa reprezentuj¹ca menu koñcowe gry.
 *
 * Klasa dziedziczy po klasie Menu, zawiera informacje o zwyciêzcy gry oraz opcjê wyjœcia.
 */
class EndMenu : public Menu {
public:
    /**
     * @brief Konstruktor klasy EndMenu.
     *
     * @param width Szerokoœæ okna gry.
     * @param height Wysokoœæ okna gry.
     */
    EndMenu(float width, float height);

    /**
     * @brief Rysuj menu koñcowe na oknie gry.
     *
     * Metoda implementuje rysowanie menu koñcowego na oknie gry, wyœwietlaj¹c informacje o zwyciêzcy
     * oraz opcjê wyjœcia.
     *
     * @param window Okno gry, na którym rysowane jest menu koñcowe.
     */
    void draw(sf::RenderWindow& window) override;

    /**
     * @brief Ustaw szczegó³y zwyciêzcy gry.
     *
     * Metoda ustawia informacje o zwyciêzcy gry, które zostan¹ wyœwietlone w menu koñcowym.
     *
     * @param winnerName Nazwa zwyciêzcy gry.
     */
    void setWinnerDetails(const std::string& winnerName);

    /**
     * @brief Pozycjonuj przycisk wyjœcia w menu koñcowym.
     *
     * Metoda ustawia pozycjê przycisku wyjœcia w menu koñcowym, tak aby by³ odpowiednio umiejscowiony
     * pod informacjami o zwyciêzcy.
     */
    void positionExitButton();

private:
    sf::Text winnerDetails; /**< Tekst zawieraj¹cy informacje o zwyciêzcy. */
    sf::Text menuItems[1]; /**< Tablica tekstów dla przycisków menu". */
};