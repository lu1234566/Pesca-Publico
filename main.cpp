#include <iostream>
#include <vector>
#include <string>

using namespace std;

// Configurações
int hour = 12;
int minute = 0;
bool isFishing = false;
bool isPaused = false;
int fontSize = 20;
vector<string> inventory;
vector<string> baitTypes = {"Worm", "Fly", "Spinner"};
int selectedBaitIndex = 0;

// Estruturas
struct Fish {
    string name;
};

struct NPC {
    string name;
    vector<string> dialogues;
};

// Funções de inicialização
void loadNPCs(vector<NPC>& npcs) {
    NPC npc1;
    npc1.name = "Pescador João";
    npc1.dialogues.push_back("Olá, pescador! Dicas para hoje?");
    npc1.dialogues.push_back("Use a isca especial para capturar os maiores peixes!");
    npcs.push_back(npc1);
}

void displayHUD() {
    cout << "Hora: " << hour << ":" << (minute < 10 ? "0" : "") << minute << endl;
    cout << "Isca: " << baitTypes[selectedBaitIndex] << endl;
    cout << "Peixes capturados: " << inventory.size() << endl;
}

void switchEquipment() {
    cout << "Alternando equipamento..." << endl;
}

void switchEnvironment() {
    cout << "Alternando ambiente..." << endl;
}

void saveProgress() {
    cout << "Progresso salvo!" << endl;
}

int main() {
    vector<NPC> npcs;
    loadNPCs(npcs);

    while (true) {
        cout << "Pressione 'f' para pescar, 'e' para alternar equipamento, 'n' para alternar ambiente, 'p' para pausar/resumir, 's' para salvar, 'q' para sair." << endl;
        char command;
        cin >> command;

        if (command == 'q') break;

        switch (command) {
            case 'f':
                if (!isPaused) {
                    if (!isFishing) {
                        isFishing = true;
                        cout << "Pescando..." << endl;
                    } else {
                        isFishing = false;
                        // Simular captura de peixe
                        string fishCaught = "Peixe Exemplo";
                        inventory.push_back(fishCaught);
                        cout << "Peixe capturado: " << fishCaught << endl;
                    }
                }
                break;
            case 'e':
                switchEquipment();
                break;
            case 'n':
                switchEnvironment();
                break;
            case 'p':
                isPaused = !isPaused;
                cout << (isPaused ? "Jogo pausado" : "Jogo resumido") << endl;
                break;
            case 's':
                saveProgress();
                break;
            default:
                cout << "Comando não reconhecido." << endl;
        }

        displayHUD();
    }

    return 0;
}
