#include <iostream>
#include <fstream>

int main(int argc, char* argv[]) {
    if (argc != 2) {
        std::cerr << "uporaba: vaja2 <vhodna_datoteka>" << std::endl;
        return 1;
    }

    std::ifstream input(argv[1]);
    if (!input.is_open()) {
        std::cerr << "napaka odpiranje" << std::endl;
        return 1;
    }

    input.close();

    return 0;
}