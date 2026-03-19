#include <iostream>
#include <fstream>
#include <vector>


void radixSortBinary(std::vector<unsigned char>& A) {
    // TODO: implement radix sort
}


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

    std::vector<unsigned char> numbers;
    int x;

    while (input >> x) {
        if (x < 0 || x > 255) {
            std::cerr << "ni dovoljen obseg: " << x << std::endl;
            return 1;
        }

        numbers.push_back(static_cast<unsigned char>(x));
    }

    if (numbers.empty()) {
        std::cerr << "datoteka je prazna ali ne vsebuje veljavnih podatkov" << std::endl;
        return 1;
    }
    radixSortBinary(numbers);
    input.close();

    return 0;
}