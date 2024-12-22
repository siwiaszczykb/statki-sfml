#include "Game.h"

// Konstruktor
Game::Game() : window(sf::VideoMode(800, 600), "Szify"),
menu(window.getSize().x, window.getSize().y),
optionsMenu(window.getSize().x, window.getSize().y),
gameState(GameState::MENU), board1(), board2(),
player1("Player1", "", board1), player2("Player2", "", board2), endMenu(window.getSize().x, window.getSize().y) {
    if (!font.loadFromFile("font.otf")) {
        std::cerr << "Font sie nie zaladowal" << std::endl;
    }
}

// G³ówna pêtla
void Game::run() {
    while (window.isOpen()) {
        processEvents();
        render();
    }
}

// Obs³uga zdarzeñ klawiatury dla stanu menu
void Game::handleMenuEvents(const sf::Event& event) {
    switch (event.key.code) {
    case sf::Keyboard::Left:
        menu.MoveLeft();
        break;
    case sf::Keyboard::Right:
        menu.MoveRight();
        break;
    case sf::Keyboard::Return:
        switch (menu.GetPressedItem()) {
        case 0:
            gameState = GameState::SETUP;
            break;
        case 1:
            gameState = GameState::OPTIONS;
            break;
        case 2:
            window.close();
            break;
        }
    }
}

// Obs³uga zdarzeñ klawiatury dla stanu opcji
void Game::handleOptionsEvents(const sf::Event & event) {
    switch (event.key.code) {
    case sf::Keyboard::Up:
        optionsMenu.MoveUp();
        break;
    case sf::Keyboard::Down:
        optionsMenu.MoveDown();
        break;
    case sf::Keyboard::Return:
        int selectedItem = optionsMenu.GetPressedItem();
        if (selectedItem < 3) { 
            changeResolution();
        }
        else if (selectedItem == 3) {
            optionsMenu.toggleFullscreen();
            toggleFullscreen();
        }
        else if (selectedItem == 4) {
            gameState = GameState::MENU;
        }
        break;
    }
}

// Obs³uga zdarzeñ klawiatury dla stanu ustawiania planszy
void Game::handleSetupEvents(const sf::Event& event) {
    if (settingUpPlayer1) {
        player1.handleSetupEvents(event, board1);
        if (player1.getSetupState() == Player::PlayerSetupState::DONE) {
            settingUpPlayer1 = false;
            player2.setSetupState(Player::PlayerSetupState::SETTING_NICKNAME);
        }
    }
    else {
        player2.handleSetupEvents(event, board2);
        if (player2.getSetupState() == Player::PlayerSetupState::DONE) {
            gameState = GameState::PLAY;
            currentPlayer = 1;
            player1.setGameState(Player::PlayerGameState::ATTACKING);
            player2.setGameState(Player::PlayerGameState::WAITING); 
        }
    }
}

// Obs³uga zdarzeñ klawiatury dla stanu graj
void Game::handlePlayEvents(const sf::Event& event) {
    if (currentPlayer == 1) {
        if (player1.handleGameEvents(event, player2, currentPlayer)) {
            checkEndGameCondition();
        }
    }
    else {
        if (player2.handleGameEvents(event, player1, currentPlayer)) {
            checkEndGameCondition();
        }
    }
}

// Obs³uga zdarzeñ klawiatury dla stanu zakoñczenia gry
void Game::handleEndMenuEvents(const sf::Event& event) {
    switch (event.key.code) {
    case sf::Keyboard::Up:
        endMenu.MoveUp();
        break;
    case sf::Keyboard::Down:
        endMenu.MoveDown();
        break;
    case sf::Keyboard::Return:
        window.close();
        break;
    }
}

// Przetwarzanie zdarzeñ SFML
void Game::processEvents() {
    sf::Event event;
    while (window.pollEvent(event)) {
        if (gameState == GameState::SETUP) {
            handleSetupEvents(event);
        }
        else {
            switch (event.type) {
            case sf::Event::KeyPressed: 
                switch (gameState) {
                case GameState::MENU:
                    handleMenuEvents(event);
                    break;
                case GameState::OPTIONS:
                    handleOptionsEvents(event);
                    break;
                case GameState::PLAY:
                    if (currentPlayer == 1) {
                        bool turnEnded = false;
                        player1.handleGameEvents(event, player2, currentPlayer);
                        checkEndGameCondition();
                    }
                    else {
                        bool turnEnded = false;
                        player2.handleGameEvents(event, player1, currentPlayer);
                        checkEndGameCondition();
                    }
                    break;
                case GameState::END:
                    handleEndMenuEvents(event);
                    break;
                }
                break;
            case sf::Event::Closed:
                window.close();
                break;
            }
        }
    }
}

// Renderowanie obrazu gry w SFML
void Game::render() {
    window.clear();

    switch (gameState) {
    case GameState::MENU:
        menu.draw(window);
        break;
    case GameState::OPTIONS:
        optionsMenu.draw(window);
        break;
    case GameState::SETUP:
        if (settingUpPlayer1) {
            player1.renderSetup(window, font, "Player1");
        }
        else {
            player2.renderSetup(window, font, "Player2");
        }
        break;
    case GameState::PLAY:
        if (currentPlayer == 1) {
            player1.renderGame(window, font, player2);
        }
        else {
            player2.renderGame(window, font, player1);
        }
        break;

    case GameState::END:
        endMenu.draw(window);
        break;
    }

    window.display();
}

// Zmiana rozdzielczoœci okna gry
void Game::changeResolution() {
    Resolution newResolution = optionsMenu.getSelectedResolution();
    window.create(sf::VideoMode(newResolution.width, newResolution.height), "Szify");
    optionsMenu.updateSizeAndPosition(newResolution.width, newResolution.height);
    updateUIForResolution();
}

// Prze³¹czanie trybu pe³noekranowego
void Game::toggleFullscreen() {
    if (optionsMenu.isFullscreen()) {
        window.create(sf::VideoMode::getDesktopMode(), "Szify", sf::Style::Fullscreen);
    }
    else {
        Resolution res;
        res.width = 800;
        res.height = 600;
        window.create(sf::VideoMode(res.width, res.height), "Szify", sf::Style::Default);
    }
    sf::Vector2u newSize = window.getSize();
    optionsMenu.updateSizeAndPosition(newSize.x, newSize.y);
    updateUIForResolution();
}

// Aktualizacja interfejsu u¿ytkownika po zmianie rozdzielczosci
void Game::updateUIForResolution() {
    sf::Vector2u windowSize = window.getSize();
    menu.updateMenuSize(static_cast<float>(windowSize.x), static_cast<float>(windowSize.y));
}

// Sprawdzenie warunkow zakoñczenia gry
void Game::checkEndGameCondition() {
    if (player1.allShipsSunk() || player2.allShipsSunk()) {
        gameState = GameState::END;
        Player& winner = player1.allShipsSunk() ? player2 : player1;
        endMenu.setWinnerDetails(winner.getName());
    }
}

