/**
 *
 */

#ifndef ANIMATION_H
#define ANIMATION_H

#include <SFML/Graphics.hpp>

class Animation
{
    public:
        Animation(sf::Texture* texture, sf::Vector2u imageCount, float switchTime);
        ~Animation();

        void Update(unsigned int row, float deltaTime, bool faceRight);

        sf::IntRect uvRect;

    protected:


    private:
        // how many frames in the animation cycle
        sf::Vector2u imageCount;

        // which sprite sheet we have loaded
        sf::Vector2u currentImage;

        float totalTime;
        float switchTime;
};

#endif // ANIMATION_H
