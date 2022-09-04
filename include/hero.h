#pragma once

#include <SFML/Graphics.hpp>
#include "constants.h"
class Hero : public sf::Drawable {
public:
    bool load(const std::string&tex);

    const sf::Vector2i& Hero_Pos()const;

private:
    void draw(sf::RenderTarget& target, sf::RenderStates states) const ;
    sf::Vector2i hero_pos_;
    sf::Texture hero_tex_;
};