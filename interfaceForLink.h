#include "iostream"
#include "linkseq.h"
#include "sequence.h"
#include "complex"
#include "Sorter.h"
#include "random"


template<class T>
bool cmp1(T a1, T a2) {
    return a1 < a2;
}
double GetSortTime(int index2, LinkedSequence<double>& arr1);
void Compare();

void testFuncLinked(int Type);

void DeleteLinked(int Type, LinkedSequence<LinkedSequence<int>> *ArrInt,
            LinkedSequence<LinkedSequence<double>> *ArrDouble);
template<class T>
void DeleteLinkedType(LinkedSequence<LinkedSequence<T>> *ArrInt);

void DeleteLinkedAll(int Type, LinkedSequence<LinkedSequence<int>> *ArrInt,
               LinkedSequence<LinkedSequence<double>> *ArrDouble);
template<class T>
void DeleteLinkedAllType(LinkedSequence<LinkedSequence<T>> *ArrInt);

void readSequence1(int Type, LinkedSequence<LinkedSequence<int>> *ArrInt,
                  LinkedSequence<LinkedSequence<double>> *ArrDouble);
template<class T>
LinkedSequence<T> readSequence1Type(int count);


void printAll1(int Type, LinkedSequence<LinkedSequence<int>> *ArrInt,
              LinkedSequence<LinkedSequence<double>> *ArrDouble);
void printLinked(int Type, LinkedSequence<LinkedSequence<int>> *ArrInt,
                LinkedSequence<LinkedSequence<double>> *ArrDouble, int index1);


void Sort(int Type, LinkedSequence<LinkedSequence<int>> *ArrInt,
          LinkedSequence<LinkedSequence<double>> *ArrDouble);
template<class T>
LinkedSequence<T> SortType(LinkedSequence<LinkedSequence<T>> *ArrInt);
template<class T>
void SortTypeVoid(int Type, LinkedSequence<LinkedSequence<T>> *ArrInt);

int get_type();




void interfaceForLinked(LinkedSequence<LinkedSequence<int>> &ArrInt,
                       LinkedSequence<LinkedSequence<double>> &ArrDouble){

    while (true) {
        std::cout << "Can you choose option:\n"
                  << "\t0 - exit\n"
                  << "\t1 - Enter Sequence\n"
                  << "\t2 - print all Sequences\n"
                  << "\t3 - print Sequence[i]\n"
                  << "\t4 - Sort Sequence\n"
                  << "\t5 - compare Sorts\n"
                  << "\t6 - tests\n"
                  << "\t7 - DeleteLinked all\n"
                  << "\t8 - DeleteLinked Sequence[i]\n";
        int item0 = get_int(0, 8);

        if (item0 == 0) {
            std::cout << "Thanks for being with us ^-^\n";
            break;
        }
        int Type = get_type();
        switch (item0) {
            case 1:
                readSequence1(Type, &ArrInt, &ArrDouble);
                break;
            case 2:
                printAll1(Type, &ArrInt, &ArrDouble);
                break;
            case 3:
                printLinked(Type, &ArrInt, &ArrDouble, -1);
                break;
            case 4:
                Sort(Type, &ArrInt, &ArrDouble);
                break;
            case 5:
                Compare();
                break;
            case 6:
                testFuncLinked(Type);
                break;
            case 7:
                DeleteLinkedAll(Type, &ArrInt, &ArrDouble);
                break;
            case 8:
                DeleteLinked(Type, &ArrInt, &ArrDouble);
                break;

        }
    }


}



void readSequence1(int Type, LinkedSequence<LinkedSequence<int>> *ArrInt,
                  LinkedSequence<LinkedSequence<double>> *ArrDouble){
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

    LinkedSequence<int> ArrInt1;
    LinkedSequence<double> ArrDouble1;
    switch (Type) {
        case 1:
            ArrInt->append(readSequence1Type<int>(count));
            break;
        case 2:
            ArrDouble1 = readSequence1Type<double>(count);
            ArrDouble->append(ArrDouble1);
            break;
        default:
            break;
    }
}

template<class T>
LinkedSequence<T> readSequence1Type(int count){
    std::cout << "Can you enter the elements, please:\n";

    LinkedSequence<T> arr;
    for (int i = 0; i < count; i++){
        T item;
        std::cin >> item;

        arr.append(item);
    }

    return arr;
}



void printLinked(int Type, LinkedSequence<LinkedSequence<int>> *ArrInt,
                LinkedSequence<LinkedSequence<double>> *ArrDouble, int index1){
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

void printAll1(int Type, LinkedSequence<LinkedSequence<int>> *ArrInt,
              LinkedSequence<LinkedSequence<double>> *ArrDouble) {

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
            printLinked(Type, ArrInt, ArrDouble, i);
            std::cout << "\n";
        }
    } else {
        if (ArrDouble->get_len() == 0){
            std::cout << "Sorry, but Length == 0 \n";
            return;
        }
        for (int i = 0; i < ArrDouble->get_len(); i++) {
            printLinked(Type, ArrInt, ArrDouble, i);
            std::cout << "\n";
        }

    }
}

void Sort(int Type, LinkedSequence<LinkedSequence<int>> *ArrInt,
          LinkedSequence<LinkedSequence<double>> *ArrDouble)  {

    if (Type == 0){
        std::cout << "Thanks for being with us ^-^\n";
        return;
    }

    LinkedSequence<int> ArrInt1;
    LinkedSequence<double> ArrDouble1;

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
LinkedSequence<T> SortType(LinkedSequence<LinkedSequence<T>> *ArrInt){
    int length = ArrInt->get_len();
    if (length == 0){
        std::cout << "Sorry, but Length == 0\n";
        return LinkedSequence<T>();
    }
    std::cout << "Can you choose index of massive from 0 to " << ArrInt->get_len() - 1 << ",please\n";

    int index;
    std::cin >> index;
    while (index < 0 || index >= length) {
        if (index < 0 || index >= length)
            std::cout << "index can not be less than 0 and be bigger than length, please ReEnter count or enter -1 to exit\n";
        std::cin >> index;
        if (index == -1)
            return LinkedSequence<T>();
    }

    LinkedSequence<T> ArrTemp(ArrInt->operator[](index));

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
        return LinkedSequence<T>();
    }
    T Linked1[] = {9, 5, 3, 8,4, 1};
    LinkedSequence<T> arr(6, Linked1);
    switch (index22){
        case 1:
            Sorter<T>::BubbleSort(ArrTemp, cmp1);
            break;
        case 2:
            Sorter<T>::BubbleShakerSort(ArrTemp, cmp1);
            break;
        case 3:
            Sorter<T>::InsertionSort(ArrTemp, cmp1);
            break;
        case 4:
            Sorter<T>::BinaryInsertionSort(ArrTemp, cmp1);
            break;
        case 5:
            Sorter<T>::SelectionSort(ArrTemp, cmp1);
            break;
        case 6:
            Sorter<T>::CountingSort(ArrTemp, cmp1);
            break;
        case 7:
            Sorter<T>::MergeSort(ArrTemp, 0, ArrTemp.get_len() - 1, cmp1);
            break;
        case 8:
            Sorter<T>::QuickSort(ArrTemp, 0, ArrTemp.get_len() - 1, cmp1);
            break;
        case 9:
            Sorter<T>::ShellSort(ArrTemp, cmp1);
            break;
        case 10:
            Sorter<T>::ShellSelectSort(ArrTemp, arr, cmp1);
            break;
        case 11:
            Sorter<T>::Node::BinaryTreeSort(ArrTemp);
            break;
        case 12:
            Sorter<T>::HeapSort(ArrTemp, ArrInt->get_len(), cmp1);
            break;
    }
    return ArrTemp;
}

template<class T>
void SortTypeVoid(int Type, LinkedSequence<LinkedSequence<T>> *ArrInt){

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

    int index22 = get_int(0,2);
    if (index22 == 0){
        std::cout << "Thanks for being with us ^-^\n";
        return;
    }
    T Linked1[] = {9, 5, 3, 8,4, 1};
    LinkedSequence<T> arr(6, Linked1);
    switch (index22){
        case 1:
            Sorter<T>::BubbleSort(ArrInt->operator[](index), cmp1);
            break;
        case 2:
            Sorter<T>::BubbleShakerSort(ArrInt->operator[](index), cmp1);
            break;
        case 3:
            Sorter<T>::InsertionSort(ArrInt->operator[](index), cmp1);
            break;
        case 4:
            Sorter<T>::BinaryInsertionSort(ArrInt->operator[](index), cmp1);
            break;
        case 5:
            Sorter<T>::SelectionSort(ArrInt->operator[](index), cmp1);
            break;
        case 6:
            Sorter<T>::CountingSort(ArrInt->operator[](index), cmp1);
            break;
        case 7:
            Sorter<T>::MergeSort(ArrInt->operator[](index), 0, ArrInt->get_len() - 1, cmp1);
            break;
        case 8:
            Sorter<T>::QuickSort(ArrInt->operator[](index), 0,ArrInt->get_len() - 1, cmp1);
            break;
        case 9:
            Sorter<T>::ShellSort(ArrInt->operator[](index), cmp1);
            break;
        case 10:
            Sorter<T>::ShellSelectSort(ArrInt->operator[](index),arr, cmp1);
            break;
        case 11:
            Sorter<T>::Node::BinaryTreeSort(ArrInt->operator[](index));
            break;
        case 12:
            Sorter<T>::HeapSort(ArrInt->operator[](index), ArrInt->get_len(), cmp1);
            break;
    }


}


void DeleteLinked(int Type, LinkedSequence<LinkedSequence<int>> *ArrInt,
            LinkedSequence<LinkedSequence<double>> *ArrDouble){
    if (Type == 0){
        std::cout << "Thanks for being with us ^-^\n";
        return;
    }
    switch (Type) {
        case 1:
            DeleteLinkedType<int>(ArrInt);
            break;
        case 2:
            DeleteLinkedType<double>(ArrDouble);
            break;

    }

}

template<class T>
void DeleteLinkedType(LinkedSequence<LinkedSequence<T>> *ArrInt){
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
                  << "\t1 - DeleteLinked Sequence[i]\n"
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

void DeleteLinkedAll(int Type, LinkedSequence<LinkedSequence<int>> *ArrInt,
               LinkedSequence<LinkedSequence<double>> *ArrDouble){
    if (Type == 0){
        std::cout << "Thanks for being with us ^-^\n";
        return;
    }

    switch (Type) {
        case 1:
            DeleteLinkedAllType<int>(ArrInt);
            break;
        case 2:
            DeleteLinkedAllType<double>(ArrDouble);
            break;

    }
}

template<class T>
void DeleteLinkedAllType(LinkedSequence<LinkedSequence<T>> *ArrInt){
    if (ArrInt->get_len() == 0){
        std::cout << "Sorry, but massive is empty \n";
        return;
    }
    int length =ArrInt->get_len();
    for (int i = 0; i < length; i++){
        ArrInt->pop(0);
    }
}

void testFuncLinked(int Type){
    if (Type == 0)
        return;

    if (Type == 1){
        LinkedSequence<int> Arr;
        int length = rand()%100;

        for (int i = 0; i < length; i++){
            Arr.append(rand() % 1000000);
        }
        LinkedSequence<int> ar(Arr);
        Sorter<int>::QuickSort(ar, 0 , ar.get_len() - 1, cmp1);
        int Linked[] = {9, 5, 3, 8,4, 1};
        LinkedSequence<int> arra(6, Linked);

        for (int i = 1; i <= 12; i++){
            LinkedSequence<int> arr(Arr);

            std::cout << i << ": ";
            switch (i){
                case 1:
                    Sorter<int>::BubbleSort(arr, cmp1);
                    if (ar == arr)
                        std::cout << "Ohhh, It's actually working, my friend\n";
                    else
                        std::cout << "What is a duuuude, you can not create normal sort\n";
                    break;
                case 2:
                    Sorter<int>::BubbleShakerSort(arr, cmp1);
                    if (ar == arr)
                        std::cout << "Ohhh, It's actually working, my friend\n";
                    else
                        std::cout << "What is a duuuude, you can not create normal sort\n";
                    break;
                case 3:
                    Sorter<int>::InsertionSort(arr, cmp1);
                    if (ar == arr)
                        std::cout << "Ohhh, It's actually working, my friend\n";
                    else
                        std::cout << "What is a duuuude, you can not create normal sort\n";
                    break;
                case 4:
                    Sorter<int>::BinaryInsertionSort(arr, cmp1);
                    if (ar == arr)
                        std::cout << "Ohhh, It's actually working, my friend\n";
                    else
                        std::cout << "What is a duuuude, you can not create normal sort\n";
                    break;
                case 5:
                    Sorter<int>::SelectionSort(arr, cmp1);
                    if (ar == arr)
                        std::cout << "Ohhh, It's actually working, my friend\n";
                    else
                        std::cout << "What is a duuuude, you can not create normal sort\n";
                    break;
                case 6:
                    Sorter<int>::CountingSort(arr, cmp1);
                    if (ar == arr)
                        std::cout << "Ohhh, It's actually working, my friend\n";
                    else
                        std::cout << "What is a duuuude, you can not create normal sort\n";
                    break;
                case 7:
                    Sorter<int>::MergeSort(arr, 0, arr.get_len() - 1, cmp1);
                    if (ar == arr)
                        std::cout << "Ohhh, It's actually working, my friend\n";
                    else
                        std::cout << "What is a duuuude, you can not create normal sort\n";
                    break;
                case 8:
                    Sorter<int>::QuickSort(arr, 0, arr.get_len() - 1, cmp1);
                    if (ar == arr)
                        std::cout << "Ohhh, It's actually working, my friend\n";
                    else
                        std::cout << "What is a duuuude, you can not create normal sort\n";
                    break;
                case 9:
                    Sorter<int>::ShellSort(arr, cmp1);
                    if (ar == arr)
                        std::cout << "Ohhh, It's actually working, my friend\n";
                    else
                        std::cout << "What is a duuuude, you can not create normal sort\n";
                    break;
                case 10:
                    Sorter<int>::ShellSelectSort(arr, arra, cmp1);
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
                    Sorter<int>::HeapSort(arr, arr.get_len(), cmp1);
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
        LinkedSequence<double> Arr1;
        int length = rand()%100;

        for (int i = 0; i < length; i++){
            Arr1.append(rand() % 1000000);
        }
        LinkedSequence<double> ar1(Arr1);
        Sorter<double>::QuickSort(ar1, 0 , ar1.get_len() - 1, cmp1);
        double Linked1[] = {9, 5, 3, 8,4, 1};
        LinkedSequence<double> arra1(6, Linked1);

        for (int i = 1; i <= 12; i++){
            LinkedSequence<double> arr1(Arr1);

            std::cout << i << ": ";
            switch (i){
                case 1:
                    Sorter<double>::BubbleSort(arr1, cmp1);
                    if (ar1 == arr1)
                        std::cout << "Ohhh, It's actually working, my friend\n";
                    else
                        std::cout << "What is a duuuude, you can not create normal sort\n";
                    break;
                case 2:
                    Sorter<double>::BubbleShakerSort(arr1, cmp1);
                    if (ar1 == arr1)
                        std::cout << "Ohhh, It's actually working, my friend\n";
                    else
                        std::cout << "What is a duuuude, you can not create normal sort\n";
                    break;
                case 3:
                    Sorter<double>::InsertionSort(arr1, cmp1);
                    if (ar1 == arr1)
                        std::cout << "Ohhh, It's actually working, my friend\n";
                    else
                        std::cout << "What is a duuuude, you can not create normal sort\n";
                    break;
                case 4:
                    Sorter<double>::BinaryInsertionSort(arr1, cmp1);
                    if (ar1 == arr1)
                        std::cout << "Ohhh, It's actually working, my friend\n";
                    else
                        std::cout << "What is a duuuude, you can not create normal sort\n";
                    break;
                case 5:
                    Sorter<double>::SelectionSort(arr1, cmp1);
                    if (ar1 == arr1)
                        std::cout << "Ohhh, It's actually working, my friend\n";
                    else
                        std::cout << "What is a duuuude, you can not create normal sort\n";
                    break;
                case 6:
                    Sorter<double>::CountingSort(arr1, cmp1);
                    if (ar1 == arr1)
                        std::cout << "Ohhh, It's actually working, my friend\n";
                    else
                        std::cout << "What is a duuuude, you can not create normal sort\n";
                    break;
                case 7:
                    Sorter<double>::MergeSort(arr1, 0, arr1.get_len() - 1, cmp1);
                    if (ar1 == arr1)
                        std::cout << "Ohhh, It's actually working, my friend\n";
                    else
                        std::cout << "What is a duuuude, you can not create normal sort\n";
                    break;
                case 8:
                    Sorter<double>::QuickSort(arr1, 0, arr1.get_len() - 1, cmp1);
                    if (ar1 == arr1)
                        std::cout << "Ohhh, It's actually working, my friend\n";
                    else
                        std::cout << "What is a duuuude, you can not create normal sort\n";
                    break;
                case 9:
                    Sorter<double>::ShellSort(arr1, cmp1);
                    if (ar1 == arr1)
                        std::cout << "Ohhh, It's actually working, my friend\n";
                    else
                        std::cout << "What is a duuuude, you can not create normal sort\n";
                    break;
                case 10:
                    Sorter<double>::ShellSelectSort(arr1, arra1, cmp1);
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
                    Sorter<double>::HeapSort(arr1, arr1.get_len() , cmp1);
                    if (ar1 == arr1)
                        std::cout << "Ohhh, It's actually working, my friend\n";
                    else
                        std::cout << "What is a duuuude, you can not create normal sort\n";
                    break;
            }
        }
    }

}


void Compare(){

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

    while (true){
        if (index2 == index1){
            std::cout << "Ooops, can you rechoose sort\n";
            index2 = get_int(0, 12);
        }
        else
            break;
    }


    std::cout << "Please, choose count of number from 10 to 100\n";
    int length = get_int(10, 100);

    LinkedSequence<double> arr;


    for (int i = 0; i < length; i++){
        arr.append(rand() % 1000000);
    }

    LinkedSequence<double> arr1(arr);

    auto time1 = GetSortTime(index1, arr);
    auto time2 = GetSortTime(index2, arr1);

    std::cout << Name_sorts[index1 - 1];
    for (int i = 0; i < 8; i++)
        std::cout << " ";
    std::cout << Name_sorts[index2 - 1] << '\n';

    std::cout << time1 << " microseconds            " << time2 <<" microseconds\n";
}


double GetSortTime(int index2, LinkedSequence<double>& arr1){

    Timer sort2;
    double time2;
    double array1[] = {9, 5, 3, 8,4, 1};
    LinkedSequence<double> arra1(6, array1);
    switch (index2){
        case 1:
            sort2.Start();

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




