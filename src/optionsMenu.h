#pragma once
#include "menu.h"
#include "config.h"
#include <SFML/Graphics.hpp>
#include <iostream>
#include <vector>


/**
 * @brief Klasa reprezentująca menu opcji w grze.
 */
class OptionsMenu : public Menu {
public:
    /**
     * @brief Konstruktor klasy OptionsMenu.
     *
     * @param width Szerokość okna gry.
     * @param height Wysokość okna gry.
     */
    OptionsMenu(float width, float height);

    /**
     * @brief Destruktor klasy OptionsMenu (domyślny).
     */
    ~OptionsMenu() = default;

    /**
     * @brief Metoda zwracająca indeks wybranego elementu w menu opcji.
     *
     * @return Indeks wybranego elementu w menu opcji.
     */
    int GetPressedItem() const override;

    /**
     * @brief Metoda rysująca menu opcji na oknie.
     *
     * @param window Referencja do obiektu sf::RenderWindow, na którym rysowane jest menu opcji.
     */
    void draw(sf::RenderWindow& window) override;

    /**
     * @brief Metoda obsługująca ruch w górę w menu opcji.
     */
    void MoveUp() override;

    /**
     * @brief Metoda obsługująca ruch w dół w menu opcji.
     */
    void MoveDown() override;

    /**
     * @brief Metoda przełączająca tryb pełnoekranowy.
     */
    void toggleFullscreen();

    /**
     * @brief Metoda aktualizująca rozmiar i pozycję menu opcji po zmianie rozdzielczości okna.
     *
     * @param newWidth Nowa szerokość okna.
     * @param newHeight Nowa wysokość okna.
     */
    void updateSizeAndPosition(float newWidth, float newHeight);

    /**
     * @brief Metoda sprawdzająca, czy tryb pełnoekranowy jest włączony.
     *
     * @return Wartość logiczna informująca, czy tryb pełnoekranowy jest włączony.
     */
    bool isFullscreen() const;

    /**
     * @brief Metoda zwracająca wybraną rozdzielczość w menu opcji.
     *
     * @return Obiekt Resolution reprezentujący wybraną rozdzielczość.
     */
    Resolution getSelectedResolution() const;

private:
    sf::Font font;  ///< Obiekt czcionki używanej do tekstu w menu opcji.
    sf::Text menuItems[5];  ///< Tablica tekstów reprezentujących elementy menu opcji.
    int selectedItemIndex;  ///< Indeks aktualnie zaznaczonego elementu w menu opcji.
    int currentResolutionIndex;  ///< Indeks aktualnie wybranej rozdzielczości.
    float screenWidth, screenHeight;  ///< Szerokość i wysokość okna gry.
    bool isFullscreenEnabled;  ///< Flaga informująca, czy tryb pełnoekranowy jest włączony.

    /**
     * @brief Metoda ustawiająca pozycję elementów menu opcji na podstawie aktualnych rozmiarów okna.
     */
    void positionMenuItems();
    std::vector<Resolution> resolutions = { {800, 600}, {1280, 720},{1920, 1080} };

};
