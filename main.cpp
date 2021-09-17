#include <iostream>
#include "Sorter.h"
#include "sequence.h"
#include "ArraySequence.h"
#include "interfaceBoth.h"

int main() {
    interface();
return 0;
    int array[] = {38, 27, 43, 3, 9, 82, 10, 0 , 3};
    ArraySequence<int> arra(9, array);
    for (int i = 0; i < 10000; i++)
        arra.append(i * i - 5 + 8*i + 3);

//    for (int i = 0; i < arra.get_len(); i++){
//        std::cout << arra.get_i(i) << " ";
//    }
    int shit;
    std::cout << "\n";
    Sorter<int>::SquareSelectionSort(arra,cmp);
    std::cout << arra;
    std::cin >> shit;

    for (int i = 0; i < arra.get_len(); i++){
        std::cout << arra.get_i(i) << " ";
    }

    return 0;
}
