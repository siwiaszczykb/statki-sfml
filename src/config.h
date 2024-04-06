#pragma once

/**
 * @brief Struktura reprezentuj¹ca rozdzielczoœæ, sk³adaj¹c¹ siê z szerokoœci i wysokoœci.
 */
struct Resolution {
    unsigned int width; /**< Szerokoœæ */
    unsigned int height; /**< Wysokoœæ */
};

/**
 * @brief Sta³a reprezentuj¹ca rozmiar planszy do gry w statki.
 *
 * Sta³a ta zawiera obiekt struktury Resolution okreœlaj¹cy szerokoœæ i wysokoœæ planszy.
 * Domyœlnie ustawiona na rozmiar 10x10.
 */
const Resolution boardSize = { 10, 10 };
