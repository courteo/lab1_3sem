#include <iostream>
#include "Sorter.h"

int main() {
    int array[] = {38, 27, 43, 3, 9, 82, 10};
    Sorter<int> arra(7, array);

    for (int i = 0; i < arra.get_len(); i++){
        std::cout << arra.get_i(i) << " ";
    }
    std::cout << "\n";
    arra.ShellSort(arra);

    for (int i = 0; i < arra.get_len(); i++){
        std::cout << arra.get_i(i) << " ";
    }
    return 0;
}
