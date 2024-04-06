#include "optionsMenu.h"

// Konstruktor klasy
OptionsMenu::OptionsMenu(float width, float height) : Menu(width, height), screenWidth(width), screenHeight(height), selectedItemIndex(0), currentResolutionIndex(0) {
    if (!font.loadFromFile("font.otf")) {
        std::cerr << "Font sie nie zaladowal bruh" << std::endl;
    }

    const std::vector<std::string> optionStrings = {
        "800x600", "1280×720", "1920×1080", "Tryb pelnoekranowy: Off", "< Curig"
    };

    for (size_t i = 0; i < optionStrings.size(); ++i) {
        menuItems[i].setFont(font);
        menuItems[i].setString(optionStrings[i]);
        menuItems[i].setFillColor(sf::Color::White);
    }

    positionMenuItems();
}

// Metoda rysuj¹ca menu opcji na oknie
void OptionsMenu::draw(sf::RenderWindow& window) {
    for (const auto& item : menuItems) {
        window.draw(item);
    }
}

// Metoda ustawiaj¹ca pozycjê elementów menu opcji
void OptionsMenu::positionMenuItems() {
    float y = screenHeight / 5;
    for (int i = 0; i < 5; ++i) {
        sf::FloatRect textRect = menuItems[i].getLocalBounds();
        menuItems[i].setOrigin(textRect.left + textRect.width / 2.0f, textRect.top + textRect.height / 2.0f);      
        menuItems[i].setPosition(sf::Vector2f(screenWidth / 2.0f, y + i * 50));
    }
}

// Metoda obs³uguj¹ca ruch w górê w menu opcji
void OptionsMenu::MoveUp() {
    if (selectedItemIndex - 1 >= 0) {
        menuItems[selectedItemIndex].setFillColor(sf::Color::White);
        selectedItemIndex--;
        menuItems[selectedItemIndex].setFillColor(sf::Color::Red);
    }
    currentResolutionIndex = selectedItemIndex;
}

// Metoda obs³uguj¹ca ruch w dó³ w menu opcji
void OptionsMenu::MoveDown() {
    if (selectedItemIndex + 1 < 5) {
        menuItems[selectedItemIndex].setFillColor(sf::Color::White);
        selectedItemIndex++;
        menuItems[selectedItemIndex].setFillColor(sf::Color::Red);
    }
    currentResolutionIndex = selectedItemIndex;
}

// Getter - Metoda zwracaj¹ca indeks wybranego elementu w menu opcji
int OptionsMenu::GetPressedItem() const {
    return selectedItemIndex;
}

// Getter - Metoda zwracaj¹ca wybran¹ rozdzielczoœæ w menu opcji
Resolution OptionsMenu::getSelectedResolution() const {
    return resolutions[currentResolutionIndex];
}

// Metoda sprawdzaj¹ca, czy tryb pe³noekranowy jest w³¹czony
bool OptionsMenu::isFullscreen() const {
    return isFullscreenEnabled; 
}

// Metoda prze³¹czaj¹ca tryb pe³noekranowy
void OptionsMenu::toggleFullscreen() {
    isFullscreenEnabled = !isFullscreenEnabled; 
    menuItems[3].setString("Fullscreen: " + std::string(isFullscreenEnabled ? "On" : "Off"));
    positionMenuItems();
}

// Metoda aktualizuj¹ca rozmiar i pozycjê menu opcji po zmianie rozdzielczoœci okna
void OptionsMenu::updateSizeAndPosition(float newWidth, float newHeight) {
    screenWidth = newWidth;
    screenHeight = newHeight;
    positionMenuItems();
}


