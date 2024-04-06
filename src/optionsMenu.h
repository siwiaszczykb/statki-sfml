#pragma once
#include "menu.h"
#include "config.h"
#include <SFML/Graphics.hpp>
#include <iostream>
#include <vector>


/**
 * @brief Klasa reprezentuj�ca menu opcji w grze.
 */
class OptionsMenu : public Menu {
public:
    /**
     * @brief Konstruktor klasy OptionsMenu.
     *
     * @param width Szeroko�� okna gry.
     * @param height Wysoko�� okna gry.
     */
    OptionsMenu(float width, float height);

    /**
     * @brief Destruktor klasy OptionsMenu (domy�lny).
     */
    ~OptionsMenu() = default;

    /**
     * @brief Metoda zwracaj�ca indeks wybranego elementu w menu opcji.
     *
     * @return Indeks wybranego elementu w menu opcji.
     */
    int GetPressedItem() const override;

    /**
     * @brief Metoda rysuj�ca menu opcji na oknie.
     *
     * @param window Referencja do obiektu sf::RenderWindow, na kt�rym rysowane jest menu opcji.
     */
    void draw(sf::RenderWindow& window) override;

    /**
     * @brief Metoda obs�uguj�ca ruch w g�r� w menu opcji.
     */
    void MoveUp() override;

    /**
     * @brief Metoda obs�uguj�ca ruch w d� w menu opcji.
     */
    void MoveDown() override;

    /**
     * @brief Metoda prze��czaj�ca tryb pe�noekranowy.
     */
    void toggleFullscreen();

    /**
     * @brief Metoda aktualizuj�ca rozmiar i pozycj� menu opcji po zmianie rozdzielczo�ci okna.
     *
     * @param newWidth Nowa szeroko�� okna.
     * @param newHeight Nowa wysoko�� okna.
     */
    void updateSizeAndPosition(float newWidth, float newHeight);

    /**
     * @brief Metoda sprawdzaj�ca, czy tryb pe�noekranowy jest w��czony.
     *
     * @return Warto�� logiczna informuj�ca, czy tryb pe�noekranowy jest w��czony.
     */
    bool isFullscreen() const;

    /**
     * @brief Metoda zwracaj�ca wybran� rozdzielczo�� w menu opcji.
     *
     * @return Obiekt Resolution reprezentuj�cy wybran� rozdzielczo��.
     */
    Resolution getSelectedResolution() const;

private:
    sf::Font font;  ///< Obiekt czcionki u�ywanej do tekstu w menu opcji.
    sf::Text menuItems[5];  ///< Tablica tekst�w reprezentuj�cych elementy menu opcji.
    int selectedItemIndex;  ///< Indeks aktualnie zaznaczonego elementu w menu opcji.
    int currentResolutionIndex;  ///< Indeks aktualnie wybranej rozdzielczo�ci.
    float screenWidth, screenHeight;  ///< Szeroko�� i wysoko�� okna gry.
    bool isFullscreenEnabled;  ///< Flaga informuj�ca, czy tryb pe�noekranowy jest w��czony.

    /**
     * @brief Metoda ustawiaj�ca pozycj� element�w menu opcji na podstawie aktualnych rozmiar�w okna.
     */
    void positionMenuItems();
    std::vector<Resolution> resolutions = { {800, 600}, {1280, 720},{1920, 1080} };

};
