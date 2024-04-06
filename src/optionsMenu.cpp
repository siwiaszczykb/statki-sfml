#include "optionsMenu.h"

// Konstruktor klasy
OptionsMenu::OptionsMenu(float width, float height) : Menu(width, height), screenWidth(width), screenHeight(height), selectedItemIndex(0), currentResolutionIndex(0) {
    if (!font.loadFromFile("font.otf")) {
        std::cerr << "Font sie nie zaladowal bruh" << std::endl;
    }

    const std::vector<std::string> optionStrings = {
        "800x600", "1280�720", "1920�1080", "Tryb pelnoekranowy: Off", "< Curig"
    };

    for (size_t i = 0; i < optionStrings.size(); ++i) {
        menuItems[i].setFont(font);
        menuItems[i].setString(optionStrings[i]);
        menuItems[i].setFillColor(sf::Color::White);
    }

    positionMenuItems();
}

// Metoda rysuj�ca menu opcji na oknie
void OptionsMenu::draw(sf::RenderWindow& window) {
    for (const auto& item : menuItems) {
        window.draw(item);
    }
}

// Metoda ustawiaj�ca pozycj� element�w menu opcji
void OptionsMenu::positionMenuItems() {
    float y = screenHeight / 5;
    for (int i = 0; i < 5; ++i) {
        sf::FloatRect textRect = menuItems[i].getLocalBounds();
        menuItems[i].setOrigin(textRect.left + textRect.width / 2.0f, textRect.top + textRect.height / 2.0f);      
        menuItems[i].setPosition(sf::Vector2f(screenWidth / 2.0f, y + i * 50));
    }
}

// Metoda obs�uguj�ca ruch w g�r� w menu opcji
void OptionsMenu::MoveUp() {
    if (selectedItemIndex - 1 >= 0) {
        menuItems[selectedItemIndex].setFillColor(sf::Color::White);
        selectedItemIndex--;
        menuItems[selectedItemIndex].setFillColor(sf::Color::Red);
    }
    currentResolutionIndex = selectedItemIndex;
}

// Metoda obs�uguj�ca ruch w d� w menu opcji
void OptionsMenu::MoveDown() {
    if (selectedItemIndex + 1 < 5) {
        menuItems[selectedItemIndex].setFillColor(sf::Color::White);
        selectedItemIndex++;
        menuItems[selectedItemIndex].setFillColor(sf::Color::Red);
    }
    currentResolutionIndex = selectedItemIndex;
}

// Getter - Metoda zwracaj�ca indeks wybranego elementu w menu opcji
int OptionsMenu::GetPressedItem() const {
    return selectedItemIndex;
}

// Getter - Metoda zwracaj�ca wybran� rozdzielczo�� w menu opcji
Resolution OptionsMenu::getSelectedResolution() const {
    return resolutions[currentResolutionIndex];
}

// Metoda sprawdzaj�ca, czy tryb pe�noekranowy jest w��czony
bool OptionsMenu::isFullscreen() const {
    return isFullscreenEnabled; 
}

// Metoda prze��czaj�ca tryb pe�noekranowy
void OptionsMenu::toggleFullscreen() {
    isFullscreenEnabled = !isFullscreenEnabled; 
    menuItems[3].setString("Fullscreen: " + std::string(isFullscreenEnabled ? "On" : "Off"));
    positionMenuItems();
}

// Metoda aktualizuj�ca rozmiar i pozycj� menu opcji po zmianie rozdzielczo�ci okna
void OptionsMenu::updateSizeAndPosition(float newWidth, float newHeight) {
    screenWidth = newWidth;
    screenHeight = newHeight;
    positionMenuItems();
}


