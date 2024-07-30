#ifndef NPC_HPP
#define NPC_HPP

#include <SFML/Graphics.hpp>
#include <vector>
#include <string>

class NPC {
public:
    std::string name;
    std::vector<std::string> dialogues;
    sf::Sprite sprite;

    void draw(sf::RenderWindow &window) const; // Adicionando const
};

private:
    std::string name;
    sf::Sprite sprite;
    sf::Texture texture;
    std::string dialogue;
};

#endif // NPC_HPP
