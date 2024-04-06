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
     * Inicjalizuje obiekt klasy Player przy u�yciu podanych parametr�w i ustawia pocz�tkowe warto�ci zmiennych cz�onkowskich.
     *
     * @param id Unikalny identyfikator gracza.
     * @param nickname Nick gracza.
     * @param boardRef Referencja do obiektu klasy Board, na kt�rej gra gracz.
     */
   Player(const std::string& id, const std::string& nickname, Board& board);

   /**
    * @brief Enumeracja reprezentuj�ca r�ne stany dla procesu konfiguracji gracza.
    */
   enum class PlayerSetupState {
       SETTING_NICKNAME, /**< Gracz ustawia sw�j nick. */
       PLACING_SHIPS,    /**< Gracz rozmieszcza statki na planszy. */
       DONE              /**< Proces konfiguracji zako�czony. */
   };

   /**
    * @brief Enumeracja reprezentuj�ca r�ne stany gry dla gracza.
    */
   enum class PlayerGameState {
       PLACING_SHIPS, /**< Gracz rozmieszcza statki na planszy. */
       ATTACKING,     /**< Gracz wykonuje atak na przeciwnika. */
       WAITING,       /**< Gracz oczekuje na ruch przeciwnika. */
       GAME_OVER      /**< Gra zako�czona. */
   };

    //metody do setupu

    /**
     * @brief Obs�uguje zdarzenia zwi�zane z konfiguracj� gracza.
     *
     * W zale�no�ci od aktualnego stanu konfiguracji, reaguje na zdarzenia takie jak wprowadzanie tekstu
     * czy klawisze, umo�liwiaj�c odpowiednie ustawienia gracza.
     *
     * @param event Zdarzenie SFML, kt�re ma by� obs�u�one.
     * @param board Referencja do obiektu planszy gry.
     */
   void handleSetupEvents(const sf::Event& event, Board& board);

   /**
    * @brief Renderuje interfejs konfiguracji gracza.
    *
    * W zale�no�ci od aktualnego stanu konfiguracji, renderuje odpowiednie elementy interfejsu graficznego,
    * takie jak pole do wprowadzania nicku, informacje o rozmieszczaniu statk�w, plansz� do rozmieszczania statk�w itp.
    *
    * @param window Okno SFML, na kt�rym ma by� renderowany interfejs.
    * @param font Czcionka u�ywana do renderowania tekstu.
    * @param playerId Identyfikator gracza.
    */
   void renderSetup(sf::RenderWindow& window, const sf::Font& font, const std::string& playerId);


   /**
    * @brief Sprawdza, czy wszystkie statki zosta�y umieszczone na planszy.
    *
    * @return True, je�li wszystkie statki zosta�y umieszczone; w przeciwnym razie false.
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
     * @brief Obs�uguje zdarzenia zwi�zane z faz� gry atakuj�c�.
     *
     * @param event Zdarzenie SFML.
     * @param otherPlayer Przeciwnik.
     * @param currentPlayer Aktualny numer gracza.
     * @return True, je�li tura zako�czona; w przeciwnym razie false.
     */
   bool handleGameEvents(const sf::Event& event, Player& otherPlayer, int& currentPlayer);

   /**
    * @brief Renderuje interfejs gry.
    *
    * @param window Okno renderingu SFML.
    * @param font Czcionka do u�ycia.
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
   * @brief Sprawdza, czy wszystkie statki zosta�y zatopione.
   *
   * @return True, je�li wszystkie statki zosta�y zatopione, false w przeciwnym razie.
   */
   bool allShipsSunk() const;

   /**
    * @brief Pobiera aktualny stan gry.
    *
    * @return Aktualny stan gry.
    */
   PlayerGameState getGameState() const;

   /**
    * @brief Pobiera nazw� gracza.
    *
    * @return Nazwa gracza.
    */
   std::string getName() const;

   //metody do celowania
   /**
   * @brief Przesuwa celownik w g�r�.
   */
   void moveAimUp();

   /**
    * @brief Przesuwa celownik w d�.
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
    * @brief Pobiera aktualne wsp�rz�dne celownika.
    *
    * @return Wsp�rz�dne celownika jako para int�w.
    */
   std::pair<int, int> getAim() const;

   /**
    * @brief Pobiera plansz� gry.
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
    unsigned int startX, startY;            /**< Pocz�tkowe wsp�rz�dne ustawiania statk�w. */
    unsigned int shipsPlaced;               /**< Liczba ustawionych statk�w. */
    static const unsigned int MAX_SHIPS = 5; /**< Maksymalna liczba statk�w, jakie gracz mo�e postawi�. */
    std::vector<unsigned int> shipLengths;  /**< D�ugo�ci statk�w, kt�re gracz mo�e postawi�. */
    bool isVertical;                       /**< Czy statek jest ustawiony pionowo czy poziomo. */

    //czesc do gry
    PlayerGameState gamestate;             /**< Aktualny stan gry gracza. */
    unsigned int attackX, attackY;         /**< Wsp�rz�dne ataku gracza. */
    int aimX, aimY;                        /**< Wsp�rz�dne celownika gracza. */


    //do renderingu
    /**
     * @brief Oblicza pozycj� do renderowania na podstawie wymiar�w okna i rozmiaru elementu.
     *
     * @param window Okno renderowania.
     * @param width Szeroko�� elementu do zrenderowania.
     * @param height Wysoko�� elementu do zrenderowania.
     * @return Obliczona pozycja jako wektor 2D.
     */
    sf::Vector2f calculatePosition(sf::RenderWindow& window, float width, float height);
};


