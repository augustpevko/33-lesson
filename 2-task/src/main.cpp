#include <iostream>
#include <vector>
#include <string>
#include <ctime>
#include "myExceptions.h"

class Field {
    std::vector<myException*> sectors;

public:
    void pickSector(int& answer) {
        if (sectors[answer] != nullptr) {
            sectors[answer]->myThrow();
        }
        return;
    }

    Field(Field const&) = delete;
    Field& operator=(Field const&) = delete;
    Field() {
        sectors.resize(9);
        std::srand(std::time(nullptr));
        sectors[std::rand() % 9] = new FishException;
        for (int i = 0; i < 3; ) {
            int tempRandom = std::rand() % 9;
            if (sectors[tempRandom] == nullptr) {
                sectors[tempRandom] = new BootException;
                i++;
            }
        } 
    }
    ~Field() {
        for (auto v: sectors) {
            delete v;
        }
    }
};

int main() {
    Field field;
    int i = 0;
    while (true) {
        int answer;
        do {
            std::cout << "Select a sector: ";
            std::cin >> answer;
        } while (answer > 8);
        try {
            field.pickSector(answer);
            i++;
        }
        catch (FishException& x) {
            std::cerr << x.what() << std::endl;
            std::cerr << "it took you " << i + 1 << " attempts";
            break;
        }
        catch (BootException& x) {
            std::cerr << x.what() << std::endl;
            i++;
        }
    }
}
