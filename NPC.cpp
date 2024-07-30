#include "NPC.hpp"

NPC::NPC(const std::string &name, const sf::Vector2f &position, const std::string &dialogue) 
    : name(name), dialogue(dialogue) {
    // Carregar a textura e definir a posição inicial
    if (!texture.loadFromFile("npc.png")) {
        // Handle error
    }
    sprite.setTexture(texture);
    sprite.setPosition(position);
}

void NPC::draw(sf::RenderWindow &window) {
    window.draw(sprite);
}

const sf::FloatRect NPC::getBounds() const {
    return sprite.getGlobalBounds();
}

const std::string& NPC::getDialogue() const {
    return dialogue;
}
