#include <SFML/Window.hpp>
#include <SFML/System.hpp>
#include <SFML/Graphics.hpp>

constexpr unsigned int ropeSize = 800;
constexpr unsigned int windowHeight = 400;

int main(void) {
    sf::RenderWindow window(sf::VideoMode(ropeSize, windowHeight), "Rope Physics", sf::Style::Close);
    sf::VertexArray rope(sf::Points, ropeSize);

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

        window.draw(rope);
        window.display();
   }
    return 0;
}