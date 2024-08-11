# Battleships [EN]

## Project Description

This project involves the implementation of the classic battleships game using C++ and the SFML library. The game was developed following object-oriented programming paradigms, ensuring code clarity and ease of expansion and maintenance.

## Game Features

- **Single-player mode**: The player competes against a computer opponent that randomly places its ships on the board.
- **Ship Placement**: Users can manually place their ships on the board.
- **Firing Mode**: The player inputs the coordinates of their shots, and the program informs whether the shot was a hit or a miss.
- **User Interface**: The game features a graphical user interface built using the SFML library.

## Project Structure

The project consists of the following classes:

- **Game**: Manages the game logic.
- **Player**: Represents the player.
- **Board**: Responsible for the game board, storing information about ship placements and shot history.
- **Ship**: Represents a single ship.
- **Menu, EndMenu, OptionsMenu**: Classes responsible for the user interface.

## Installation and Execution

1. Clone the repository:
   ```sh
   git clone https://github.com/siwiaszczykb/statki-sfml.git
   ```

2. Navigate to the project directory:
   ```sh
   cd statki-sfml
   ```

3. Build the project using CMake:
   ```sh
   mkdir build
   cd build
   cmake ..
   make
   ```

4. Run the game:
   ```sh
   ./statki
   ```

## Requirements

- C++11 or newer
- SFML library

## Documentation

The project documentation was generated using Doxygen. It contains a detailed description of the data structures, classes, and functions used in the project. The documentation can be found in the `docs` directory.

## Author

This project was completed by Bartosz Siwiaszczyk as part of the Computer Programming II course at the Silesian University of Technology in the 2023/2024 academic year.

# Statki [PL]

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
