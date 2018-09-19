/**
 *
 */

#include "Player.h"

using namespace std;

Player::Player(sf::Texture* texture, sf::Vector2u imageCount, float switchTime, float speed) :
    animation(texture, imageCount, switchTime)
{
    this->speed = speed;
    row = 0;
    faceRight = true;


    //body.setSize(sf::Vector2f(128.0f, 128.0f));
    //body.setOrigin(64.0f, 64.0f);
    body.setSize(sf::Vector2f(96.0f, 96.0f));
    body.setOrigin(texture->getSize().x / float(imageCount.x), texture->getSize().y / float(imageCount.y));
    body.setPosition(400.0f, 300.0f);
    body.setTexture(texture);
}

Player::~Player()
{
    //
}

void Player::Update(float deltaTime)
{
    sf::Vector2f movement(0.0f, 0.0f);

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::W) || sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
    {
        movement.y -= speed * deltaTime;
        row = 3;
        faceRight = false;
    }

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::S) || sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
    {
        movement.y += speed * deltaTime;
        row = 1;
        faceRight = false;
    }

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::A) || sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
    {
        movement.x -= speed * deltaTime;
        row = 2;
        faceRight = false;
    }

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::D) || sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
    {
        movement.x += speed * deltaTime;
        row = 0;
        faceRight = true;
    }


    animation.Update(row, deltaTime, faceRight);
    body.setTextureRect(animation.uvRect);
    body.move(movement);
}

void Player::Draw(sf::RenderWindow& window)
{
    window.draw(body);
}
