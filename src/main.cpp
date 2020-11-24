#include <SFML/Window.hpp>
#include <SFML/System.hpp>
#include <SFML/Graphics.hpp>

constexpr unsigned int ropeSize = 800;
constexpr unsigned int windowHeight = 400;

signed int CoordsHeight(sf::RenderWindow &window) {
    sf::Vector2i localPosition = sf::Mouse::getPosition(window);
    return localPosition.y - (windowHeight / 2);
}

bool isMouseLeftReleased() {
    static bool click = false;
    if (click == true && !(sf::Mouse::isButtonPressed(sf::Mouse::Left))) {
        click = false;
        return true;
    }
    else if (click == false && sf::Mouse::isButtonPressed(sf::Mouse::Left))
        click = true;
    return false;
}

unsigned int positiveNumberConvert(signed int number) {
    if (number < 0)
        number *= -1;
    return number;
}

void clickRelease(sf::RenderWindow& window, signed int ropePositionY[]) {
    if (isMouseLeftReleased()) {
        signed int mouseHeight = CoordsHeight(window);
        if (sf::Mouse::getPosition(window).x < ropeSize && sf::Mouse::getPosition(window).x >= 0) {
            ropePositionY[sf::Mouse::getPosition(window).x] = CoordsHeight(window);
            for (unsigned int i = 0; i < positiveNumberConvert(CoordsHeight(window)); i++) {

            }
        }
    }
}

int main(void) {
    sf::RenderWindow window(sf::VideoMode(ropeSize, windowHeight), "Rope Physics", sf::Style::Close);
    sf::VertexArray rope(sf::Points, ropeSize);
    signed int ropePositionY[ropeSize] = { 0 };

    for (unsigned int i = 0; i < ropeSize; i++) {
        rope[i].position = sf::Vector2f((float)i, (float)(windowHeight / 2));
    }

    window.setVerticalSyncEnabled(true);
    while (window.isOpen()) {
        sf::sleep(sf::microseconds(33'333));
        window.clear(sf::Color::Black);
        sf::Event event;
        while (window.pollEvent(event)) {
            switch (event.type) {
                case sf::Event::Closed:
                    window.close();
                    break;

                default:
                    break;
            }
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
            window.close();

        clickRelease(window, ropePositionY);

        window.draw(rope);
        window.display();
   }
    return 0;
}