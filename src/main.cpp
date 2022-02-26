
#include "constants.h"
#include "map.h"


 
int main() {
    sf::RenderWindow window(sf::VideoMode(640, 480), "demo");
   
    std::string a = "block.png";
    std::string b = "map.txt";
    Map map;
    if (!map.load("map.txt","block.png"))
        return -1;

  
    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        window.clear(sf::Color::White);
        window.draw(map);

        window.display();
    }
    return 0;
}

