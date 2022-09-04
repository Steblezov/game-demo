#include "hero.h"

bool Hero::load(const std::string& tex) {
    if (!hero_tex_.loadFromFile(tex))
        return false;
    hero_pos_.x = 5 * sizeS;
    hero_pos_.y = 12 * sizeS;

}

const sf::Vector2i& Hero::Hero_Pos()const {
    return hero_pos_;
}

void Hero::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
    sf::Sprite hero(hero_tex_);

    hero.setScale(sf::Vector2f(5.f, 5.f));
    hero.setPosition(hero_pos_.x, hero_pos_.y);


    target.draw(hero);
}