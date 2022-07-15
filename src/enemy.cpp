#include "enemy.h"


bool Enemy::load(const std::string& tex) {
    if (!enemy_tex_.loadFromFile(tex))
        return false;
    enemy_pos_.x = 21 * sizeS;
    enemy_pos_.y = 12 * sizeS;
}

void Enemy::draw(sf::RenderTarget& target, sf::RenderStates states) const  {
    sf::Sprite enemy(enemy_tex_);

    enemy.setScale(sf::Vector2f(-5.f, 5.f));
    enemy.setPosition(enemy_pos_.x, enemy_pos_.y);

    target.draw(enemy);
}