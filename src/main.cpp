
#include "constants.h"
#include "map.h"
#include "hero.h"
#include "attack.h"
#include "enemy.h"

int main() {
    sf::RenderWindow window(sf::VideoMode(640, 480), "demo");

    std::string a = "block.png";
    std::string b = "map.txt";

    Map map;
    if (!map.load("map.txt", "map.png"))
        return -1;

    Hero hero;
    if (!hero.load("hero.png"))
        return -1;

    Attack attack("attack.png", sf::Vector2i(10, 13), /*moving_right=*/true);
   
    Enemy enemy;
    if (!enemy.load("enemy.png"))
        return -1;

    Attack attack_enemy("attack_enemy.png", sf::Vector2i(16, 13), /*moving_right=*/false);

    sf::Clock clock;
    float timer = 0, delay = 0.1;

    sf::Vector2i CurrentPos = hero.Hero_Pos();

    int dir = 0;
    bool die_enemy = false;
    bool die_hero = false;
    bool players_move = true;
    int health_hero = 3;
    int health_enemy = 3;
    float die_enemy_timer = 0;
    float die_hero_timer = 0;
    float shot_enemy_timer = 0;
    while (window.isOpen())
    {
        float time = clock.getElapsedTime().asSeconds();
        clock.restart();
        timer += time;
        if (die_enemy == true)
            die_enemy_timer += time;
        if (die_hero == true)
            die_hero_timer += time;
        if (players_move == false && die_enemy == false)
            shot_enemy_timer += time;
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed) {
                window.close();

            }
            if (event.type == sf::Event::KeyPressed) {
                if (event.key.code == sf::Keyboard::Escape) {
                    window.close();
                }
                if (event.key.code == sf::Keyboard::E) {
                    dir = 1;
                }
            }
        }
        window.draw(map);
        if (timer > delay) {
            if (players_move == true) {
                if (dir == 1)
                    attack.UpdatePhysics();
            }
            else if(shot_enemy_timer >= 3)
                attack_enemy.UpdatePhysics();
            timer = 0;
        }
        if (attack.Attack_Pos().x >= 19 ) {
            dir = 0;
            attack = Attack("attack.png", sf::Vector2i(10, 13), /*moving_right=*/true);;
            --health_enemy;
            players_move = false;
        }
        if (attack_enemy.Attack_Pos().x <= 12) {
            shot_enemy_timer = 0;
            attack_enemy.Reset();
            players_move = true;
           --health_hero;
        }

        if (health_enemy == 0)
            die_enemy = true;

        if (health_hero == 0)
            die_hero = true;

        if (die_enemy_timer >= 5) {
            die_enemy = false;
            health_enemy = 3;
            die_enemy_timer = 0;
        }
        if (die_hero_timer >= 5) {
            die_hero = false;
            health_hero = 3;
            die_hero_timer = 0;
        }
      
        if(die_enemy == false)
            window.draw(enemy);
        if (die_hero == false)
            window.draw(hero);
        if (shot_enemy_timer >= 3 && players_move == false) 
            window.draw(attack_enemy);
        if (dir == 1)
            window.draw(attack);
        window.display();
    }
    return 0;
}


