#include "endMenu.h"

// Inicjalizacja czcionki i ustawienia tekstu dla przycisku "Wyjdz"
EndMenu::EndMenu(float width, float height) : Menu(width, height) {
    if (!font.loadFromFile("font.otf")) {
        std::cerr << "Font sie nie zaladowal" << std::endl;
    }
    menuItems[0].setFont(font);
    menuItems[0].setString("Wyjdz");
    menuItems[0].setFillColor(sf::Color::White);
    menuItems[0].setPosition(width / 2, height / 2); 
}

// Inicjalizacja tekstu informuj¹cego o zwyciêzcy gry
void EndMenu::setWinnerDetails(const std::string& winnerName) {
    winnerDetails.setFont(font);
    winnerDetails.setString("Zwyciezca: " + winnerName);
    winnerDetails.setCharacterSize(24);
    winnerDetails.setFillColor(sf::Color::Cyan);
    sf::FloatRect textRect = winnerDetails.getLocalBounds();
    winnerDetails.setOrigin(textRect.left + textRect.width / 2.0f, textRect.top + textRect.height / 2.0f);
    winnerDetails.setPosition(screenWidth / 2, screenHeight / 4); 
    positionExitButton();
}

// Pozycjonowanie przycisku "Wyjdz" pod informacjami o zwyciêzcy
void EndMenu::positionExitButton() {
    sf::FloatRect winnerRect = winnerDetails.getGlobalBounds();
    float exitButtonY = winnerRect.top + winnerRect.height + 60;
    sf::FloatRect exitRect = menuItems[0].getLocalBounds();
    menuItems[0].setOrigin(exitRect.left + exitRect.width / 2.0f, exitRect.top + exitRect.height / 2.0f);
    menuItems[0].setPosition(screenWidth / 2, exitButtonY);
}

// Rysowanie informacji o zwyciêzcy i przycisku "Wyjdz"
void EndMenu::draw(sf::RenderWindow& window) {
    window.draw(winnerDetails);
    window.draw(menuItems[0]);
}
