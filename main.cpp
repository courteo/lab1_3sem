#include <iostream>
#include "Sorter.h"
#include "sequence.h"
#include "ArraySequence.h"

bool comp(int a1, int a2) {
    return a1 < a2;
}
int main() {
    int array[] = {38, 27, 43, 3, 9, 82, 10, 0 , 3};
    ArraySequence<int> arra(9, array);

    for (int i = 0; i < arra.get_len(); i++){
        std::cout << arra.get_i(i) << " ";
    }

    std::cout << "\n";
    //ArraySequence<int> qwe;
    Sorter<int>::Bitonicsort(arra,comp);

    for (int i = 0; i < arra.get_len(); i++){
        std::cout << arra.get_i(i) << " ";
    }
    return 0;
}
