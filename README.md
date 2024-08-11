# Statki

## Opis projektu

Projekt polega na implementacji klasycznej gry w statki przy użyciu języka C++ i biblioteki SFML. Gra została stworzona z wykorzystaniem paradygmatów programowania obiektowego, co zapewnia przejrzystość kodu oraz łatwość jego rozbudowy i utrzymania.

## Funkcje gry

- **Gra jednoosobowa**: Gracz rywalizuje przeciwko komputerowi, który losowo rozmieszcza swoje statki.
- **Rozmieszczanie statków**: Użytkownik ma możliwość ręcznego rozmieszczenia swoich statków na planszy.
- **Tryb strzału**: Gracz wprowadza współrzędne strzałów, a program informuje, czy trafiono, czy chybiono.
- **Interfejs użytkownika**: Gra posiada interfejs graficzny zbudowany przy użyciu biblioteki SFML.

## Struktura projektu

Projekt składa się z następujących klas:

- **Game**: Klasa zarządzająca logiką gry.
- **Player**: Klasa reprezentująca gracza.
- **Board**: Klasa odpowiedzialna za planszę gry, przechowująca informacje o rozmieszczeniu statków i historii strzałów.
- **Ship**: Klasa reprezentująca pojedynczy statek.
- **Menu, EndMenu, OptionsMenu**: Klasy odpowiedzialne za interfejs użytkownika.

## Instalacja i uruchomienie

1. Sklonuj repozytorium:
   ```sh
   git clone https://github.com/siwiaszczykb/statki-sfml.git
   ```

2. Przejdź do katalogu z projektem:
   ```sh
   cd statki-sfml
   ```

3. Zbuduj projekt za pomocą CMake:
   ```sh
   mkdir build
   cd build
   cmake ..
   make
   ```

4. Uruchom grę:
   ```sh
   ./statki
   ```

## Wymagania

- C++11 lub nowszy
- Biblioteka SFML

## Dokumentacja

Dokumentacja projektu została wygenerowana przy użyciu narzędzia Doxygen. Zawiera szczegółowy opis struktur danych, klas oraz funkcji użytych w projekcie. Dokumentację można znaleźć w katalogu `docs`.

## Autor

Projekt został zrealizowany przez Bartosza Siwiaszczyka w ramach kursu Programowanie Komputerów II na Politechnice Śląskiej w roku akademickim 2023/2024.
