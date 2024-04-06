#pragma once
#include <iostream>
#include <SFML/Graphics.hpp>

class Menu {
public:
    /**
     * @brief Konstruktor klasy Menu.
     *
     * @param width Szerokoœæ okna gry.
     * @param height Wysokoœæ okna gry.
     */
    Menu(float width, float height);

    /**
     * @brief Destruktor klasy Menu (domyœlny).
     */
    ~Menu() = default;

    /**
     * @brief Metoda rysuj¹ca menu na oknie.
     *
     * @param window Referencja do obiektu sf::RenderWindow, na którym rysowane jest menu.
     */
    virtual void draw(sf::RenderWindow& window);

    /**
     * @brief Metoda obs³uguj¹ca ruch w lewo w menu.
     */
    virtual void MoveLeft();

    /**
     * @brief Metoda obs³uguj¹ca ruch w prawo w menu.
     */
    virtual void MoveRight();

    /**
     * @brief Metoda obs³uguj¹ca ruch w górê w menu (pusta implementacja w bazowej klasie).
     */
    virtual void MoveUp() {};

    /**
     * @brief Metoda obs³uguj¹ca ruch w dó³ w menu (pusta implementacja w bazowej klasie).
     */
    virtual void MoveDown() {};

    /**
     * @brief Metoda zwracaj¹ca indeks wybranego elementu w menu.
     *
     * @return Indeks wybranego elementu w menu.
     */
    virtual int GetPressedItem() const;

    /**
     * @brief Metoda aktualizuj¹ca rozmiar menu z uwzglêdnieniem zmiany rozdzielczoœci okna.
     *
     * @param width Nowa szerokoœæ okna.
     * @param height Nowa wysokoœæ okna.
     */
    void updateMenuSize(float width, float height);
    sf::Text menu[3];

private:
    sf::Sprite logo;  ///< Sprite logo wyœwietlane w menu.
    sf::Texture logoTexture;  ///< Tekstura logo.

protected:
    sf::Font font;  ///< Obiekt czcionki u¿ywanej do tekstu w menu.
    float screenWidth;  ///< Szerokoœæ okna gry.
    float screenHeight;  ///< Wysokoœæ okna gry.
    int selectedItemIndex;  ///< Indeks aktualnie zaznaczonego elementu w menu.

    /**
     * @brief Metoda ustawiaj¹ca pozycje elementów menu na podstawie aktualnych rozmiarów okna.
     */
    virtual void positionMenuItems();
};