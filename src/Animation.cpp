/**
 *
 */

#include "Animation.h"
#include <iostream>

using namespace std;

Animation::Animation(sf::Texture* texture, sf::Vector2u imageCount, float switchTime)
{
    this->imageCount = imageCount;
    this->switchTime = switchTime;
    totalTime = 0.0f;
    currentImage.x = 0;

    uvRect.width  = texture->getSize().x / float(imageCount.x);
    uvRect.height = texture->getSize().y / float(imageCount.y);
    //cout << "uvRect.width = " << uvRect.width << endl;
    //cout << "uvRect.height = " << uvRect.height << endl;
}

Animation::~Animation()
{
    //
}

void Animation::Update(int row, float deltaTime)
{
    currentImage.y = row;
    totalTime += deltaTime;

    if (totalTime >= switchTime)
    {
        totalTime -= switchTime;
        currentImage.x++;

        // as we loop through the sprite x axis, reset to 0 when we try to go past the last frame
        if (currentImage.x >= imageCount.x)
        {
            currentImage.x = 0;
        }
    }

    uvRect.left = currentImage.x * uvRect.width;
}
