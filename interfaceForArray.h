#include "iostream"
#include "ArraySequence.h"
#include "sequence.h"
#include "complex"
#include "string"
#include "Sorter.h"
#include "random"
#include "timer.h"
#ifndef DAR_H_INTERFACE_H
#define DAR_H_INTERFACE_H

template<class T>
bool cmp(T a1, T a2) {
    return a1 < a2;
}
double getSortTime(int index2, ArraySequence<double>&arr1);

void testFunc(int Type);

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

void compare();


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
                compare();
                break;
            case 6:
                testFunc(Type);
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
                if (ArrInt1.get_len() != 0)
                    ArrInt->append(ArrInt1);
                break;
            case 2:
                ArrDouble1 = SortType<double>(ArrDouble);
                if (ArrDouble1.get_len() != 0)
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
              << "\t8 - QuickSort\n"
              << "\t9 - ShellSort\n"
              << "\t10 - ShellSelectSort\n"
              << "\t11 - BinaryTreeSort\n"
              << "\t12 - HeapSort\n";

    int index22 = get_int(0,12);
    if (index22 == 0){
        std::cout << "Thanks for being with us ^-^\n";
        return ArraySequence<T>();
    }
    T array1[] = {9, 5, 3, 8,4, 1};
    ArraySequence<T> arr(6, array1);
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
                Sorter<T>::QuickSort(ArrTemp, 0, ArrTemp.get_len() - 1, cmp);
                break;
            case 9:
                Sorter<T>::ShellSort(ArrTemp, cmp);
                break;
            case 10:
                Sorter<T>::ShellSelectSort(ArrTemp, arr, cmp);
                break;
            case 11:
                Sorter<T>::Node::BinaryTreeSort(ArrTemp);
                break;
            case 12:
                Sorter<T>::HeapSort(ArrTemp, ArrInt->get_len(), cmp);
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
              << "\t8 - QuickSort\n"
              << "\t9 - ShellSort\n"
              << "\t10 - ShellSelectSort\n"
              << "\t11 - BinaryTreeSort\n"
              << "\t12 - HeapSort\n";

    int index22 = get_int(0,12);
    if (index22 == 0){
        std::cout << "Thanks for being with us ^-^\n";
        return;
    }
    T array1[] = {9, 5, 3, 8,4, 1};
    ArraySequence<T> arr(6, array1);
        switch (index22){
            case 1:
                Sorter<T>::BubbleSort(ArrInt->operator[](index), cmp);
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
                Sorter<T>::QuickSort(ArrInt->operator[](index), 0,ArrInt->get_len() - 1, cmp);
                break;
            case 9:
                Sorter<T>::ShellSort(ArrInt->operator[](index), cmp);
                break;
            case 10:
                Sorter<T>::ShellSelectSort(ArrInt->operator[](index),arr, cmp);
                break;
            case 11:
                Sorter<T>::Node::BinaryTreeSort(ArrInt->operator[](index));
                break;
            case 12:
                Sorter<T>::HeapSort(ArrInt->operator[](index), ArrInt->get_len(), cmp);
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

void testFunc(int Type){
    if (Type == 0)
        return;
    if (Type == 1){
        ArraySequence<int> Arr;
        int length = rand()%100;

        for (int i = 0; i < length; i++){
            Arr.append(rand() % 1000000);
        }
        ArraySequence<int> ar(Arr);
        Sorter<int>::QuickSort(ar, 0 , ar.get_len() - 1, cmp);
        int array[] = {9, 5, 3, 8,4, 1};
        ArraySequence<int> arra(6, array);

        for (int i = 1; i <= 12; i++){
            ArraySequence<int> arr(Arr);

            std::cout << i << ": ";
            switch (i){
                case 1:
                    Sorter<int>::BubbleSort(arr, cmp);
                    if (ar == arr)
                        std::cout << "Ohhh, It's actually working, my friend\n";
                    else
                        std::cout << "What is a duuuude, you can not create normal sort\n";
                    break;
                case 2:
                    Sorter<int>::BubbleShakerSort(arr, cmp);
                    if (ar == arr)
                        std::cout << "Ohhh, It's actually working, my friend\n";
                    else
                        std::cout << "What is a duuuude, you can not create normal sort\n";
                    break;
                case 3:
                    Sorter<int>::InsertionSort(arr, cmp);
                    if (ar == arr)
                        std::cout << "Ohhh, It's actually working, my friend\n";
                    else
                        std::cout << "What is a duuuude, you can not create normal sort\n";
                    break;
                case 4:
                    Sorter<int>::BinaryInsertionSort(arr, cmp);
                    if (ar == arr)
                        std::cout << "Ohhh, It's actually working, my friend\n";
                    else
                        std::cout << "What is a duuuude, you can not create normal sort\n";
                    break;
                case 5:
                    Sorter<int>::SelectionSort(arr, cmp);
                    if (ar == arr)
                        std::cout << "Ohhh, It's actually working, my friend\n";
                    else
                        std::cout << "What is a duuuude, you can not create normal sort\n";
                    break;
                case 6:
                    Sorter<int>::CountingSort(arr, cmp);
                    if (ar == arr)
                        std::cout << "Ohhh, It's actually working, my friend\n";
                    else
                        std::cout << "What is a duuuude, you can not create normal sort\n";
                    break;
                case 7:
                    Sorter<int>::MergeSort(arr, 0, arr.get_len() - 1, cmp);
                    if (ar == arr)
                        std::cout << "Ohhh, It's actually working, my friend\n";
                    else
                        std::cout << "What is a duuuude, you can not create normal sort\n";
                    break;
                case 8:
                    Sorter<int>::QuickSort(arr, 0, arr.get_len() - 1, cmp);
                    if (ar == arr)
                        std::cout << "Ohhh, It's actually working, my friend\n";
                    else
                        std::cout << "What is a duuuude, you can not create normal sort\n";
                    break;
                case 9:
                    Sorter<int>::ShellSort(arr, cmp);
                    if (ar == arr)
                        std::cout << "Ohhh, It's actually working, my friend\n";
                    else
                        std::cout << "What is a duuuude, you can not create normal sort\n";
                    break;
                case 10:
                    Sorter<int>::ShellSelectSort(arr, arra, cmp);
                    if (ar == arr)
                        std::cout << "Ohhh, It's actually working, my friend\n";
                    else
                        std::cout << "What is a duuuude, you can not create normal sort\n";
                    break;
                case 11:
                    Sorter<int>::Node::BinaryTreeSort(arr);
                    if (ar == arr)
                        std::cout << "Ohhh, It's actually working, my friend\n";
                    else
                        std::cout << "What is a duuuude, you can not create normal sort\n";
                    break;
                case 12:
                    Sorter<int>::HeapSort(arr, arr.get_len(), cmp);
                    if (ar == arr)
                        std::cout << "Ohhh, It's actually working, my friend\n";
                    else
                        std::cout << "What is a duuuude, you can not create normal sort\n";
                    break;
            }
        }

    }
    else
    {
        ArraySequence<double> Arr1;
        int length = rand()%100;

        for (int i = 0; i < length; i++){
            Arr1.append(rand() % 1000000);
        }
        ArraySequence<double> ar1(Arr1);
        Sorter<double>::QuickSort(ar1, 0 , ar1.get_len() - 1, cmp);
        double array1[] = {9, 5, 3, 8,4, 1};
        ArraySequence<double> arra1(6, array1);

        for (int i = 1; i <= 12; i++){
            ArraySequence<double> arr1(Arr1);

            std::cout << i << ": ";
            switch (i){
                case 1:
                    Sorter<double>::BubbleSort(arr1, cmp);
                    if (ar1 == arr1)
                        std::cout << "Ohhh, It's actually working, my friend\n";
                    else
                        std::cout << "What is a duuuude, you can not create normal sort\n";
                    break;
                case 2:
                    Sorter<double>::BubbleShakerSort(arr1, cmp);
                    if (ar1 == arr1)
                        std::cout << "Ohhh, It's actually working, my friend\n";
                    else
                        std::cout << "What is a duuuude, you can not create normal sort\n";
                    break;
                case 3:
                    Sorter<double>::InsertionSort(arr1, cmp);
                    if (ar1 == arr1)
                        std::cout << "Ohhh, It's actually working, my friend\n";
                    else
                        std::cout << "What is a duuuude, you can not create normal sort\n";
                    break;
                case 4:
                    Sorter<double>::BinaryInsertionSort(arr1, cmp);
                    if (ar1 == arr1)
                        std::cout << "Ohhh, It's actually working, my friend\n";
                    else
                        std::cout << "What is a duuuude, you can not create normal sort\n";
                    break;
                case 5:
                    Sorter<double>::SelectionSort(arr1, cmp);
                    if (ar1 == arr1)
                        std::cout << "Ohhh, It's actually working, my friend\n";
                    else
                        std::cout << "What is a duuuude, you can not create normal sort\n";
                    break;
                case 6:
                    Sorter<double>::CountingSort(arr1, cmp);
                    if (ar1 == arr1)
                        std::cout << "Ohhh, It's actually working, my friend\n";
                    else
                        std::cout << "What is a duuuude, you can not create normal sort\n";
                    break;
                case 7:
                    Sorter<double>::MergeSort(arr1, 0, arr1.get_len() - 1, cmp);
                    if (ar1 == arr1)
                        std::cout << "Ohhh, It's actually working, my friend\n";
                    else
                        std::cout << "What is a duuuude, you can not create normal sort\n";
                    break;
                case 8:
                    Sorter<double>::QuickSort(arr1, 0, arr1.get_len() - 1, cmp);
                    if (ar1 == arr1)
                        std::cout << "Ohhh, It's actually working, my friend\n";
                    else
                        std::cout << "What is a duuuude, you can not create normal sort\n";
                    break;
                case 9:
                    Sorter<double>::ShellSort(arr1, cmp);
                    if (ar1 == arr1)
                        std::cout << "Ohhh, It's actually working, my friend\n";
                    else
                        std::cout << "What is a duuuude, you can not create normal sort\n";
                    break;
                case 10:
                    Sorter<double>::ShellSelectSort(arr1, arra1, cmp);
                    if (ar1 == arr1)
                        std::cout << "Ohhh, It's actually working, my friend\n";
                    else
                        std::cout << "What is a duuuude, you can not create normal sort\n";
                    break;
                case 11:
                    Sorter<double>::Node::BinaryTreeSort(arr1);
                    if (ar1 == arr1)
                        std::cout << "Ohhh, It's actually working, my friend\n";
                    else
                        std::cout << "What is a duuuude, you can not create normal sort\n";
                    break;
                case 12:
                    Sorter<double>::HeapSort(arr1, arr1.get_len() , cmp);
                    if (ar1 == arr1)
                        std::cout << "Ohhh, It's actually working, my friend\n";
                    else
                        std::cout << "What is a duuuude, you can not create normal sort\n";
                    break;
            }
        }
    }

}

void compare(){

    std::cout << "Can you choose 2 certain sorts:\n"
              << "\t0 - exit\n"
              << "\t1 - BubbleSort\n"
              << "\t2 - BubbleShakerSort\n"
              << "\t3 - InsertionSort\n"
              << "\t4 - BinaryInsertionSort\n"
              << "\t5 - SelectionSort\n"
              << "\t6 - CountingSort\n"
              << "\t7 - MergeSort\n"
              << "\t8 - QuickSort\n"
              << "\t9 - ShellSort\n"
              << "\t10 - ShellSelectSort\n"
              << "\t11 - BinaryTreeSort\n"
              << "\t12 - HeapSort\n";

    std::string Name_sorts[12] = {"BubbleSort", "BubbleShakerSort", "InsertionSort", "BinaryInsertionSort", "SelectionSort", "CountingSort",
                         "MergeSort", "QuickSort", "ShellSort", "ShellSelectSort", "BinaryTreeSort", "HeapSort"};

    int index1 = get_int(0,12);
    if (index1 == 0){
        std::cout << "Thanks for being with us ^-^\n";
        return;
    }

    int index2 = get_int(0,12);
    if (index2 == 0){
        std::cout << "Thanks for being with us ^-^\n";
        return;
    }
/*
    while (true){
        if (index2 == index1){
            std::cout << "Ooops, can you rechoose sort\n";
            index2 = get_int(0, 12);
        }
        else
            break;
    }
*/

    std::cout << "Please, choose count of number from 10 to 100\n";
    int length = get_int(10, 100);

    ArraySequence<double> arr;


    for (int i = 0; i < length; i++){
        arr.append(rand() % 1000000);
    }

    ArraySequence<double> arr1(arr);

    auto time1 = getSortTime(index1, arr);
    auto time2 = getSortTime(index2, arr1);

    std::cout << Name_sorts[index1 - 1];
    for (int i = 0; i < 8; i++)
        std::cout << " ";
    std::cout << Name_sorts[index2 - 1] << '\n';

    std::cout << time1 << " microseconds            " << time2 <<" microseconds\n";
}


double getSortTime(int index2, ArraySequence<double>& arr1){

    Timer sort2;
    double time2;
    double array1[] = {9, 5, 3, 8,4, 1};
    ArraySequence<double> arra1(6, array1);
    switch (index2){
        case 1:
            sort2.Start();
            //std::cout << sort2.GetDuration() << '\n';
            Sorter<double>::BubbleSort(arr1, cmp);
            return sort2.GetDuration();
        case 2:
            sort2.Start();
            Sorter<double>::BubbleShakerSort(arr1, cmp);
            return sort2.GetDuration();
        case 3:
            sort2.Start();
            Sorter<double>::InsertionSort(arr1, cmp);
            return sort2.GetDuration();
        case 4:
            sort2.Start();
            Sorter<double>::BinaryInsertionSort(arr1, cmp);
            return sort2.GetDuration();
        case 5:
            sort2.Start();
            Sorter<double>::SelectionSort(arr1, cmp);
            return sort2.GetDuration();
        case 6:
            sort2.Start();
            Sorter<double>::CountingSort(arr1, cmp);
            return sort2.GetDuration();
        case 7:
            sort2.Start();
            Sorter<double>::MergeSort(arr1, 0, arr1.get_len() - 1, cmp);
            return sort2.GetDuration();
        case 8:
            sort2.Start();
            Sorter<double>::QuickSort(arr1, 0, arr1.get_len() - 1, cmp);
            return sort2.GetDuration();
        case 9:
            sort2.Start();
            Sorter<double>::ShellSort(arr1, cmp);
            return sort2.GetDuration();
        case 10:
            sort2.Start();
            Sorter<double>::ShellSelectSort(arr1, arra1, cmp);
            return sort2.GetDuration();
        case 11:
            sort2.Start();
            Sorter<double>::Node::BinaryTreeSort(arr1);
            time2 = sort2.GetDuration();
            break;
        case 12:
            sort2.Start();
            Sorter<double>::HeapSort(arr1, arr1.get_len() , cmp);
            return sort2.GetDuration();
    }
}


#endif //DAR_H_INTERFACE_H

