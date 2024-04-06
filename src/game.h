#pragma once
#include "menu.h"
#include "optionsMenu.h"
#include "endMenu.h"
#include "board.h"
#include "player.h"
#include <SFML/Graphics.hpp>
#include <iostream>

/**
 * @brief Stan gry.
 *
 * Enumeracja okre�laj�ca r�ne stany gry, takie jak menu, opcje, ustawianie planszy, rozgrywka i zako�czenie gry.
 */
enum class GameState {
    MENU, /**< Stan menu. */
    OPTIONS, /**< Stan opcji. */
    SETUP, /**< Stan ustawiania planszy. */
    PLAY, /**< Stan rozgrywki. */
    END /**< Stan zako�czenia gry. */
};

/**
 * @brief Klasa reprezentuj�ca g��wny obiekt gry.
 *
 * Klasa ta zarz�dza g��wn� p�tl� gry, obs�uguje zdarzenia, renderuje obrazy i kontroluje przej�cia mi�dzy r�nymi stanami gry.
 */
class Game {
public:
    /**
     * @brief Konstruktor klasy Game.
     */
    Game();

    /**
     * @brief Uruchomienie gry.
     *
     * Metoda ta uruchamia g��wn� p�tl� gry, obs�uguj�c zdarzenia i renderuj�c obrazy.
     */
    void run();

private:
    /**
     * @brief Obs�uga zdarze� dla stanu menu.
     *
     * Obs�uguje zdarzenia klawiatury dla stanu menu, takie jak poruszanie si� po opcjach i akcja po naci�ni�ciu klawisza "Enter".
     *
     * @param event Zdarzenie SFML.
     */
    void handleMenuEvents(const sf::Event& event);

    /**
     * @brief Obs�uga zdarze� dla stanu opcji.
     *
     * Obs�uguje zdarzenia klawiatury dla stanu opcji, takie jak poruszanie si� po opcjach, zmiana rozdzielczo�ci i akcja po naci�ni�ciu klawisza "Enter".
     *
     * @param event Zdarzenie SFML.
     */
    void handleOptionsEvents(const sf::Event& event);

    /**
     * @brief Obs�uga zdarze� dla stanu ustawiania planszy.
     *
     * Obs�uguje zdarzenia klawiatury dla stanu ustawiania planszy, umo�liwiaj�c graczom ustawianie swoich statk�w.
     *
     * @param event Zdarzenie SFML.
     */
    void handlePlayEvents(const sf::Event& event);

    /**
     * @brief Obs�uga zdarze� dla stanu rozgrywki.
     *
     * Obs�uguje zdarzenia klawiatury dla stanu rozgrywki, takie jak strza�y graczy i sprawdzenie warunk�w zako�czenia gry.
     *
     * @param event Zdarzenie SFML.
     */
    void handleEndMenuEvents(const sf::Event& event);

    /**
     * @brief Obs�uga zdarze� dla stanu zako�czenia gry.
     *
     * Obs�uguje zdarzenia klawiatury dla stanu zako�czenia gry, takie jak poruszanie si� po menu zako�czenia i akcja po naci�ni�ciu klawisza "Enter".
     *
     * @param event Zdarzenie SFML.
     */
    void handleSetupEvents(const sf::Event& event);

    /**
     * @brief Przetwarzanie zdarze� SFML.
     *
     * Przetwarza og�lne zdarzenia SFML, rozr�niaj�c r�ne stany gry.
     */
    void processEvents();

    /**
     * @brief Renderowanie obrazu.
     *
     * Renderuje obraz gry, uwzgl�dniaj�c aktualny stan gry.
     */
    void render();

    /**
     * @brief Zmiana rozdzielczo�ci okna.
     *
     * Zmienia rozdzielczo�� okna gry na wybran� przez gracza z menu opcji.
     */
    void changeResolution();

    /**
     * @brief Prze��czanie trybu pe�noekranowego.
     *
     * Prze��cza tryb pe�noekranowy w zale�no�ci od wyboru gracza w menu opcji.
     */
    void toggleFullscreen();

    /**
    * @brief Aktualizacja interfejsu u�ytkownika zwi�zanej z rozdzielczo�ci�.
    *
    * Aktualizuje elementy interfejsu u�ytkownika (UI) w zale�no�ci od zmiany rozdzielczo�ci okna.
    */
    void updateUIForResolution();

    /**
     * @brief Sprawdzenie warunk�w zako�czenia gry.
     *
     * Sprawdza, czy spe�nione s� warunki zako�czenia gry, tj. zatopienie wszystkich statk�w jednego z graczy.
     */
    void checkEndGameCondition();

    sf::RenderWindow window; /**< Okno gry SFML. */
    sf::Font font; /**< Czcionka u�ywana w grze. */
    GameState gameState; /**< Aktualny stan gry. */
    Menu menu; /**< Menu gry. */
    OptionsMenu optionsMenu; /**< Menu opcji. */
    EndMenu endMenu; /**< Menu zako�czenia gry. */
    Player player1, player2; /**< Gracze. */
    Board board1, board2; /**< Plansze graczy. */
    sf::Vector2u originalResolution; /**< Pocz�tkowa rozdzielczo�� okna. */
    int currentPlayer = 1; /**< Numer aktualnego gracza. */
    bool settingUpPlayer1 = true; /**< Flaga ustawiania planszy dla gracza 1. */
};

