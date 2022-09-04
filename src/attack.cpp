#include "attack.h"

Attack::Attack(const std::string& tex, const sf::Vector2i& initial_attack_pos, bool moving_right) 
        : initial_attack_pos_(initial_attack_pos), attack_pos_(initial_attack_pos), moving_right_(moving_right) {
    if (!attack_tex_.loadFromFile(tex))
        exit(1);
}
void Attack::UpdatePhysics() {
    if (moving_right_ == true)
        ++attack_pos_.x;
    else {
        --attack_pos_.x;
    }
}

void Attack::Reset() {
    attack_pos_ = initial_attack_pos_;
}

const sf::Vector2i& Attack::Attack_Pos()const {
    return attack_pos_;
}

void Attack::draw(sf::RenderTarget& target, sf::RenderStates states) const 
{
    sf::Sprite attack(attack_tex_);
    attack.setPosition(attack_pos_.x * sizeS, attack_pos_.y * sizeS);
    if (!moving_right_) {
        attack.setScale(sf::Vector2f(-1.f, 1.f));
    }
    target.draw(attack);
}