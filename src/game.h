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
 * Enumeracja okreœlaj¹ca ró¿ne stany gry, takie jak menu, opcje, ustawianie planszy, rozgrywka i zakoñczenie gry.
 */
enum class GameState {
    MENU, /**< Stan menu. */
    OPTIONS, /**< Stan opcji. */
    SETUP, /**< Stan ustawiania planszy. */
    PLAY, /**< Stan rozgrywki. */
    END /**< Stan zakoñczenia gry. */
};

/**
 * @brief Klasa reprezentuj¹ca g³ówny obiekt gry.
 *
 * Klasa ta zarz¹dza g³ówn¹ pêtl¹ gry, obs³uguje zdarzenia, renderuje obrazy i kontroluje przejœcia miêdzy ró¿nymi stanami gry.
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
     * Metoda ta uruchamia g³ówn¹ pêtlê gry, obs³uguj¹c zdarzenia i renderuj¹c obrazy.
     */
    void run();

private:
    /**
     * @brief Obs³uga zdarzeñ dla stanu menu.
     *
     * Obs³uguje zdarzenia klawiatury dla stanu menu, takie jak poruszanie siê po opcjach i akcja po naciœniêciu klawisza "Enter".
     *
     * @param event Zdarzenie SFML.
     */
    void handleMenuEvents(const sf::Event& event);

    /**
     * @brief Obs³uga zdarzeñ dla stanu opcji.
     *
     * Obs³uguje zdarzenia klawiatury dla stanu opcji, takie jak poruszanie siê po opcjach, zmiana rozdzielczoœci i akcja po naciœniêciu klawisza "Enter".
     *
     * @param event Zdarzenie SFML.
     */
    void handleOptionsEvents(const sf::Event& event);

    /**
     * @brief Obs³uga zdarzeñ dla stanu ustawiania planszy.
     *
     * Obs³uguje zdarzenia klawiatury dla stanu ustawiania planszy, umo¿liwiaj¹c graczom ustawianie swoich statków.
     *
     * @param event Zdarzenie SFML.
     */
    void handlePlayEvents(const sf::Event& event);

    /**
     * @brief Obs³uga zdarzeñ dla stanu rozgrywki.
     *
     * Obs³uguje zdarzenia klawiatury dla stanu rozgrywki, takie jak strza³y graczy i sprawdzenie warunków zakoñczenia gry.
     *
     * @param event Zdarzenie SFML.
     */
    void handleEndMenuEvents(const sf::Event& event);

    /**
     * @brief Obs³uga zdarzeñ dla stanu zakoñczenia gry.
     *
     * Obs³uguje zdarzenia klawiatury dla stanu zakoñczenia gry, takie jak poruszanie siê po menu zakoñczenia i akcja po naciœniêciu klawisza "Enter".
     *
     * @param event Zdarzenie SFML.
     */
    void handleSetupEvents(const sf::Event& event);

    /**
     * @brief Przetwarzanie zdarzeñ SFML.
     *
     * Przetwarza ogólne zdarzenia SFML, rozró¿niaj¹c ró¿ne stany gry.
     */
    void processEvents();

    /**
     * @brief Renderowanie obrazu.
     *
     * Renderuje obraz gry, uwzglêdniaj¹c aktualny stan gry.
     */
    void render();

    /**
     * @brief Zmiana rozdzielczoœci okna.
     *
     * Zmienia rozdzielczoœæ okna gry na wybran¹ przez gracza z menu opcji.
     */
    void changeResolution();

    /**
     * @brief Prze³¹czanie trybu pe³noekranowego.
     *
     * Prze³¹cza tryb pe³noekranowy w zale¿noœci od wyboru gracza w menu opcji.
     */
    void toggleFullscreen();

    /**
    * @brief Aktualizacja interfejsu u¿ytkownika zwi¹zanej z rozdzielczoœci¹.
    *
    * Aktualizuje elementy interfejsu u¿ytkownika (UI) w zale¿noœci od zmiany rozdzielczoœci okna.
    */
    void updateUIForResolution();

    /**
     * @brief Sprawdzenie warunków zakoñczenia gry.
     *
     * Sprawdza, czy spe³nione s¹ warunki zakoñczenia gry, tj. zatopienie wszystkich statków jednego z graczy.
     */
    void checkEndGameCondition();

    sf::RenderWindow window; /**< Okno gry SFML. */
    sf::Font font; /**< Czcionka u¿ywana w grze. */
    GameState gameState; /**< Aktualny stan gry. */
    Menu menu; /**< Menu gry. */
    OptionsMenu optionsMenu; /**< Menu opcji. */
    EndMenu endMenu; /**< Menu zakoñczenia gry. */
    Player player1, player2; /**< Gracze. */
    Board board1, board2; /**< Plansze graczy. */
    sf::Vector2u originalResolution; /**< Pocz¹tkowa rozdzielczoœæ okna. */
    int currentPlayer = 1; /**< Numer aktualnego gracza. */
    bool settingUpPlayer1 = true; /**< Flaga ustawiania planszy dla gracza 1. */
};

