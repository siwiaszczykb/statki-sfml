#pragma once
#include "config.h"
#include "Ship.h"
#include <vector>
#include <iostream>

/**
 * @brief Klasa reprezentuj�ca plansz� do gry w statki.
 *
 * Klasa ta zawiera prywatne sk�adowe reprezentuj�ce w�a�ciwo�ci planszy do gry w statki,
 * takie jak szeroko��, wysoko��, dwuwymiarowa tablica zawieraj�ca zawarto�� poszczeg�lnych kom�rek
 * oraz wektor przechowuj�cy statki umieszczone na planszy.
 */
class Board {
public:

    /**
     * @brief Konstruktor domy�lny.
     *
     * Inicjalizuje plansz� o wymiarach zdefiniowanych w pliku konfiguracyjnym `config.h`
     * i przygotowuje j� do gry, wype�niaj�c wszystkie kom�rki znakiem '.'.
     */
    Board(); 

    /**
     * @brief Destruktor.
     *
     * Zwalnia zaalokowan� pami�� po planszy oraz statkach.
     */
    ~Board();

    /**
     * @brief Pobierz warto�� kom�rki o okre�lonych wsp�rz�dnych.
     *
     * Funkcja  pobiera warto�� kom�rki znajduj�cej si� na okre�lonych wsp�rz�dnych (x, y) z planszy gry.
     *
     * @param x Wsp�rz�dna pozioma x kom�rki.
     * @param y Wsp�rz�dna pionowa y kom�rki.
     *
     * @return Znak reprezentuj�cy zawarto�� okre�lonej kom�rki.
     *         Je�li wsp�rz�dne s� poza zakresem, zwracany jest znak spacji.
     */
    char getCellValue(unsigned int x, unsigned int y) const;

    /**
     * @brief Umie�� statek na planszy gry.
     *
     * Funkcja ta umieszcza statek na planszy gry, poczynaj�c od okre�lonych wsp�rz�dnych
     * (startX, startY) i o okre�lonej d�ugo�ci (shipLength). Statek mo�e by� umieszczony
     * pionowo lub poziomo w zale�no�ci od warto�ci parametru isVertical.
     *
     * @param startX Pocz�tkowa wsp�rz�dna pozioma umieszczenia statku.
     * @param startY Pocz�tkowa wsp�rz�dna pionowa umieszczenia statku.
     * @param shipLength D�ugo�� statku do umieszczenia.
     * @param isVertical Flaga okre�laj�ca orientacj� statku (true - pionowy, false - poziomy).
     *
     * @return Warto�� logiczna informuj�ca o powodzeniu umieszczenia statku.
     *         Zwraca true, je�li umieszczenie by�o mo�liwe, a false w przeciwnym razie.
     */
    bool placeShip(unsigned int startX, unsigned int startY, unsigned int shipLength, bool isVertical);

     /**
     * @brief Sprawd� dost�pno�� kom�rki na planszy gry.
     *
     * Funkcja ta sprawdza, czy okre�lona kom�rka na planszy gry (o wsp�rz�dnych y, x) jest dost�pna
     * do umieszczenia statku. Kom�rka jest uznawana za dost�pn�, je�li jej warto�� to '.' oraz �adna
     * z s�siednich kom�rek nie zawiera statku ('S').
     *
     * @param y Wsp�rz�dna pionowa kom�rki.
     * @param x Wsp�rz�dna pozioma kom�rki.
     *
     * @return Warto�� logiczna informuj�ca o dost�pno�ci kom�rki.
     *         Zwraca true, je�li kom�rka jest dost�pna, a false w przeciwnym razie.
     */
    bool isCellAvailable(unsigned int y, unsigned int x) const;

    /**
     * @brief Wystrzel w okre�lon� kom�rk� na planszy gry.
     *
     * Funkcja ta wykonuje strza� w okre�lon� kom�rk� o wsp�rz�dnych (x, y) na planszy gry.
     * W zale�no�ci od zawarto�ci kom�rki, aktualizuje stan planszy oznaczaj�c trafienie statku ('X')
     * lub brak trafienia ('M').
     *
     * @param x Wsp�rz�dna pozioma celu strza�u.
     * @param y Wsp�rz�dna pionowa celu strza�u.
     *
     * @return Warto�� logiczna informuj�ca o rezultacie strza�u.
     *         Zwraca true, je�li strza� trafi� statek, a false w przeciwnym razie.
     */
    bool shootAt(unsigned int x, unsigned int y); 

    /**
     * @brief Sprawd�, czy statek na planszy jest zatopiony.
     *
     * Funkcja ta sprawdza, czy statek na planszy, kt�rego pocz�tkowe wsp�rz�dne to (x, y),
     * jest zatopiony, czyli czy wszystkie jego cz�ci zosta�y trafione.
     *
     * @param x Wsp�rz�dna pozioma pocz�tku statku.
     * @param y Wsp�rz�dna pionowa pocz�tku statku.
     *
     * @return Warto�� logiczna informuj�ca o tym, czy statek jest zatopiony.
     *         Zwraca true, je�li statek jest zatopiony, a false w przeciwnym razie.
     */
    bool isShipSunk(unsigned int x, unsigned int y); 

    /**
     * @brief Sprawd�, czy wszystkie statki na planszy zosta�y zatopione.
     *
     * Funkcja ta sprawdza, czy na planszy nie ma ju� �adnych aktywnych statk�w, czyli
     * czy wszystkie statki zosta�y zatopione.
     *
     * @return Warto�� logiczna informuj�ca o tym, czy wszystkie statki zosta�y zatopione.
     *         Zwraca true, je�li wszystkie statki s� zatopione, a false w przeciwnym razie.
     */
    bool areAllShipsSunk(); 

    /**
     * @brief Getter - Pobierz szeroko�� planszy.
     *
     * Funkcja ta zwraca szeroko�� planszy gry.
     *
     * @return Warto�� ca�kowita unsigned int reprezentuj�ca szeroko�� planszy.
     */
    unsigned int getWidth() const;

    /**
     * @brief Getter - Pobierz wysoko�� planszy.
     *
     * Funkcja ta zwraca wysoko�� planszy gry.
     *
     * @return Warto�� ca�kowita unsigned int reprezentuj�ca wysoko�� planszy.
     */
    unsigned int getHeight() const;

private:
    unsigned int width; /**< Szeroko�� planszy. */
    unsigned int height; /**< Wysoko�� planszy. */
    char** boardArray; /**< Dwuwymiarowa tablica reprezentuj�ca plansz�. */
    std::vector<Ship> ships; /**< Wektor przechowuj�cy statki na planszy. */
};


