#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include <string>
#include <vector>
#include "Board.h"

class Player {
public:
    /**
     * @brief Konstruktor klasy Player.
     *
     * Inicjalizuje obiekt klasy Player przy u¿yciu podanych parametrów i ustawia pocz¹tkowe wartoœci zmiennych cz³onkowskich.
     *
     * @param id Unikalny identyfikator gracza.
     * @param nickname Nick gracza.
     * @param boardRef Referencja do obiektu klasy Board, na której gra gracz.
     */
   Player(const std::string& id, const std::string& nickname, Board& board);

   /**
    * @brief Enumeracja reprezentuj¹ca ró¿ne stany dla procesu konfiguracji gracza.
    */
   enum class PlayerSetupState {
       SETTING_NICKNAME, /**< Gracz ustawia swój nick. */
       PLACING_SHIPS,    /**< Gracz rozmieszcza statki na planszy. */
       DONE              /**< Proces konfiguracji zakoñczony. */
   };

   /**
    * @brief Enumeracja reprezentuj¹ca ró¿ne stany gry dla gracza.
    */
   enum class PlayerGameState {
       PLACING_SHIPS, /**< Gracz rozmieszcza statki na planszy. */
       ATTACKING,     /**< Gracz wykonuje atak na przeciwnika. */
       WAITING,       /**< Gracz oczekuje na ruch przeciwnika. */
       GAME_OVER      /**< Gra zakoñczona. */
   };

    //metody do setupu

    /**
     * @brief Obs³uguje zdarzenia zwi¹zane z konfiguracj¹ gracza.
     *
     * W zale¿noœci od aktualnego stanu konfiguracji, reaguje na zdarzenia takie jak wprowadzanie tekstu
     * czy klawisze, umo¿liwiaj¹c odpowiednie ustawienia gracza.
     *
     * @param event Zdarzenie SFML, które ma byæ obs³u¿one.
     * @param board Referencja do obiektu planszy gry.
     */
   void handleSetupEvents(const sf::Event& event, Board& board);

   /**
    * @brief Renderuje interfejs konfiguracji gracza.
    *
    * W zale¿noœci od aktualnego stanu konfiguracji, renderuje odpowiednie elementy interfejsu graficznego,
    * takie jak pole do wprowadzania nicku, informacje o rozmieszczaniu statków, planszê do rozmieszczania statków itp.
    *
    * @param window Okno SFML, na którym ma byæ renderowany interfejs.
    * @param font Czcionka u¿ywana do renderowania tekstu.
    * @param playerId Identyfikator gracza.
    */
   void renderSetup(sf::RenderWindow& window, const sf::Font& font, const std::string& playerId);


   /**
    * @brief Sprawdza, czy wszystkie statki zosta³y umieszczone na planszy.
    *
    * @return True, jeœli wszystkie statki zosta³y umieszczone; w przeciwnym razie false.
    */
   bool allShipsPlaced() const { return shipsPlaced >= MAX_SHIPS; }

   /**
    * @brief Ustawia nowy nick gracza.
    *
    * @param newNickname Nowy nick gracza.
    */
   void setNickname(const std::string& newNickname);

   /**
    * @brief Ustawia nowy stan konfiguracji gracza.
    *
    * @param state Nowy stan konfiguracji gracza.
    */

   void setSetupState(PlayerSetupState state);
   /**
    * @brief Zwraca aktualny stan konfiguracji gracza.
    *
    * @return Aktualny stan konfiguracji gracza.
    */
   PlayerSetupState getSetupState() const;

    //metody do gry
    /**
     * @brief Obs³uguje zdarzenia zwi¹zane z faz¹ gry atakuj¹c¹.
     *
     * @param event Zdarzenie SFML.
     * @param otherPlayer Przeciwnik.
     * @param currentPlayer Aktualny numer gracza.
     * @return True, jeœli tura zakoñczona; w przeciwnym razie false.
     */
   bool handleGameEvents(const sf::Event& event, Player& otherPlayer, int& currentPlayer);

   /**
    * @brief Renderuje interfejs gry.
    *
    * @param window Okno renderingu SFML.
    * @param font Czcionka do u¿ycia.
    * @param enemyPlayer Przeciwnik.
    */
   void renderGame(sf::RenderWindow& window, const sf::Font& font, const Player& enemyPlayer);

   /**
    * @brief Ustawia stan gry.
    *
    * @param state Nowy stan gry.
    */
   void setGameState(PlayerGameState state);

   /**
   * @brief Sprawdza, czy wszystkie statki zosta³y zatopione.
   *
   * @return True, jeœli wszystkie statki zosta³y zatopione, false w przeciwnym razie.
   */
   bool allShipsSunk() const;

   /**
    * @brief Pobiera aktualny stan gry.
    *
    * @return Aktualny stan gry.
    */
   PlayerGameState getGameState() const;

   /**
    * @brief Pobiera nazwê gracza.
    *
    * @return Nazwa gracza.
    */
   std::string getName() const;

   //metody do celowania
   /**
   * @brief Przesuwa celownik w górê.
   */
   void moveAimUp();

   /**
    * @brief Przesuwa celownik w dó³.
    */
   void moveAimDown();

   /**
    * @brief Przesuwa celownik w lewo.
    */
   void moveAimLeft();

   /**
    * @brief Przesuwa celownik w prawo.
    */
   void moveAimRight();

   /**
    * @brief Pobiera aktualne wspó³rzêdne celownika.
    *
    * @return Wspó³rzêdne celownika jako para intów.
    */
   std::pair<int, int> getAim() const;

   /**
    * @brief Pobiera planszê gry.
    *
    * @return Referencja do planszy gry.
    */
   Board& getBoard();

private:
    //czesc do setupu
    Board& board;                          /**< Referencja do planszy gry. */
    PlayerSetupState setupState;           /**< Stan przygotowania gracza. */
    std::string nickname;                  /**< Nazwa gracza. */
    std::string playerId;                  /**< Identyfikator gracza. */
    unsigned int startX, startY;            /**< Pocz¹tkowe wspó³rzêdne ustawiania statków. */
    unsigned int shipsPlaced;               /**< Liczba ustawionych statków. */
    static const unsigned int MAX_SHIPS = 5; /**< Maksymalna liczba statków, jakie gracz mo¿e postawiæ. */
    std::vector<unsigned int> shipLengths;  /**< D³ugoœci statków, które gracz mo¿e postawiæ. */
    bool isVertical;                       /**< Czy statek jest ustawiony pionowo czy poziomo. */

    //czesc do gry
    PlayerGameState gamestate;             /**< Aktualny stan gry gracza. */
    unsigned int attackX, attackY;         /**< Wspó³rzêdne ataku gracza. */
    int aimX, aimY;                        /**< Wspó³rzêdne celownika gracza. */


    //do renderingu
    /**
     * @brief Oblicza pozycjê do renderowania na podstawie wymiarów okna i rozmiaru elementu.
     *
     * @param window Okno renderowania.
     * @param width Szerokoœæ elementu do zrenderowania.
     * @param height Wysokoœæ elementu do zrenderowania.
     * @return Obliczona pozycja jako wektor 2D.
     */
    sf::Vector2f calculatePosition(sf::RenderWindow& window, float width, float height);
};


