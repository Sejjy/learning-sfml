#include <SFML/Graphics.hpp>

int main() {
    sf::RenderWindow window(sf::VideoMode(800, 600), "Game");
    window.setFramerateLimit(60);

    // Paddle
    sf::RectangleShape paddle(sf::Vector2f(100.0f, 20.0f));
    paddle.setPosition(350.0f, 550.0f);

    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        // Movement
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::A) && paddle.getPosition().x > 0)
            paddle.move(-5.0f, 0.0f);
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::D) && paddle.getPosition().x + paddle.getSize().x < 800)
            paddle.move(5.0f, 0.0f);

        window.clear();
        window.draw(paddle);
        window.display();
    }

    return 0;
}