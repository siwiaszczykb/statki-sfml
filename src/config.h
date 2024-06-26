#pragma once

/**
 * @brief Struktura reprezentująca rozdzielczość, składającą się z szerokości i wysokości.
 */
struct Resolution {
    unsigned int width; /**< Szerokość */
    unsigned int height; /**< Wysokość */
};

/**
 * @brief Stała reprezentująca rozmiar planszy do gry w statki.
 *
 * Stała ta zawiera obiekt struktury Resolution określający szerokość i wysokość planszy.
 * Domyślnie ustawiona na rozmiar 10x10.
 */
const Resolution boardSize = { 10, 10 };
