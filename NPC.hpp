#ifndef NPC_HPP
#define NPC_HPP

#include <SFML/Graphics.hpp>
#include <string>

class NPC {
public:
    NPC(const std::string &name, const sf::Vector2f &position, const std::string &dialogue);
    
    void draw(sf::RenderWindow &window);
    const sf::FloatRect getBounds() const;
    const std::string& getDialogue() const;

private:
    std::string name;
    sf::Sprite sprite;
    sf::Texture texture;
    std::string dialogue;
};

#endif // NPC_HPP
