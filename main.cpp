
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <iostream>
#include <vector>
#include <string>

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

struct NPC {
    Sprite sprite;
    string name;
    vector<string> dialogues;
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
    NPC npc1;
    npc1.name = "Pescador João";
    npc1.sprite.setTexture(npcTexture);
    npc1.sprite.setPosition(300, 300);
    npc1.dialogues.push_back("Olá, pescador! Dicas para hoje?");
    npc1.dialogues.push_back("Use a isca especial para capturar os maiores peixes!");
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

    Text fishCountText("Peixes capturados: " + to_string(inventory.size()), font, 20);
    fishCountText.setFillColor(Color::White);
    fishCountText.setPosition(10, 70);
    window.draw(fishCountText);
}

void switchEquipment() {
    // Lógica para alternar entre diferentes varas de pescar e molinetes
    // Atualize o equipamento atualmente selecionado
}

void switchEnvironment() {
    // Lógica para alternar entre diferentes ambientes de pesca
    // Atualize o cenário e a lógica de aparição de peixes
}

void displayOptionsMenu(RenderWindow &window, Font &font) {
    // Lógica para exibir o menu de opções
    // Permitir que o jogador ajuste configurações como tamanho da fonte e controle de áudio
}

void saveProgress() {
    // Lógica para salvar o progresso do jogador em um arquivo
}

void updateDailyMissions() {
    // Atualize o progresso das missões diárias
}

void updateScore(int points) {
    // Atualize a pontuação do jogador
}

void displayFeedback(RenderWindow &window) {
    // Exiba feedback visual para captura de peixe e troca de isca
}

void startGame(RenderWindow &window) {
    Font font;
    if (!font.loadFromFile("arial.ttf")) {
        cout << "Erro ao carregar a fonte!" << endl;
        return;
    }

    loadNPCs();

    while (window.isOpen()) {
        Event event;
        while (window.pollEvent(event)) {
            if (event.type == Event::Closed) {
                window.close();
            }

            if (event.type == Event::KeyPressed) {
                if (event.key.code == Keyboard::Space) {
                    if (!isPaused) {
                        if (!isFishing) {
                            isFishing = true;
                            castSound.play();
                        } else {
                            isFishing = false;
                            // Simular captura de peixe
                            string fishCaught = "Peixe Exemplo";
                            inventory.push_back(fishCaught);
                            catchSound.play();
                        }
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
                    if (npc.sprite.getGlobalBounds().contains(event.mouseButton.x, event.mouseButton.y)) {
                        int randomIndex = rand() % npc.dialogues.size();
                        cout << npc.name << ": " << npc.dialogues[randomIndex] << endl;
                    }
                }
            }
        }

        window.clear(Color::Blue);

        if (!isPaused) {
            // Desenhar elementos do jogo
            displayHUD(window, font);
            displayFeedback(window);
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

    startGame(window);

    return 0;
}
