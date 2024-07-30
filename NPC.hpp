#ifndef NPC_HPP
#define NPC_HPP

#include <SFML/Graphics.hpp>
#include <string>
#include <iostream>

class NPC {
public:
    NPC(const std::string &name, const sf::Vector2f &position, const std::string &dialogue);

    void draw(sf::RenderWindow &window) const;
    sf::FloatRect getBounds() const;
    std::string getDialogue() const;

private:
    std::string name;
    sf::Vector2f position;
    std::string dialogue;
    sf::Texture texture;
    sf::Sprite sprite;
};

#endif // NPC_HPP
