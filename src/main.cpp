#include <SFML/Graphics.hpp>
#include <iostream>
#include "Player.h"

using namespace std;

static const float VIEW_HEIGHT = 512.0f;

void ResizeView(sf::RenderWindow& window, sf::View& view)
{
    float aspectRatio = float(window.getSize().x) / float(window.getSize().y);
    view.setSize(VIEW_HEIGHT * aspectRatio, VIEW_HEIGHT);
}

int main()
{
    unsigned int maxHeight = 1920;
    unsigned int maxWidth = 1080;
    float resolutionPercent = 0.65f;
    unsigned int screenHeight = maxHeight * resolutionPercent;
    unsigned int screenWidth = maxWidth * resolutionPercent;
    sf::Vector2i screenDimensions(screenHeight, screenWidth);

    // Create the main window
    sf::RenderWindow window(sf::VideoMode(screenDimensions.x, screenDimensions.y), "Princess Unicorn Kitty", sf::Style::Close | sf::Style::Resize);
    window.setFramerateLimit(120);

    sf::View view(sf::Vector2f(0.0f, 0.0f), sf::Vector2f((float)screenDimensions.x, (float)screenDimensions.y));

    // Load a sprite to display
    sf::Texture saraSpriteWalking;
    if (!saraSpriteWalking.loadFromFile("resources/LPC_Sara/characters/WalkingAll.png")) {
        return EXIT_FAILURE;
    }

    float animationCycleSpeed = 0.075f;
    float movementSpeed = 192.0f;
    Player player(&saraSpriteWalking, sf::Vector2u(8, 4), animationCycleSpeed, movementSpeed);

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
            if (event.type == sf::Event::Closed)
            {
                cout << "Closing window, better save the game." << endl;
                window.close();
            }

            if (event.type == sf::Event::Resized)
            {
                ResizeView(window, view);
                // cout << "Resized window to: " << event.size.width << "x" << event.size.height << endl;
            }
        }
        /*if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
            sf::Vector2i mousePosition = sf::Mouse::getPosition(window);
            //player.setPosition((float)mousePosition.x, static_cast<float>mousePosition.y);
            player.setPosition((float)mousePosition.x, (float)mousePosition.y);
        }*/

        player.Update(deltaTime);
        view.setCenter(player.GetPosition());

        // Clear screen
        window.clear(sf::Color::Black);
        window.setView(view);

        player.Draw(window);

        // Update the window
        window.display();
    }

    return EXIT_SUCCESS;
}
