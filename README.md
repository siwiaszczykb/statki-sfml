# Statki

## Opis projektu

Projekt polega na implementacji gry w statki przy użyciu języka C++ i biblioteki SFML. Gra została stworzona z wykorzystaniem paradygmatów programowania obiektowego.

## Funkcje gry

- **Gra jednoosobowa**: Gracz rywalizuje przeciwko drugiemu graczowi w trybie hot-seat.
- **Rozmieszczanie statków**: Użytkownik ma możliwość ręcznego rozmieszczenia swoich statków na planszy.
- **Strzał**: Gracz wprowadza współrzędne strzałów, a program informuje, czy trafiono, czy chybiono.
- **Interfejs użytkownika**: Gra posiada interfejs graficzny zbudowany przy użyciu biblioteki SFML.

## Struktura projektu

Projekt składa się z następujących klas:

- **Game**: Klasa zarządzająca logiką gry.
- **Player**: Klasa reprezentująca gracza.
- **Board**: Klasa odpowiedzialna za planszę gry, przechowująca informacje o rozmieszczeniu statków i historii strzałów.
- **Ship**: Klasa reprezentująca pojedynczy statek.
- **Menu, EndMenu, OptionsMenu**: Klasy odpowiedzialne za interfejs użytkownika.

## Wymagania

- C++11 lub nowszy
- Biblioteka graficzna SFML

## Dokumentacja

Dokumentacja projektu została wygenerowana przy użyciu narzędzia Doxygen. Zawiera szczegółowy opis struktur danych, klas oraz funkcji użytych w projekcie. Dokumentację można znaleźć w katalogu `docs`.

## Informacje

Projekt został zrealizowany w ramach kursu Programowanie Komputerów II na Politechnice Śląskiej w roku akademickim 2023/2024.
