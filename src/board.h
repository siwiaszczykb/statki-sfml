#pragma once
#include "config.h"
#include "Ship.h"
#include <vector>
#include <iostream>

/**
 * @brief Klasa reprezentuj¹ca planszê do gry w statki.
 *
 * Klasa ta zawiera prywatne sk³adowe reprezentuj¹ce w³aœciwoœci planszy do gry w statki,
 * takie jak szerokoœæ, wysokoœæ, dwuwymiarowa tablica zawieraj¹ca zawartoœæ poszczególnych komórek
 * oraz wektor przechowuj¹cy statki umieszczone na planszy.
 */
class Board {
public:

    /**
     * @brief Konstruktor domyœlny.
     *
     * Inicjalizuje planszê o wymiarach zdefiniowanych w pliku konfiguracyjnym `config.h`
     * i przygotowuje j¹ do gry, wype³niaj¹c wszystkie komórki znakiem '.'.
     */
    Board(); 

    /**
     * @brief Destruktor.
     *
     * Zwalnia zaalokowan¹ pamiêæ po planszy oraz statkach.
     */
    ~Board();

    /**
     * @brief Pobierz wartoœæ komórki o okreœlonych wspó³rzêdnych.
     *
     * Funkcja  pobiera wartoœæ komórki znajduj¹cej siê na okreœlonych wspó³rzêdnych (x, y) z planszy gry.
     *
     * @param x Wspó³rzêdna pozioma x komórki.
     * @param y Wspó³rzêdna pionowa y komórki.
     *
     * @return Znak reprezentuj¹cy zawartoœæ okreœlonej komórki.
     *         Jeœli wspó³rzêdne s¹ poza zakresem, zwracany jest znak spacji.
     */
    char getCellValue(unsigned int x, unsigned int y) const;

    /**
     * @brief Umieœæ statek na planszy gry.
     *
     * Funkcja ta umieszcza statek na planszy gry, poczynaj¹c od okreœlonych wspó³rzêdnych
     * (startX, startY) i o okreœlonej d³ugoœci (shipLength). Statek mo¿e byæ umieszczony
     * pionowo lub poziomo w zale¿noœci od wartoœci parametru isVertical.
     *
     * @param startX Pocz¹tkowa wspó³rzêdna pozioma umieszczenia statku.
     * @param startY Pocz¹tkowa wspó³rzêdna pionowa umieszczenia statku.
     * @param shipLength D³ugoœæ statku do umieszczenia.
     * @param isVertical Flaga okreœlaj¹ca orientacjê statku (true - pionowy, false - poziomy).
     *
     * @return Wartoœæ logiczna informuj¹ca o powodzeniu umieszczenia statku.
     *         Zwraca true, jeœli umieszczenie by³o mo¿liwe, a false w przeciwnym razie.
     */
    bool placeShip(unsigned int startX, unsigned int startY, unsigned int shipLength, bool isVertical);

     /**
     * @brief SprawdŸ dostêpnoœæ komórki na planszy gry.
     *
     * Funkcja ta sprawdza, czy okreœlona komórka na planszy gry (o wspó³rzêdnych y, x) jest dostêpna
     * do umieszczenia statku. Komórka jest uznawana za dostêpn¹, jeœli jej wartoœæ to '.' oraz ¿adna
     * z s¹siednich komórek nie zawiera statku ('S').
     *
     * @param y Wspó³rzêdna pionowa komórki.
     * @param x Wspó³rzêdna pozioma komórki.
     *
     * @return Wartoœæ logiczna informuj¹ca o dostêpnoœci komórki.
     *         Zwraca true, jeœli komórka jest dostêpna, a false w przeciwnym razie.
     */
    bool isCellAvailable(unsigned int y, unsigned int x) const;

    /**
     * @brief Wystrzel w okreœlon¹ komórkê na planszy gry.
     *
     * Funkcja ta wykonuje strza³ w okreœlon¹ komórkê o wspó³rzêdnych (x, y) na planszy gry.
     * W zale¿noœci od zawartoœci komórki, aktualizuje stan planszy oznaczaj¹c trafienie statku ('X')
     * lub brak trafienia ('M').
     *
     * @param x Wspó³rzêdna pozioma celu strza³u.
     * @param y Wspó³rzêdna pionowa celu strza³u.
     *
     * @return Wartoœæ logiczna informuj¹ca o rezultacie strza³u.
     *         Zwraca true, jeœli strza³ trafi³ statek, a false w przeciwnym razie.
     */
    bool shootAt(unsigned int x, unsigned int y); 

    /**
     * @brief SprawdŸ, czy statek na planszy jest zatopiony.
     *
     * Funkcja ta sprawdza, czy statek na planszy, którego pocz¹tkowe wspó³rzêdne to (x, y),
     * jest zatopiony, czyli czy wszystkie jego czêœci zosta³y trafione.
     *
     * @param x Wspó³rzêdna pozioma pocz¹tku statku.
     * @param y Wspó³rzêdna pionowa pocz¹tku statku.
     *
     * @return Wartoœæ logiczna informuj¹ca o tym, czy statek jest zatopiony.
     *         Zwraca true, jeœli statek jest zatopiony, a false w przeciwnym razie.
     */
    bool isShipSunk(unsigned int x, unsigned int y); 

    /**
     * @brief SprawdŸ, czy wszystkie statki na planszy zosta³y zatopione.
     *
     * Funkcja ta sprawdza, czy na planszy nie ma ju¿ ¿adnych aktywnych statków, czyli
     * czy wszystkie statki zosta³y zatopione.
     *
     * @return Wartoœæ logiczna informuj¹ca o tym, czy wszystkie statki zosta³y zatopione.
     *         Zwraca true, jeœli wszystkie statki s¹ zatopione, a false w przeciwnym razie.
     */
    bool areAllShipsSunk(); 

    /**
     * @brief Getter - Pobierz szerokoœæ planszy.
     *
     * Funkcja ta zwraca szerokoœæ planszy gry.
     *
     * @return Wartoœæ ca³kowita unsigned int reprezentuj¹ca szerokoœæ planszy.
     */
    unsigned int getWidth() const;

    /**
     * @brief Getter - Pobierz wysokoœæ planszy.
     *
     * Funkcja ta zwraca wysokoœæ planszy gry.
     *
     * @return Wartoœæ ca³kowita unsigned int reprezentuj¹ca wysokoœæ planszy.
     */
    unsigned int getHeight() const;

private:
    unsigned int width; /**< Szerokoœæ planszy. */
    unsigned int height; /**< Wysokoœæ planszy. */
    char** boardArray; /**< Dwuwymiarowa tablica reprezentuj¹ca planszê. */
    std::vector<Ship> ships; /**< Wektor przechowuj¹cy statki na planszy. */
};


