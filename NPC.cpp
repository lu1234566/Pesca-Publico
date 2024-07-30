#include "NPC.hpp"

NPC::NPC(const std::string &name, const sf::Vector2f &position, const std::string &dialogue)
    : name(name), position(position), dialogue(dialogue) {
    if (!texture.loadFromFile("npc.gif")) {
        std::cerr << "Erro ao carregar a textura do NPC" << std::endl;
    }
    sprite.setTexture(texture);
    sprite.setPosition(position);
}

void NPC::draw(sf::RenderWindow &window) const {
    window.draw(sprite);
}

sf::FloatRect NPC::getBounds() const {
    return sprite.getGlobalBounds();
}

std::string NPC::getDialogue() const {
    return dialogue;
}
