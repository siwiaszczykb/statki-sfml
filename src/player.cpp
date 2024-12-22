#include "Player.h"
#include "game.h"

Player::Player(const std::string& id, const std::string& nickname, Board& boardRef)
    : playerId(id),
    nickname(nickname),
    board(boardRef),
    startX(0),
    startY(0),
    shipsPlaced(0),
    shipLengths({ 5, 4, 3, 3, 2 }),
    isVertical(false),
    gamestate(PlayerGameState::PLACING_SHIPS),
    attackX(0),
    attackY(0),
    aimX(0),
    aimY(0) {}

void Player::handleSetupEvents(const sf::Event& event, Board& board) {
    // Obs³uga wprowadzania nicku
    if (setupState == PlayerSetupState::SETTING_NICKNAME) {
        if (event.type == sf::Event::TextEntered) {
            // Dodawanie znaku do nicku (jesli drukowalny)
            if (event.text.unicode < 128 && std::isprint(static_cast<char>(event.text.unicode))) {
                nickname += static_cast<char>(event.text.unicode);
            }
        }
        else if (event.type == sf::Event::KeyPressed) {
            // Usuwanie ostatniego znaku lub przejœcie do etapu ustawiania statków
            if (event.key.code == sf::Keyboard::BackSpace && !nickname.empty()) {
                nickname.pop_back();
            }
            else if (event.key.code == sf::Keyboard::Enter) {
                setupState = PlayerSetupState::PLACING_SHIPS;
            }
        }
    }
    // Obs³uga ustawiania statków
    else if (setupState == PlayerSetupState::PLACING_SHIPS) {
        if (event.type == sf::Event::KeyPressed) {
            switch (event.key.code) {
                // Przesuniêcie w górê
            case sf::Keyboard::Up:
                if (startY > 0) --startY;
                break;
                // Przesuniêcie w dó³
            case sf::Keyboard::Down:
                if (startY < board.getHeight() - 1) ++startY;
                break;
                // Przesuniêcie w lewo
            case sf::Keyboard::Left:
                if (startX > 0) --startX;
                break;
                // Przesuniêcie w prawo
            case sf::Keyboard::Right:
                if (startX < board.getWidth() - 1) ++startX;
                break;
                // Zmiana orientacji statku
            case sf::Keyboard::R:
                isVertical = !isVertical;
                break;
                // Postawienie statku (Enter)
            case sf::Keyboard::Enter:
                if (!shipLengths.empty() && board.placeShip(startY, startX, shipLengths.back(), isVertical)) {
                    shipLengths.pop_back();
                    shipsPlaced++;
                    if (shipsPlaced >= MAX_SHIPS) {
                        setupState = PlayerSetupState::DONE;
                    }
                }
                else {
                    std::cerr << "Nie postawiono statku\n";
                }
                break;
            }
        }
    }
}

void Player::renderSetup(sf::RenderWindow& window, const sf::Font& font, const std::string& playerId) {
    // Renderowanie ekranu ustawieñ nicku
    if (setupState == PlayerSetupState::SETTING_NICKNAME) {
        sf::Text prompt(playerId + " - Wpisz nick:", font);
        prompt.setCharacterSize(24);
        prompt.setFillColor(sf::Color::White);
        sf::Vector2f promptPosition = calculatePosition(window, prompt.getLocalBounds().width, prompt.getLocalBounds().height);
        prompt.setPosition(promptPosition.x, 50);

        sf::Text nicknameText(nickname, font);
        nicknameText.setCharacterSize(24);
        nicknameText.setFillColor(sf::Color::White);
        sf::Vector2f nicknamePosition = calculatePosition(window, nicknameText.getLocalBounds().width, nicknameText.getLocalBounds().height);
        nicknameText.setPosition(nicknamePosition.x, 100);

        window.draw(prompt);
        window.draw(nicknameText);
    }
    // Renderowanie ekranu ustawiania statków
    else if (setupState == PlayerSetupState::PLACING_SHIPS) {
        sf::Text headerText(nickname + " teraz uklada szify", font);
        headerText.setCharacterSize(24);
        headerText.setFillColor(sf::Color::Cyan);
        sf::Vector2f headerPosition = calculatePosition(window, headerText.getLocalBounds().width, headerText.getLocalBounds().height);
        headerText.setPosition(headerPosition.x, 50);
        window.draw(headerText);

        std::string shipLengthTextStr = "Dlugosc szifu: ";
        if (!shipLengths.empty()) {
            shipLengthTextStr += std::to_string(shipLengths.back());
        }
        else {
            shipLengthTextStr += "0";
        }
        sf::Text shipLengthText(shipLengthTextStr, font);
        shipLengthText.setCharacterSize(20);
        shipLengthText.setFillColor(sf::Color::Green);
        sf::Vector2f shipLengthPosition = calculatePosition(window, shipLengthText.getLocalBounds().width, shipLengthText.getLocalBounds().height);
        shipLengthText.setPosition(headerPosition.x, 80);
        window.draw(shipLengthText);

        const float cellSize = 30.0f;
        sf::Vector2f gridStart = calculatePosition(window, board.getWidth() * cellSize, board.getHeight() * cellSize);
        unsigned int shipLength = !shipLengths.empty() ? shipLengths.back() : 0;

        auto isShipPart = [this, shipLength](unsigned int i, unsigned int j) -> bool {
            if (isVertical) {
                return i == startY && j >= startX && j < startX + shipLength && j < board.getWidth();
            }
            else {
                return j == startX && i >= startY && i < startY + shipLength && i < board.getHeight();
            }
            };

        // Renderowanie planszy
        for (unsigned int i = 0; i <= board.getHeight(); ++i) {
            for (unsigned int j = 0; j <= board.getWidth(); ++j) {
                sf::RectangleShape line(sf::Vector2f(cellSize * board.getWidth(), 1.0f));
                line.setPosition(gridStart.x, gridStart.y + i * cellSize);
                window.draw(line);

                line.setSize(sf::Vector2f(1.0f, cellSize * board.getHeight()));
                line.setPosition(gridStart.x + j * cellSize, gridStart.y);
                window.draw(line);

                char cellValue = board.getCellValue(i, j);
                sf::Text cellText(std::string(1, cellValue), font, 24);
                cellText.setPosition(gridStart.x + j * cellSize + 5, gridStart.y + i * cellSize + 5);

                // Kolorowanie komórek statku na czerwono
                if (isShipPart(i, j)) {
                    cellText.setFillColor(sf::Color::Red);
                }
                else {
                    cellText.setFillColor(sf::Color::White);
                }
                window.draw(cellText);
            }
        }

        // Renderowanie oznaczeñ wierszy i kolumn
        for (unsigned int i = 0; i < board.getHeight(); ++i) {
            sf::Text rowLabel(std::to_string(i + 1), font, 20);
            rowLabel.setPosition(gridStart.x - 20, gridStart.y + i * cellSize + 5);
            window.draw(rowLabel);
        }

        for (unsigned int j = 0; j < board.getWidth(); ++j) {
            sf::Text colLabel(std::string(1, 'A' + j), font, 20);
            colLabel.setPosition(gridStart.x + j * cellSize + 5, gridStart.y - 25);
            window.draw(colLabel);
        }
    }
}


//gettery
Player::PlayerSetupState Player::getSetupState() const {
    return setupState;
}

//settery
void Player::setSetupState(PlayerSetupState state) {
    setupState = state;
}

void Player::setNickname(const std::string& newNickname) {
    nickname = newNickname;
}
//koniec czesci setupu



// czesc gry
bool Player::handleGameEvents(const sf::Event& event, Player& otherPlayer, int& currentPlayer) {
    // Sprawdzanie, czy gracz jest w fazie ataku
    if (gamestate != PlayerGameState::ATTACKING) {
        return false;
    }

    bool turnEnded = false;

    if (event.type == sf::Event::KeyPressed) {
        switch (event.key.code) {
        case sf::Keyboard::Up:
            moveAimUp();
            break;
        case sf::Keyboard::Down:
            moveAimDown();
            break;
        case sf::Keyboard::Left:
            moveAimLeft();
            break;
        case sf::Keyboard::Right:
            moveAimRight();
            break;
        case sf::Keyboard::Enter:
            // Wykonanie strza³u i sprawdzenie, czy trafi³
            bool hit = otherPlayer.getBoard().shootAt(attackY, attackX);
            turnEnded = !hit;
            break;
        }

        // Jeœli tura zakoñczona, prze³¹czenie gracza i aktualizacja stanu gry
        if (turnEnded) {
            currentPlayer = (currentPlayer == 1) ? 2 : 1;
            setGameState(PlayerGameState::WAITING);
            otherPlayer.setGameState(PlayerGameState::ATTACKING);

            // Sprawdzenie warunków zakoñczenia gry
            if (allShipsSunk()) {
                setGameState(PlayerGameState::GAME_OVER);
                otherPlayer.setGameState(PlayerGameState::GAME_OVER);
            }
        }

        return turnEnded;
    }

    // Drugi sposób obs³ugi zakoñczenia tury (zgodny z poprzednim, bez powtarzania kodu)
    if (turnEnded) {
        currentPlayer = (currentPlayer == 1) ? 2 : 1;
        setGameState(PlayerGameState::WAITING);
        otherPlayer.setGameState(PlayerGameState::ATTACKING);

        // Sprawdzenie warunków zakoñczenia gry
        if (allShipsSunk() || otherPlayer.allShipsSunk()) {
            setGameState(PlayerGameState::GAME_OVER);
            otherPlayer.setGameState(PlayerGameState::GAME_OVER);
        }
    }

    return turnEnded;
}

void Player::renderGame(sf::RenderWindow& window, const sf::Font& font, const Player& enemyPlayer) {
    // Renderowanie informacji o turze gracza
    sf::Text infoText;
    infoText.setFont(font);
    infoText.setCharacterSize(20);
    infoText.setFillColor(sf::Color::White);
    infoText.setString("Tura: " + nickname + "\n");

    sf::Vector2f infoTextPosition = calculatePosition(window, infoText.getLocalBounds().width, infoText.getLocalBounds().height);
    infoText.setPosition(infoTextPosition.x, 10);
    window.draw(infoText);

    // Wybór planszy do renderowania w zale¿noœci od stanu gry
    const Board& boardToRender = (gamestate == PlayerGameState::ATTACKING) ? enemyPlayer.board : board;
    const float cellSize = 30.0f;

    sf::Vector2f gridStart = calculatePosition(window, boardToRender.getWidth() * cellSize, boardToRender.getHeight() * cellSize);

    // Renderowanie planszy
    for (unsigned int i = 0; i <= boardToRender.getHeight(); ++i) {
        for (unsigned int j = 0; j <= boardToRender.getWidth(); ++j) {
            sf::RectangleShape line(sf::Vector2f(cellSize * boardToRender.getWidth(), 1.0f));
            line.setPosition(gridStart.x, gridStart.y + i * cellSize);
            window.draw(line);

            line.setSize(sf::Vector2f(1.0f, cellSize * boardToRender.getHeight()));
            line.setPosition(gridStart.x + j * cellSize, gridStart.y);
            window.draw(line);

            if (i < boardToRender.getHeight() && j < boardToRender.getWidth()) {
                char cellValue = boardToRender.getCellValue(i, j);
                if (cellValue == 'S' && gamestate == PlayerGameState::ATTACKING) {
                    cellValue = '.';
                }

                sf::Text cellText(std::string(1, cellValue), font, 24);
                cellText.setPosition(gridStart.x + j * cellSize + 5, gridStart.y + i * cellSize + 5);

                // Kolorowanie komórek podczas ataku gracza
                if (gamestate == PlayerGameState::ATTACKING && i == attackY && j == attackX) {
                    cellText.setFillColor(sf::Color::Red);
                }
                else {
                    cellText.setFillColor(cellValue == 'X' ? sf::Color::Red :
                        cellValue == 'M' ? sf::Color::Blue : sf::Color::White);
                }

                window.draw(cellText);
            }
        }
    }

    // Renderowanie oznaczeñ wierszy i kolumn
    for (unsigned int i = 0; i < boardToRender.getHeight(); ++i) {
        sf::Text rowLabel(std::to_string(i + 1), font, 20);
        rowLabel.setPosition(gridStart.x - 20, gridStart.y + i * cellSize + 5);
        window.draw(rowLabel);
    }

    for (unsigned int j = 0; j < boardToRender.getWidth(); ++j) {
        sf::Text colLabel(std::string(1, 'A' + j), font, 20);
        colLabel.setPosition(gridStart.x + j * cellSize + 5, gridStart.y - 25);
        window.draw(colLabel);
    }
}



//settery
void Player::setGameState(PlayerGameState state) {
    gamestate = state;
}

void Player::moveAimUp() {
    if (attackY > 0) --attackY;
}

void Player::moveAimDown() {
    if (attackY < board.getHeight() - 1) ++attackY;
}

void Player::moveAimLeft() {
    if (attackX > 0) --attackX;
}

void Player::moveAimRight() {
    if (attackX < board.getWidth() - 1) ++attackX;
}

//gettery
Board& Player::getBoard() {
    return board;
}

std::string Player::getName() const
{
    return nickname;
}

std::pair<int, int> Player::getAim() const {
    return std::make_pair(aimX, aimY);
}

Player::PlayerGameState Player::getGameState() const {
    return PlayerGameState();
}

bool Player::allShipsSunk() const {
    return board.areAllShipsSunk();
}

//do renderingu
sf::Vector2f Player::calculatePosition(sf::RenderWindow& window, float width, float height) {
    // Pobranie szerokoœci i wysokoœci okna
    float windowWidth = static_cast<float>(window.getSize().x);
    float windowHeight = static_cast<float>(window.getSize().y);

    // Obliczenie pozycji startowej, aby skoncentrowaæ obiekt na ekranie
    float startX = (windowWidth - width) / 2.0f;
    float startY = (windowHeight - height) / 2.0f;

    // Zwrócenie obliczonej pozycji jako obiektu sf::Vector2f
    return sf::Vector2f(startX, startY);
}


