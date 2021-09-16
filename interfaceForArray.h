#include "iostream"
#include "ArraySequence.h"
#include "sequence.h"
#include "complex"
#include "Sorter.h"
#ifndef DAR_H_INTERFACE_H
#define DAR_H_INTERFACE_H

template<class T>
bool cmp(T a1, T a2) {
    return a1 < a2;
}


void Delete(int Type, ArraySequence<ArraySequence<int>> *ArrInt,
            ArraySequence<ArraySequence<double>> *ArrDouble);
template<class T>
void DeleteType(ArraySequence<ArraySequence<T>> *ArrInt);

void DeleteAll(int Type, ArraySequence<ArraySequence<int>> *ArrInt,
                  ArraySequence<ArraySequence<double>> *ArrDouble);
template<class T>
void DeleteAllType(ArraySequence<ArraySequence<T>> *ArrInt);

void readSequence(int Type, ArraySequence<ArraySequence<int>> *ArrInt,
                            ArraySequence<ArraySequence<double>> *ArrDouble);
template<class T>
ArraySequence<T> readSequenceType(int count);


void printAll(int Type, ArraySequence<ArraySequence<int>> *ArrInt,
                        ArraySequence<ArraySequence<double>> *ArrDouble);
void printArray(int Type, ArraySequence<ArraySequence<int>> *ArrInt,
                          ArraySequence<ArraySequence<double>> *ArrDouble, int index1);


void Sort(int Type, ArraySequence<ArraySequence<int>> *ArrInt,
                    ArraySequence<ArraySequence<double>> *ArrDouble);
template<class T>
ArraySequence<T> SortType(ArraySequence<ArraySequence<T>> *ArrInt);
template<class T>
void SortTypeVoid(int Type, ArraySequence<ArraySequence<T>> *ArrInt);

int get_type();




int get_int() {
    int a;
    std::cin >> a;
    return a;
}

int get_int(int up) {
    int a;
    std::cin >> a;
    if (a > up) {
        std::cout << "Can you enter again\n";
        return get_int(up);
    }
    return a;
}

int get_int(int down, int up) {
    int a;
    std::cin >> a;
    if (a > up || a < down) {
        std::cout << "Can you enter again\n";
        return get_int(down, up);
    }
    return a;
}

double get_double() {
    double a;
    std::cin >> a;
    return a;
}


int get_type() {
    std::cout << "Enter number to operate with certain data type: \n"
              << "\t1 - int\n"
              << "\t2 - double\n"
              << "\t0 - exit\n";
    return get_int(0, 2);
}

void interfaceForArray(ArraySequence<ArraySequence<int>> &ArrInt,
                       ArraySequence<ArraySequence<double>> &ArrDouble){

    while (true) {
        std::cout << "Can you choose option:\n"
                  << "\t0 - exit\n"
                  << "\t1 - Enter Sequence\n"
                  << "\t2 - print all Sequences\n"
                  << "\t3 - print Sequence[i]\n"
                  << "\t4 - Sort Sequence\n"
                  << "\t5 - compare Sorts\n"
                  << "\t6 - tests\n"
                  << "\t7 - delete all\n"
                  << "\t8 - delete Sequence[i]\n";
        int item0 = get_int(0, 8);

        if (item0 == 0) {
            std::cout << "Thanks for being with us ^-^\n";
            break;
        }
        int Type = get_type();
        switch (item0) {
            case 1:
                readSequence(Type, &ArrInt, &ArrDouble);
                break;
            case 2:
                printAll(Type, &ArrInt, &ArrDouble);
                break;
            case 3:
                printArray(Type, &ArrInt, &ArrDouble, -1);
                break;
            case 4:
                Sort(Type, &ArrInt, &ArrDouble);
                break;
            case 5:
                //compare(Type, &ArrInt, &ArrDouble);
                break;
            case 6:
                //testFunc();
                break;
            case 7:
                DeleteAll(Type, &ArrInt, &ArrDouble);
                break;
            case 8:
                Delete(Type, &ArrInt, &ArrDouble);
                break;

        }
    }


}



void readSequence(int Type, ArraySequence<ArraySequence<int>> *ArrInt,
                            ArraySequence<ArraySequence<double>> *ArrDouble){
    if (Type == 0){
        std::cout << "Thanks for being with us ^-^\n";
        return;
    }

    std::cout << "Enter count of elements or 0 to exit, please: \n";
    int count;
    std::cin >> count;
    while (count <= 0) {
        if (count < 0)
            std::cout << "count can not be less than 0, please ReEnter count\n";
        std::cin >> count;
        if (count == 0)
            return;
    }

    ArraySequence<int> ArrInt1;
    ArraySequence<double> ArrDouble1;
    switch (Type) {
        case 1:
            ArrInt->append(readSequenceType<int>(count));
            break;
        case 2:
            ArrDouble1 = readSequenceType<double>(count);
            ArrDouble->append(ArrDouble1);
            break;
        default:
            break;
    }
}

template<class T>
ArraySequence<T> readSequenceType(int count){
    std::cout << "Can you enter the elements, please:\n";

    ArraySequence<T> arr;
    for (int i = 0; i < count; i++){
        T item;
        std::cin >> item;

        arr.append(item);
    }

    return arr;
}



void printArray(int Type, ArraySequence<ArraySequence<int>> *ArrInt,
                     ArraySequence<ArraySequence<double>> *ArrDouble, int index1){
    if (Type == 0){
        std::cout << "Thanks for being with us ^-^\n";
        return;
    }

    if (index1 < 0 ){

        int length;
        if (Type = 1){
            length = ArrInt->get_len();

            if (length == 0){
                std::cout << "Sorry, but Length == 0\n";
                return;
            }

            std::cout << "Can you choose index of massive from 0 to " << ArrInt->get_len() - 1 << ",please\n";
        }
        else{
            length = ArrDouble->get_len();
            if (length == 0){
                std::cout << "Sorry, but Length == 0 \n";
                return;
            }
            std::cout << "Can you choose index of massive from 0 to " << ArrDouble->get_len() - 1 << ",please\n";
        }


        int index;
        std::cin >> index;
        while (index < 0 || index >= length) {
            if (index < 0 || index >= length)
                std::cout << "index can not be less than 0 and be bigger than length, please ReEnter count or enter -1 to exit\n";
            std::cin >> index;
            if (index == -1)
                return;

        }

        if (Type == 1)
            std::cout << ArrInt->operator[](index);
        else
            std::cout << ArrDouble->operator[](index);
    }
    else {
        if (Type == 1)
            std::cout << ArrInt->operator[](index1);
        else
            std::cout << ArrDouble->operator[](index1);
    }

}

void printAll(int Type, ArraySequence<ArraySequence<int>> *ArrInt,
                        ArraySequence<ArraySequence<double>> *ArrDouble) {

    if (Type == 0) {
        std::cout << "Thanks for being with us ^-^\n";
        return;
    }

    if (Type == 1) {
        if (ArrInt->get_len() == 0){
            std::cout << "Sorry, but Length == 0 \n";
            return;
        }
        for (int i = 0; i < ArrInt->get_len(); i++) {
            printArray(Type, ArrInt, ArrDouble, i);
            std::cout << "\n";
        }
    } else {
        if (ArrDouble->get_len() == 0){
            std::cout << "Sorry, but Length == 0 \n";
            return;
        }
        for (int i = 0; i < ArrDouble->get_len(); i++) {
            printArray(Type, ArrInt, ArrDouble, i);
            std::cout << "\n";
        }

    }
}

void Sort(int Type, ArraySequence<ArraySequence<int>> *ArrInt,
                    ArraySequence<ArraySequence<double>> *ArrDouble)  {

    if (Type == 0){
        std::cout << "Thanks for being with us ^-^\n";
        return;
    }

    ArraySequence<int> ArrInt1;
    ArraySequence<double> ArrDouble1;

    std::cout << "Do you want change i massive or create new massive from i massive?\n"
               << "\t1 - change i massive\n"
               << "\t2 - create new massive\n";
    int index11 = get_int(1, 2);

    if (index11 == 1) {
        switch (Type) {
            case 1:
                SortTypeVoid(Type, ArrInt);
                break;
            case 2:
                SortTypeVoid(Type, ArrDouble);
                break;
            default:
                break;
        }
    }
    else{
        switch (Type) {
            case 1:
                ArrInt1 = SortType<int>(ArrInt);
                if (sizeof(ArrInt1) != sizeof(ArraySequence<int>))
                    ArrInt->append(ArrInt1);
                break;
            case 2:
                ArrDouble1 = SortType<double>(ArrDouble);
                if (sizeof(ArrDouble1) != sizeof(ArraySequence<int>))
                    ArrDouble->append(ArrDouble1);
                break;
            default:
                break;
        }
    }
}

template<class T>
ArraySequence<T> SortType(ArraySequence<ArraySequence<T>> *ArrInt){
    int length = ArrInt->get_len();
    if (length == 0){
        std::cout << "Sorry, but Length == 0\n";
        return ArraySequence<T>();
    }
    std::cout << "Can you choose index of massive from 0 to " << ArrInt->get_len() - 1 << ",please\n";

    int index;
    std::cin >> index;
    while (index < 0 || index >= length) {
        if (index < 0 || index >= length)
            std::cout << "index can not be less than 0 and be bigger than length, please ReEnter count or enter -1 to exit\n";
        std::cin >> index;
        if (index == -1)
            return ArraySequence<T>();
    }

    ArraySequence<T> ArrTemp(ArrInt->operator[](index));

    std::cout << "Can you choose certain sort:\n"
              << "\t0 - exit\n"
              << "\t1 - BubbleSort\n"
              << "\t2 - BubbleShakerSort\n"
              << "\t3 - InsertionSort\n"
              << "\t4 - BinaryInsertionSort\n"
              << "\t5 - SelectionSort\n"
              << "\t6 - CountingSort\n"
              << "\t7 - MergeSort\n"
              << "\t8 - SquareSelectionSort\n"
              << "\t9 - QuickSort\n"
              << "\t10 - ShellSort\n"
              << "\t11 - ShellSelectSort\n"
              << "\t12 - BinaryTreeSort\n"
              << "\t13 - HeapSort\n"
              << "\t14 - Bitonicsort\n";

    int index22 = get_int(0,14);
    if (index22 == 0){
        std::cout << "Thanks for being with us ^-^\n";
        return ArraySequence<T>();
    }

        switch (index22){
            case 1:
                Sorter<T>::BubbleSort(ArrTemp, cmp);
                break;
            case 2:
                Sorter<T>::BubbleShakerSort(ArrTemp, cmp);
                break;
            case 3:
                Sorter<T>::InsertionSort(ArrTemp, cmp);
                break;
            case 4:
                Sorter<T>::BinaryInsertionSort(ArrTemp, cmp);
                break;
            case 5:
                Sorter<T>::SelectionSort(ArrTemp, cmp);
                break;
            case 6:
                Sorter<T>::CountingSort(ArrTemp, cmp);
                break;
            case 7:
                Sorter<T>::MergeSort(ArrTemp, 0, ArrTemp.get_len() - 1, cmp);
                break;
            case 8:
                Sorter<T>::SquareSelectionSort(ArrTemp, cmp);
                break;
            case 9:
                Sorter<T>::QuickSort(ArrTemp, 0, ArrTemp.get_len() - 1, cmp);
                break;
            case 10:
                Sorter<T>::ShellSort(ArrTemp, cmp);
                break;
            case 11:
                //Sorter<T>::ShellSelectSort(ArrTemp, cmp);
                break;
            case 12:
                //Binary
                break;
            case 13:
                Sorter<T>::HeapSort(ArrTemp, cmp);
                break;
            case 14:
                Sorter<T>::Bitonicsort(ArrTemp, cmp);
                break;
        }
    return ArrTemp;
}

template<class T>
void SortTypeVoid(int Type, ArraySequence<ArraySequence<T>> *ArrInt){

    if (Type == 0){
        std::cout << "Thanks for being with us ^-^\n";
        return;
    }


    int length;
    length = ArrInt->get_len();

    if (length == 0){
        std::cout << "Sorry, but Length == 0 \n";
        return;
    }


    std::cout << "Can you choose index of massive from 0 to " << ArrInt->get_len() - 1 << ",please\n";


    int index;
    std::cin >> index;
    while (index < 0 || index >= length) {

        if (index < 0 || index >= length)
            std::cout << "index can not be less than 0 and be bigger than length, please ReEnter count or enter -1 to exit\n";
        std::cin >> index;
        if (index == -1)
            return;
    }


    std::cout << "Can you choose certain sort:\n"
              << "\t0 - exit\n"
              << "\t1 - BubbleSort\n"
              << "\t2 - BubbleShakerSort\n"
              << "\t3 - InsertionSort\n"
              << "\t4 - BinaryInsertionSort\n"
              << "\t5 - SelectionSort\n"
              << "\t6 - CountingSort\n"
              << "\t7 - MergeSort\n"
              << "\t8 - SquareSelectionSort\n"
              << "\t9 - QuickSort\n"
              << "\t10 - ShellSort\n"
              << "\t11 - ShellSelectSort\n"
              << "\t12 - BinaryTreeSort\n"
              << "\t13 - HeapSort\n"
              << "\t14 - Bitonicsort\n";

    int index22 = get_int(0,14);
    if (index22 == 0){
        std::cout << "Thanks for being with us ^-^\n";
        return;
    }

        switch (index22){
            case 1:
                Sorter<T>::Bitonicsort(ArrInt->operator[](index), cmp);
                break;
            case 2:
                Sorter<T>::BubbleShakerSort(ArrInt->operator[](index), cmp);
                break;
            case 3:
                Sorter<T>::InsertionSort(ArrInt->operator[](index), cmp);
                break;
            case 4:
                Sorter<T>::BinaryInsertionSort(ArrInt->operator[](index), cmp);
                break;
            case 5:
                Sorter<T>::SelectionSort(ArrInt->operator[](index), cmp);
                break;
            case 6:
                Sorter<T>::CountingSort(ArrInt->operator[](index), cmp);
                break;
            case 7:
                Sorter<T>::MergeSort(ArrInt->operator[](index), 0, ArrInt->get_len() - 1, cmp);
                break;
            case 8:
                Sorter<T>::SquareSelectionSort(ArrInt->operator[](index), cmp);
                break;
            case 9:
                Sorter<T>::QuickSort(ArrInt->operator[](index), 0,ArrInt->get_len() - 1, cmp);
                break;
            case 10:
                Sorter<T>::ShellSort(ArrInt->operator[](index), cmp);
                break;
            case 11:
                //Sorter<T>::ShellSelectSort(ArrInt->operator[](index), cmp);
                break;
            case 12:
                //Binary
                break;
            case 13:
                Sorter<T>::HeapSort(ArrInt->operator[](index), cmp);
                break;
            case 14:
                Sorter<T>::BinaryInsertionSort(ArrInt->operator[](index), cmp);
                break;
        }


}


void Delete(int Type, ArraySequence<ArraySequence<int>> *ArrInt,
                      ArraySequence<ArraySequence<double>> *ArrDouble){
    if (Type == 0){
        std::cout << "Thanks for being with us ^-^\n";
        return;
    }
    switch (Type) {
        case 1:
            DeleteType<int>(ArrInt);
            break;
        case 2:
            DeleteType<double>(ArrDouble);
            break;

    }

}

template<class T>
void DeleteType(ArraySequence<ArraySequence<T>> *ArrInt){
    if (ArrInt->get_len() == 0){
        std::cout << "Sorry, but massive is empty \n";
        return;
    }

    while (true){

        int length = ArrInt->get_len();
        if (ArrInt->get_len() == 0){
            std::cout << "Sorry, but massive is empty \n";
            return;
        }

        std::cout << "You have " << length << " massives\n"
                  << "\t0 - to exit\n"
                  << "\t1 - delete Sequence[i]\n"
                  << "\t2 - print all\n";

        int index1 = get_int(0, 2);
        if (index1 == 0)
            return;

        if (index1 == 2){

        }
        else {
            std::cout << "Can you choose index of massive from 0 to " << ArrInt->get_len() - 1 << ",please\n";


            int index;
            std::cin >> index;
            while (index < 0 || index >= length) {

                if (index < 0 || index >= length)
                    std::cout << "index can not be less than 0 and be bigger than length, please ReEnter count or enter -1 to exit\n";
                std::cin >> index;
                if (index == -1)
                    return;
            }
            ArrInt->pop(index);
        }
    }
}

void DeleteAll(int Type, ArraySequence<ArraySequence<int>> *ArrInt,
               ArraySequence<ArraySequence<double>> *ArrDouble){
    if (Type == 0){
        std::cout << "Thanks for being with us ^-^\n";
        return;
    }
    switch (Type) {
        case 1:
            DeleteAllType<int>(ArrInt);
            break;
        case 2:
            DeleteAllType<double>(ArrDouble);
            break;

    }
}

template<class T>
void DeleteAllType(ArraySequence<ArraySequence<T>> *ArrInt){
    if (ArrInt->get_len() == 0){
        std::cout << "Sorry, but massive is empty \n";
        return;
    }
    int length =ArrInt->get_len();
    for (int i = 0; i < length; i++){
        ArrInt->pop(0);
    }
}
#endif //DAR_H_INTERFACE_H

