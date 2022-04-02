
#include "constants.h"
#include "map.h"

class Hero : public sf::Drawable, public sf::Transformable {
public:
    bool load(const std::string& tileset){
        if (!m_tileset_.loadFromFile(tileset))
            return false;

        m_vertices_.setPrimitiveType(sf::Quads);
        m_vertices_.resize(sizeS * sizeS * 4);

        m_vertices_[0].position = sf::Vector2f(3 * sizeS, 17* sizeS);
        m_vertices_[1].position = sf::Vector2f(3 * sizeS, 14 * sizeS);
        m_vertices_[2].position = sf::Vector2f(6 * sizeS, 14 * sizeS);
        m_vertices_[3].position = sf::Vector2f(6 * sizeS, 17 * sizeS);

        m_vertices_ [0].texCoords = sf::Vector2f(0, 24);
        m_vertices_ [1].texCoords = sf::Vector2f(0, 0);
        m_vertices_ [2].texCoords = sf::Vector2f(24, 0);
        m_vertices_ [3].texCoords = sf::Vector2f(24, 24);
    }
    void UpdatePhysics() {
        switch (dir_) {
        case 1:
            m_vertices_[0].position.x += 1 * sizeS;
            m_vertices_[1].position.x += 1 * sizeS; 
            m_vertices_[2].position.x += 1 * sizeS;          
            m_vertices_[3].position.x += 1 * sizeS;          
            break;
        case  2:
            m_vertices_[0].position.x -= 1 * sizeS;
            m_vertices_[1].position.x -= 1 * sizeS;
            m_vertices_[2].position.x -= 1 * sizeS;
            m_vertices_[3].position.x -= 1 * sizeS;
            break;
        }
    }
    void UpdateFrame(int x,int y) {
        m_vertices_[0].texCoords = sf::Vector2f(x, y + 24);
        m_vertices_[1].texCoords = sf::Vector2f(x, y);
        m_vertices_[2].texCoords = sf::Vector2f(x + 24, y);
        m_vertices_[3].texCoords = sf::Vector2f(x + 24, y + 24);
    }
    void SetDir(int dir) {
        dir_ = dir;
    }

private:
    void draw(sf::RenderTarget& target, sf::RenderStates states) const override
    {
        states.transform *= getTransform();

        states.texture = &m_tileset_;

        target.draw(m_vertices_, states);
    }
    sf::VertexArray m_vertices_;
    sf::Texture m_tileset_;
    int dir_;
    float CurrentFrame_;
};


 
int main() {
    sf::RenderWindow window(sf::VideoMode(640, 480), "demo");

    std::string a = "block.png";
    std::string b = "map.txt";
    Map map;
    if (!map.load("map.txt", "block.png"))
        return -1;

    Hero hero;
    if (!hero.load("hero.png"))
        return -1;

    sf::Clock clock;
    float timer = 0, delay = 0.05;

    float CurrentFrame = 0;
    while (window.isOpen())
    {
        float time = clock.getElapsedTime().asSeconds();
        clock.restart();
        timer += time;
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
                if (event.key.code == sf::Keyboard::Right) {
                    CurrentFrame +=  time;
                    
                    hero.SetDir(1);
                }
                if (event.key.code == sf::Keyboard::Left) {
                    hero.SetDir(2);
                }
            }
            else {
                hero.SetDir(0);
                hero.UpdateFrame(0, 0);
            }
            

        }
        if (int(CurrentFrame) == 1) {
            hero.UpdateFrame(24, 0);
        }
        if (int(CurrentFrame) == 2) {
            hero.UpdateFrame(48, 0);
        }
        if (int(CurrentFrame) > 2) {
            CurrentFrame = 0;
        }
        if (timer > delay) {
            timer = 0;
            hero.UpdatePhysics();
        }
        window.clear(sf::Color::White);
        window.draw(map);
        window.draw(hero);
        window.display();
    }
    return 0;
    }


