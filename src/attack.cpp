#include "attack.h"

bool Attack::load(const std::string& tex) {
    if (!attack_tex_.loadFromFile(tex))
        return false;
    attack_pos_.x = 10;
    attack_pos_.y = 13;
}
void Attack::UpdatePhysics() {
    if (dir_ == 1) {
        ++attack_pos_.x;
    }
    else {
        attack_pos_.x = 10;
        attack_pos_.y = 13;
    }
}

const sf::Vector2i& Attack::Attack_Pos()const {
    return attack_pos_;
}
void Attack::SetDir(int dir) {
    dir_ = dir;
}

void Attack::draw(sf::RenderTarget& target, sf::RenderStates states) const 
{
    sf::Sprite attack(attack_tex_);
    attack.setPosition(attack_pos_.x * sizeS, attack_pos_.y * sizeS);
    target.draw(attack);
}