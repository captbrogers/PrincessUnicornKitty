#include <SFML/Graphics.hpp>
#include <iostream>
#include "Animation.h"

using namespace std;

int main()
{
    // Create the main window
    sf::RenderWindow window(sf::VideoMode(800, 600), "SFML Game", sf::Style::Close | sf::Style::Resize);
    sf::RectangleShape player(sf::Vector2f(128.0f, 128.0f));
    //player.setFillColor(sf::Color::Magenta);
    player.setOrigin(64.0f, 64.0f);
    player.setPosition(400.0f, 300.0f);

    bool isWalkingUp = false;
    bool isWalkingRight = true;
    bool isWalkingDown = false;
    bool isWalkingLeft = false;

    // Load a sprite to display
    sf::Texture saraSpriteWalkingRight;
    if (!saraSpriteWalkingRight.loadFromFile("resources/LPC_Sara/characters/WalkingRight.png")) {
        return EXIT_FAILURE;
    }
    sf::Texture saraSpriteWalkingLeft;
    if (!saraSpriteWalkingLeft.loadFromFile("resources/LPC_Sara/characters/WalkingLeft.png")) {
        return EXIT_FAILURE;
    }
    sf::Texture saraSpriteWalkingUp;
    if (!saraSpriteWalkingUp.loadFromFile("resources/LPC_Sara/characters/WalkingUp.png")) {
        return EXIT_FAILURE;
    }
    sf::Texture saraSpriteWalkingDown;
    if (!saraSpriteWalkingDown.loadFromFile("resources/LPC_Sara/characters/WalkingDown.png")) {
        return EXIT_FAILURE;
    }
    //sf::Sprite sprite(texture);
    player.setTexture(&saraSpriteWalkingRight);
    Animation animation(&saraSpriteWalkingRight, sf::Vector2u(8, 1), 0.1f);

    float deltaTime = 0.0f;
    sf::Clock clock;


	// Start the game loop
    while (window.isOpen())
    {
        deltaTime = clock.restart().asSeconds();

        // Process events
        sf::Event event;
        while (window.pollEvent(event))
        {
            // Close window : exit
            if (event.type == sf::Event::Closed) {
                cout << "Closing window, better save the game." << endl;
                window.close();
            }

            // Resize window : redraw layout?
            if (event.type == sf::Event::Resized) {
                // cout << "Resized window to: " << event.size.width << "x" << event.size.height << endl;
            }
        }

        animation.Update(0, deltaTime);
        player.setTextureRect(animation.uvRect);


        /**
         * Keyboard mapping stuff
         */
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::W) || sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) {
            // cout << "The 'W' key pressed" << endl;
            player.move(0.0f, -0.05f);

            if (!isWalkingUp)
            {
                isWalkingUp = true;
                isWalkingRight = false;
                isWalkingDown = false;
                isWalkingLeft = false;
                player.setTexture(&saraSpriteWalkingUp);
                Animation animation(&saraSpriteWalkingUp, sf::Vector2u(8, 1), 0.1f);

                animation.Update(0, deltaTime);
                player.setTextureRect(animation.uvRect);
            }
        }

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::S) || sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) {
            // cout << "The 'S' key pressed" << endl;
            player.move(0.0f, 0.05f);

            if (!isWalkingDown)
            {
                isWalkingUp = false;
                isWalkingRight = false;
                isWalkingDown = true;
                isWalkingLeft = false;
                player.setTexture(&saraSpriteWalkingDown);
                Animation animation(&saraSpriteWalkingDown, sf::Vector2u(8, 1), 0.1f);

                animation.Update(0, deltaTime);
                player.setTextureRect(animation.uvRect);
            }
        }

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::A) || sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
            // cout << "The 'A' key pressed" << endl;
            player.move(-0.05f, 0.0f);

            if (!isWalkingLeft)
            {
                isWalkingUp = false;
                isWalkingRight = false;
                isWalkingDown = false;
                isWalkingLeft = true;
                player.setTexture(&saraSpriteWalkingLeft);
                Animation animation(&saraSpriteWalkingLeft, sf::Vector2u(8, 1), 0.1f);

                animation.Update(0, deltaTime);
                player.setTextureRect(animation.uvRect);
            }
        }

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::D) || sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
            // cout << "The 'D' key pressed" << endl;
            player.move(0.05f, 0.0f);

            if (!isWalkingRight)
            {
                isWalkingUp = false;
                isWalkingRight = true;
                isWalkingDown = false;
                isWalkingLeft = false;
                player.setTexture(&saraSpriteWalkingRight);
                Animation animation(&saraSpriteWalkingRight, sf::Vector2u(8, 1), 0.1f);

                animation.Update(0, deltaTime);
                player.setTextureRect(animation.uvRect);
            }


        }

        /*if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
            sf::Vector2i mousePosition = sf::Mouse::getPosition(window);
            //player.setPosition((float)mousePosition.x, static_cast<float>mousePosition.y);
            player.setPosition((float)mousePosition.x, (float)mousePosition.y);
        }*/

        // Clear screen
        window.clear();

        // Draw the sprite
        // window.draw(sprite);

        // Draw the player sprite
        window.draw(player);

        // Update the window
        window.display();
    }

    return EXIT_SUCCESS;
}
