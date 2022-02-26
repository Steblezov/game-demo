#pragma once
#include <SFML/Graphics.hpp>
#include "constants.h"

class Map : public sf::Drawable, public sf::Transformable {
public:

    virtual ~Map() {}

    bool load(std::string level, std::string tileset);

private:
    virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;
    std::vector<int> number_;
    sf::VertexArray m_vertices_;
    sf::Texture m_tileset_;

};