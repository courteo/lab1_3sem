#include "iostream"
#include "sequence.h"
#include "ArraySequence.h"
#include "linkseq.h"
#include "interfaceForArray.h"
#include "complex"


int get_struct(){
    std::cout << "Enter number to operate with certain data struct:\n"
              << "\t1 - Array Sequence\n"
              << "\t2 - Linked List Sequence\n"
              << "\t0 - exit\n";
    return get_int(0,2);
}

void interface() {

    ArraySequence<ArraySequence<int>> ArrInt;
    ArraySequence<ArraySequence<double>> ArrDouble;
    while (true) {

        int DateStruct = get_struct();
        if (DateStruct == 0 ) {
            std::cout << "Thanks for being with us ^-^\n";
            break;
        }


        switch (DateStruct) {
            case 1:
                interfaceForArray(ArrInt, ArrDouble);
                break;
            case 2:
                //interfaceForLinked();
                break;
        }
    }
}
