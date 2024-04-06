#include "Menu.h"


Menu::Menu(float width, float height) : screenWidth(width), screenHeight(height) {
    if (!font.loadFromFile("font.otf")) {
        std::cerr << "Font sie nie zaladowal bruh" << std::endl;
        font.loadFromFile("font1.ttf");
    }

    if (!logoTexture.loadFromFile("ship.png")) { 
        std::cerr << "Logo sie nie zaladowalo bruh" << std::endl;
    }

    logo.setTexture(logoTexture);
    float logoScale = std::min(0.4f, std::min(screenWidth / logoTexture.getSize().x, screenHeight / logoTexture.getSize().y));
    logo.setScale(logoScale, logoScale);
    logo.setPosition(screenWidth / 2 - logo.getGlobalBounds().width / 2, screenHeight / 6);

    const std::vector<std::string> mainMenuStrings = {
        "Szpil", "Nasztalowania", "Wyjdz"
    };

    for (size_t i = 0; i < mainMenuStrings.size(); ++i) {
        menu[i].setFont(font);
        menu[i].setString(mainMenuStrings[i]);
        menu[i].setFillColor(sf::Color::White);
    }

    selectedItemIndex = 0;
    positionMenuItems(); 
}

void Menu::updateMenuSize(float width, float height) {
    screenWidth = width;
    screenHeight = height;
    float logoScale = std::min(0.3f, std::min(screenWidth / logoTexture.getSize().x, screenHeight / logoTexture.getSize().y));
    logo.setScale(logoScale, logoScale);
    logo.setPosition(screenWidth / 2 - logo.getGlobalBounds().width / 2, screenHeight / 6);
    positionMenuItems();
}

void Menu::positionMenuItems() {
    float totalWidth = 0;
    float maxHeight = 0;

    
    for (const auto& item : menu) {
        totalWidth += item.getGlobalBounds().width;
        maxHeight = std::max(maxHeight, item.getGlobalBounds().height);
    }

    float spacing = (screenWidth * 2 / 3 - totalWidth) / 4;  
    float x = screenWidth / 6 + spacing;

    float startY = logo.getPosition().y + logo.getGlobalBounds().height;
    float endY = screenHeight;
    float midY = startY + (endY - startY) / 2 - maxHeight / 2;

    for (int i = 0; i < 3; ++i) {
        menu[i].setPosition(x, midY);
        x += menu[i].getGlobalBounds().width + spacing;
    }
}

void Menu::draw(sf::RenderWindow& window) {
    window.draw(logo);
    for (const auto& item : menu) {
        window.draw(item);
    }
}

void Menu::MoveLeft() {
    if (selectedItemIndex - 1 >= 0) {
        menu[selectedItemIndex].setFillColor(sf::Color::White);
        selectedItemIndex--;
        menu[selectedItemIndex].setFillColor(sf::Color::Red);
    }
}

void Menu::MoveRight() {
    if (selectedItemIndex + 1 < 3) {
        menu[selectedItemIndex].setFillColor(sf::Color::White);
        selectedItemIndex++;
        menu[selectedItemIndex].setFillColor(sf::Color::Red);
    }
}

int Menu::GetPressedItem() const {
    return selectedItemIndex;
}

