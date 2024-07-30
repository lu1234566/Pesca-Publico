#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <iostream>
#include <vector>
#include <string>
#include <ctime>
#include "NPC.hpp"

using namespace std;
using namespace sf;

// Configurações
int hour = 12;
int minute = 0;
bool isFishing = false;
bool isPaused = false;
int fontSize = 20;
vector<string> inventory;
vector<string> baitTypes = {"Worm", "Fly", "Spinner"};
int selectedBaitIndex = 0;
vector<Texture> fishTextures;
vector<Sprite> fishSprites;
vector<NPC> npcs;
Texture backgroundTexture, npcTexture, fishTexture;
SoundBuffer castSoundBuffer, catchSoundBuffer;
Sound castSound, catchSound;

// Estruturas
struct Fish {
    string name;
    Texture texture;
};

// Funções de carregamento e inicialização
bool loadAssets() {
    if (!backgroundTexture.loadFromFile("background.gif")) return false;
    if (!npcTexture.loadFromFile("npc.gif")) return false;
    if (!fishTexture.loadFromFile("fish.gif")) return false;
    if (!castSoundBuffer.loadFromFile("cast.wav")) return false;
    if (!catchSoundBuffer.loadFromFile("catch.wav")) return false;

    castSound.setBuffer(castSoundBuffer);
    catchSound.setBuffer(catchSoundBuffer);

    return true;
}

void loadNPCs() {
    NPC npc1("Pescador João", sf::Vector2f(300, 300), "Olá, pescador! Dicas para hoje?");
    npcs.push_back(npc1);
}

void displayHUD(RenderWindow &window, Font &font) {
    Text timeText("Hora: " + to_string(hour) + ":" + (minute < 10 ? "0" : "") + to_string(minute), font, 20);
    timeText.setFillColor(Color::White);
    timeText.setPosition(10, 10);
    window.draw(timeText);

    Text baitText("Isca: " + baitTypes[selectedBaitIndex], font, 20);
    baitText.setFillColor(Color::White);
    baitText.setPosition(10, 40);
    window.draw(baitText);
}

void displayFeedback(RenderWindow &window) {
    // Implementação da exibição do feedback visual para ações de pesca
}

void saveProgress() {
    // Implementação do sistema de salvamento
}

void switchEquipment() {
    // Implementação da troca de equipamento
}

void switchEnvironment() {
    // Implementação da troca de ambiente
}

void displayOptionsMenu(RenderWindow &window, Font &font) {
    // Implementação do menu de opções
}

void startGame(RenderWindow &window) {
    // Carregar a fonte
    Font font;
    if (!font.loadFromFile("arial.ttf")) {
        cout << "Erro ao carregar a fonte" << endl;
        return;
    }

    while (window.isOpen()) {
        Event event;
        while (window.pollEvent(event)) {
            if (event.type == Event::Closed)
                window.close();

            if (event.type == Event::KeyPressed) {
                if (event.key.code == Keyboard::F) {
                    isFishing = !isFishing;
                    if (isFishing) {
                        castSound.play();
                    } else {
                        catchSound.play();
                    }
                }

                if (event.key.code == Keyboard::E) {
                    switchEquipment();
                }

                if (event.key.code == Keyboard::N) {
                    switchEnvironment();
                }

                if (event.key.code == Keyboard::B) {
                    selectedBaitIndex = (selectedBaitIndex + 1) % baitTypes.size();
                }

                if (event.key.code == Keyboard::O) {
                    displayOptionsMenu(window, font);
                }

                if (event.key.code == Keyboard::P) {
                    isPaused = !isPaused;
                }

                if (event.key.code == Keyboard::S) {
                    saveProgress();
                }
            }

            if (event.type == Event::MouseButtonPressed) {
                for (const NPC &npc : npcs) {
                    if (npc.getBounds().contains(event.mouseButton.x, event.mouseButton.y)) {
                        cout << npc.getDialogue() << endl;
                    }
                }
            }
        }

        window.clear(Color::Blue);

        if (!isPaused) {
            // Desenhar elementos do jogo
            displayHUD(window, font);
            displayFeedback(window);
            for (const NPC &npc : npcs) {
                npc.draw(window);
            }
        } else {
            Text pauseText("Jogo Pausado", font, 40);
            pauseText.setFillColor(Color::White);
            pauseText.setPosition(250, 200);
            window.draw(pauseText);
        }

        window.display();
    }
}

int main() {
    RenderWindow window(VideoMode(800, 600), "Jogo de Pesca");

    if (!loadAssets()) {
        cout << "Erro ao carregar os assets!" << endl;
        return -1;
    }

    loadNPCs();
    startGame(window);

    return 0;
}
