#pragma once

/**
 * @brief Struktura reprezentuj�ca rozdzielczo��, sk�adaj�c� si� z szeroko�ci i wysoko�ci.
 */
struct Resolution {
    unsigned int width; /**< Szeroko�� */
    unsigned int height; /**< Wysoko�� */
};

/**
 * @brief Sta�a reprezentuj�ca rozmiar planszy do gry w statki.
 *
 * Sta�a ta zawiera obiekt struktury Resolution okre�laj�cy szeroko�� i wysoko�� planszy.
 * Domy�lnie ustawiona na rozmiar 10x10.
 */
const Resolution boardSize = { 10, 10 };
