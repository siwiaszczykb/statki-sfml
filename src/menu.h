#pragma once
#include <iostream>
#include <SFML/Graphics.hpp>

class Menu {
public:
    /**
     * @brief Konstruktor klasy Menu.
     *
     * @param width Szerokość okna gry.
     * @param height Wysokość okna gry.
     */
    Menu(float width, float height);

    /**
     * @brief Destruktor klasy Menu (domyślny).
     */
    ~Menu() = default;

    /**
     * @brief Metoda rysująca menu na oknie.
     *
     * @param window Referencja do obiektu sf::RenderWindow, na którym rysowane jest menu.
     */
    virtual void draw(sf::RenderWindow& window);

    /**
     * @brief Metoda obsługująca ruch w lewo w menu.
     */
    virtual void MoveLeft();

    /**
     * @brief Metoda obsługująca ruch w prawo w menu.
     */
    virtual void MoveRight();

    /**
     * @brief Metoda obsługująca ruch w górę w menu (pusta implementacja w bazowej klasie).
     */
    virtual void MoveUp() {};

    /**
     * @brief Metoda obsługująca ruch w dół w menu (pusta implementacja w bazowej klasie).
     */
    virtual void MoveDown() {};

    /**
     * @brief Metoda zwracająca indeks wybranego elementu w menu.
     *
     * @return Indeks wybranego elementu w menu.
     */
    virtual int GetPressedItem() const;

    /**
     * @brief Metoda aktualizująca rozmiar menu z uwzględnieniem zmiany rozdzielczości okna.
     *
     * @param width Nowa szerokość okna.
     * @param height Nowa wysokość okna.
     */
    void updateMenuSize(float width, float height);
    sf::Text menu[3];

private:
    sf::Sprite logo;  ///< Sprite logo wyświetlane w menu.
    sf::Texture logoTexture;  ///< Tekstura logo.

protected:
    sf::Font font;  ///< Obiekt czcionki używanej do tekstu w menu.
    float screenWidth;  ///< Szerokość okna gry.
    float screenHeight;  ///< Wysokość okna gry.
    int selectedItemIndex;  ///< Indeks aktualnie zaznaczonego elementu w menu.

    /**
     * @brief Metoda ustawiająca pozycje elementów menu na podstawie aktualnych rozmiarów okna.
     */
    virtual void positionMenuItems();
};