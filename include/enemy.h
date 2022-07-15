#pragma once

#include <SFML/Graphics.hpp>
#include "constants.h"

class Enemy : public sf::Drawable {
public:
    bool load(const std::string& tex);

private:
    void draw(sf::RenderTarget& target, sf::RenderStates states) const override;
    sf::Vector2i enemy_pos_;
    sf::Texture enemy_tex_;
};

