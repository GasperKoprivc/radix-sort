#include <iostream>
#include <fstream>
#include <vector>


void radixSortBinary(std::vector<unsigned char>& A) {
    if (A.empty()) return;

    std::vector<unsigned char> B(A.size());

    for (int k = 0; k < 8; k++) {
        int C[2] = {0, 0};

        for (size_t i = 0; i < A.size(); i++) {
            int bit = (A[i] >> k) & 1;
            C[bit]++;
        }

        C[1] += C[0];

        for (int i = (int)A.size() - 1; i >= 0; i--) {
            int bit = (A[i] >> k) & 1;
            B[--C[bit]] = A[i];
        }

        A = B;
    }
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

    std::ofstream output("out.txt");
    if (!output.is_open()) {
        std::cerr << "napaka" << std::endl;
        return 1;
    }

    input.close();

    return 0;
}