#pragma once
#include "menu.h"
#include "config.h"
#include <SFML/Graphics.hpp>
#include <iostream>
#include <vector>


/**
 * @brief Klasa reprezentuj¹ca menu opcji w grze.
 */
class OptionsMenu : public Menu {
public:
    /**
     * @brief Konstruktor klasy OptionsMenu.
     *
     * @param width Szerokoœæ okna gry.
     * @param height Wysokoœæ okna gry.
     */
    OptionsMenu(float width, float height);

    /**
     * @brief Destruktor klasy OptionsMenu (domyœlny).
     */
    ~OptionsMenu() = default;

    /**
     * @brief Metoda zwracaj¹ca indeks wybranego elementu w menu opcji.
     *
     * @return Indeks wybranego elementu w menu opcji.
     */
    int GetPressedItem() const override;

    /**
     * @brief Metoda rysuj¹ca menu opcji na oknie.
     *
     * @param window Referencja do obiektu sf::RenderWindow, na którym rysowane jest menu opcji.
     */
    void draw(sf::RenderWindow& window) override;

    /**
     * @brief Metoda obs³uguj¹ca ruch w górê w menu opcji.
     */
    void MoveUp() override;

    /**
     * @brief Metoda obs³uguj¹ca ruch w dó³ w menu opcji.
     */
    void MoveDown() override;

    /**
     * @brief Metoda prze³¹czaj¹ca tryb pe³noekranowy.
     */
    void toggleFullscreen();

    /**
     * @brief Metoda aktualizuj¹ca rozmiar i pozycjê menu opcji po zmianie rozdzielczoœci okna.
     *
     * @param newWidth Nowa szerokoœæ okna.
     * @param newHeight Nowa wysokoœæ okna.
     */
    void updateSizeAndPosition(float newWidth, float newHeight);

    /**
     * @brief Metoda sprawdzaj¹ca, czy tryb pe³noekranowy jest w³¹czony.
     *
     * @return Wartoœæ logiczna informuj¹ca, czy tryb pe³noekranowy jest w³¹czony.
     */
    bool isFullscreen() const;

    /**
     * @brief Metoda zwracaj¹ca wybran¹ rozdzielczoœæ w menu opcji.
     *
     * @return Obiekt Resolution reprezentuj¹cy wybran¹ rozdzielczoœæ.
     */
    Resolution getSelectedResolution() const;

private:
    sf::Font font;  ///< Obiekt czcionki u¿ywanej do tekstu w menu opcji.
    sf::Text menuItems[5];  ///< Tablica tekstów reprezentuj¹cych elementy menu opcji.
    int selectedItemIndex;  ///< Indeks aktualnie zaznaczonego elementu w menu opcji.
    int currentResolutionIndex;  ///< Indeks aktualnie wybranej rozdzielczoœci.
    float screenWidth, screenHeight;  ///< Szerokoœæ i wysokoœæ okna gry.
    bool isFullscreenEnabled;  ///< Flaga informuj¹ca, czy tryb pe³noekranowy jest w³¹czony.

    /**
     * @brief Metoda ustawiaj¹ca pozycjê elementów menu opcji na podstawie aktualnych rozmiarów okna.
     */
    void positionMenuItems();
    std::vector<Resolution> resolutions = { {800, 600}, {1280, 720},{1920, 1080} };

};
