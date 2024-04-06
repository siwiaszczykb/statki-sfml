#pragma once
#include <iostream>
#include <SFML/Graphics.hpp>

class Menu {
public:
    /**
     * @brief Konstruktor klasy Menu.
     *
     * @param width Szeroko�� okna gry.
     * @param height Wysoko�� okna gry.
     */
    Menu(float width, float height);

    /**
     * @brief Destruktor klasy Menu (domy�lny).
     */
    ~Menu() = default;

    /**
     * @brief Metoda rysuj�ca menu na oknie.
     *
     * @param window Referencja do obiektu sf::RenderWindow, na kt�rym rysowane jest menu.
     */
    virtual void draw(sf::RenderWindow& window);

    /**
     * @brief Metoda obs�uguj�ca ruch w lewo w menu.
     */
    virtual void MoveLeft();

    /**
     * @brief Metoda obs�uguj�ca ruch w prawo w menu.
     */
    virtual void MoveRight();

    /**
     * @brief Metoda obs�uguj�ca ruch w g�r� w menu (pusta implementacja w bazowej klasie).
     */
    virtual void MoveUp() {};

    /**
     * @brief Metoda obs�uguj�ca ruch w d� w menu (pusta implementacja w bazowej klasie).
     */
    virtual void MoveDown() {};

    /**
     * @brief Metoda zwracaj�ca indeks wybranego elementu w menu.
     *
     * @return Indeks wybranego elementu w menu.
     */
    virtual int GetPressedItem() const;

    /**
     * @brief Metoda aktualizuj�ca rozmiar menu z uwzgl�dnieniem zmiany rozdzielczo�ci okna.
     *
     * @param width Nowa szeroko�� okna.
     * @param height Nowa wysoko�� okna.
     */
    void updateMenuSize(float width, float height);
    sf::Text menu[3];

private:
    sf::Sprite logo;  ///< Sprite logo wy�wietlane w menu.
    sf::Texture logoTexture;  ///< Tekstura logo.

protected:
    sf::Font font;  ///< Obiekt czcionki u�ywanej do tekstu w menu.
    float screenWidth;  ///< Szeroko�� okna gry.
    float screenHeight;  ///< Wysoko�� okna gry.
    int selectedItemIndex;  ///< Indeks aktualnie zaznaczonego elementu w menu.

    /**
     * @brief Metoda ustawiaj�ca pozycje element�w menu na podstawie aktualnych rozmiar�w okna.
     */
    virtual void positionMenuItems();
};