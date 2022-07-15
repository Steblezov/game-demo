#pragma once

#include <SFML/Graphics.hpp>
#include "constants.h"

class Attack : public sf::Drawable {
public:
    bool load(const std::string& tex);

    void UpdatePhysics();

    const sf::Vector2i& Attack_Pos()const;

    void SetDir(int dir);

private:
    void draw(sf::RenderTarget& target, sf::RenderStates states) const override;
    sf::Vector2i attack_pos_;
    sf::Texture attack_tex_;
    int dir_;
};