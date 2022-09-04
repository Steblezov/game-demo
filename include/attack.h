#pragma once

#include <SFML/Graphics.hpp>
#include "constants.h"

class Attack : public sf::Drawable {
public:
    Attack(const std::string& tex, const sf::Vector2i& initial_attack_pos, bool moving_right);

    void UpdatePhysics();

    void Reset();

    const sf::Vector2i& Attack_Pos()const;

private:
    void draw(sf::RenderTarget& target, sf::RenderStates states) const override;
    sf::Vector2i initial_attack_pos_;
    sf::Vector2i attack_pos_;
    sf::Texture attack_tex_;
    bool moving_right_;
};