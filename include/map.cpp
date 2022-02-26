#include "map.h"

bool Map::load(std::string level, std::string tileset) {
    if (!m_tileset_.loadFromFile(tileset))
        return false;

    std::fstream file(level);
    for (int i = 0; i < map_H * map_W; ++i) {
        int a;
        file >> a;
        number_.push_back(a);
    }


    m_vertices_.setPrimitiveType(sf::Quads);
    m_vertices_.resize(map_W * map_H * 4);

    for (int i = 0; i < map_W; ++i)
        for (int j = 0; j < map_H; ++j)
        {
            int tileNumber = number_[i + j * map_W];

            int tu = tileNumber % (m_tileset_.getSize().x / sizeS);
            int tv = tileNumber / (m_tileset_.getSize().x / sizeS);

            sf::Vertex* quad = &m_vertices_[(i + j * map_W) * 4];

            quad[0].position = sf::Vector2f(i * sizeS, j * sizeS);
            quad[1].position = sf::Vector2f((i + 1) * sizeS, j * sizeS);
            quad[2].position = sf::Vector2f((i + 1) * sizeS, (j + 1) * sizeS);
            quad[3].position = sf::Vector2f(i * sizeS, (j + 1) * sizeS);

            quad[0].texCoords = sf::Vector2f(tu * sizeS, tv * sizeS);
            quad[1].texCoords = sf::Vector2f((tu + 1) * sizeS, tv * sizeS);
            quad[2].texCoords = sf::Vector2f((tu + 1) * sizeS, (tv + 1) * sizeS);
            quad[3].texCoords = sf::Vector2f(tu * sizeS, (tv + 1) * sizeS);
        }
    return true;
}

void Map::draw(sf::RenderTarget& target, sf::RenderStates states) const 
{
    states.transform *= getTransform();

    states.texture = &m_tileset_;

    target.draw(m_vertices_, states);
}