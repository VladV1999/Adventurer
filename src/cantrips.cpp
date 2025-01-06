#include "cantrips.h"
// @todo add if a line starts with a comment or a pound, ignore it
void Cantrips::cantripRead() {
    fstream toml("data/cantrips.toml");
    if (!toml.is_open()) {
        std::cerr << "Error: unable to open or find cantrips.toml file!" << "\n";
        return;
    }
    string clazz;
    string cantrip;
    vector<string> cantrips;
    unordered_map <string, vector<string>> cantripMap;
    string line;
    while (getline (toml, line)) {
        if (line.empty()) {
            continue;
        }

        if (line[0] == '[') {
            if (!clazz.empty()) {
                cantripMap[clazz] = cantrips;
            }
                clazz = line.substr(1, line.find(']') - 1);
                continue;
        }

        if (line.find("cantrips = [") != string::npos) {
            continue;
        }

        if (line.find('"') != string::npos) {
            size_t first_quote = line.find('"');
            size_t last_quote = line.rfind('"');
            cantrip = line.substr(first_quote + 1, last_quote - first_quote - 1);
            cantrips.push_back(cantrip);
            continue;
        }

        if (line[0] == ']') {
            cantripMap[clazz] = cantrips;
            clazz.clear();
            cantrips.clear();
            continue;
        }
    }
     for (const auto& [clazz, cantrips] : cantripMap) {
        cout << "Class: '" << clazz << "'\nCantrips:\n";
        for (const auto& cantrip : cantrips) {
            cout << " - " << cantrip << "\n";
        }
    toml.close();
}
}