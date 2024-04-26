// Tema Cool.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
#include <unordered_set>

bool isCoolSequence(const std::vector<int>& sequence) {
    std::unordered_set<int> distinct_elements(sequence.begin(), sequence.end());
    return (distinct_elements.size() == sequence.size());
}

int main() {
    int N = 24; // Lungimea sirului , daca aici se pune 0 iar la k se pune 50 valorile sunt date ca exemplu se va afisa mesajul:  nu exista secventa cool de lungie y stabilita in sirul dat
    int K = 5; // Lungimea secventei cautate

    std::vector<int> A(N);
    for (int i = 0; i < N; ++i) {
        A[i] = i + 1;
    }

    bool found_cool_sequence = false;
    for (int i = 0; i <= N - K && !found_cool_sequence; ++i) {
        std::vector<int> sequence(A.begin() + i, A.begin() + i + K);
        if (isCoolSequence(sequence)) {
            std::cout << "Secventa cool gasita: ";
            for (int num : sequence) {
                std::cout << num << " ";
            }
            std::cout << std::endl;
            found_cool_sequence = true;
        }
    }

    if (!found_cool_sequence) {
        std::cout << "Nu exista secvente cool de lungime " << K << " in sirul dat." << std::endl;
    }

    return 0;
}
