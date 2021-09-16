#ifndef LAB1_3SEM_SORTER_H
#define LAB1_3SEM_SORTER_H
#include "sequence.h"
#include "ArraySequence.h"
#include "cmath"

template<class T>
class Sorter {
public:

    class IndexOutOfRange {
    public:
        int length;
        int index;

        IndexOutOfRange(int length, int index) : length(length), index(index) {};

        IndexOutOfRange() : length(-1), index(-1) {};
    };



    static void swap(T &number1, T &number2){
        T temp;
        temp = number1;
        number1 = number2;
        number2 = temp;
    }



    static void BubbleSort(Sequence<T> &sequence, bool(*cmp)(T t1, T t2)){ //O(n^2)

        if (sequence.get_len() <= 1)
            return ;

        //ArraySequence<T> sequence(sequence);

        int size = sequence.get_len();
        T temp;

        for (int i = 0; i < size; i++)
            for (int j = size - 1; j > i; j--){
                if (cmp(sequence[j], sequence[j - 1])){
                    swap(sequence[j], sequence[j - 1]);
                }
            }

        //return sequence;
    }

    static void BubbleShakerSort(Sequence<T> &sequence, bool(*cmp)(T t1, T t2)){ //O(n^2)
        if (sequence.get_len() <= 1)
            return;

        int LeftSize = 1;
        int RightSize = sequence.get_len() - 1;

        while (LeftSize <= RightSize){
            for (int i = RightSize; i >= LeftSize; i--)
                if (cmp(sequence[i], sequence[i - 1]))
                    swap(sequence[i - 1], sequence[i]);
            LeftSize++;


            for (int i = LeftSize; i <= RightSize; i++)
                if (cmp(sequence[i], sequence[i - 1]))
                    swap(sequence[i], sequence[i - 1]);
            RightSize--;

        }
    }

    static void InsertionSort(Sequence<T> &sequence, bool(*cmp)(T t1, T t2)){ // O(n^2)
        if (sequence.get_len() <= 1)
            return;

        for (int i = 1; i < sequence.get_len(); i++){
            int j = i - 1;
            T temp = sequence[i];
            while (cmp(temp, sequence[j]) && j >= 0){
                sequence[j + 1] = sequence[j];
                j--;
                if (j == -1)
                    break;
            }
            sequence[j + 1] = temp;
        }
    }


    static void BinaryInsertionSort(Sequence<T> &sequence, bool(*cmp)(T t1, T t2)){ // O(n^2)
        if (sequence.get_len() <= 1)
            return;

        for (int i = 0; i < sequence.get_len(); i++){
            T temp = sequence[i];
            if (i > 0)
                if (cmp(sequence[i - 1], temp))
                    continue;
                else
                {
                    int left = 0;
                    int right = i - 1;

                    while (left < right){
                        int mid = left + (right - left) / 2;
                        if (cmp(temp,sequence[mid]))
                            right = mid;
                        else
                            left = mid + 1;
                    }

                    for (int j = i; j > left ; j--){
                        sequence[j] = sequence[j - 1];
                    }
                    sequence[left] = temp;
                }
        }
    }





    static void SelectionSort(Sequence<T> &sequence, bool(*cmp)(T t1, T t2)){ //O(n^2)
        if (sequence.get_len() <= 1)
            return;

        for (int i = sequence.get_len() - 1; i >= 0; i--){
            T max = sequence[0];
            int number = 0;
            for (int j = 1; j <= i; j++){
                if (cmp(max, sequence[j])){
                    max = sequence[j];
                    number = j;
                }

            }
            swap(sequence[number], sequence[i]);
            //std::cout << *sequence;
        }
    }


    static void CountingSort(Sequence<T> &sequence, bool(*cmp)(T t1, T t2)){ //O(n +k);
        int length = sequence.get_len();
        if (length <= 1)
            return;
        T min = sequence[0];
        T max = sequence[0];
        for (int i = 0; i <length; i++){
            if (cmp(max,sequence[i]))
                max = sequence[i];

            if (cmp(sequence[i], min))
                min = sequence[i];
        }

        ArraySequence<T> Temp(max - min + 1);
        //std::cout << "asdasd   " << Temp.get_i(0) << " " << min << " " << max <<  " " << Temp.get_len() << "\n";
        for (int i = 0; i < length; i++)
            if (min <= 0)
                Temp[sequence[i] + abs(min)]++;
            else
                Temp[sequence[i] - min]++;

        int current = 0;
        for (int i = min; i <= max; i++){
            T k;
            if (min <= 0)
                k = i + abs(min);
            else
                k = i - min;
            for (int j = 0; j < Temp[k]; j++){
                sequence[current] = i;
                current++;
            }
        }
    }


    static void Merge(Sequence<T> &sequence, int left, int mid, int right, bool(*cmp)(T t1, T t2)){
        ArraySequence<T> temp(sequence);

        int start = left;
        int last = mid + 1;

        for (int j = left; j <= right; j++)
            if ((start <= mid) && ((last > right) || (cmp(sequence[start], sequence[last])))) {
                temp[j] = sequence[start];
                start++;
            } else {
                temp[j] = sequence[last];
                last++;
            }

        for (int i = 0; i < temp.get_len(); i++)
            sequence[i] = temp[i];

    }

    static void MergeSort(Sequence<T> &sequence, int begin, int end, bool(*cmp)(T t1, T t2)){ //O(n log n)
        if (begin >= end)
            return;

        auto mid = begin + (end - begin) / 2;
        MergeSort(sequence, begin, mid, cmp);
        MergeSort(sequence, mid + 1, end, cmp);
        Merge(sequence, begin, mid, end, cmp);


    }


    static void SquareSelectionSort(Sequence<T> &sequence, bool(*cmp)(T t1, T t2)){ //O(n^(3/2))
        T max = sequence[0];
        int length = sequence.get_len();
        for (int i = 1; i < length; i++){
            if (cmp(max, sequence[i] ))
                max = sequence[i];
        }


        int Groups = (int) sqrt((double) length) ;
        int min = 0;

        if (pow((double)Groups, 2) < length)
            Groups++;
        ArraySequence<T> result;
        ArraySequence<T> MinInGroups;

        for (int i = Groups * min; i < length; i += Groups) {
            min = i;
            for (int j = i + 1; j < i + Groups && j < length; j++)
                if (cmp(sequence[j], sequence[min]))
                    min = j;
            MinInGroups.append(sequence[min]);
            sequence[min] = max;
        }


        while (true) {
            min = 0;
            for (int k = 1; k < Groups; k++)
                if (MinInGroups[k] < MinInGroups[min])
                    min = k;
            result.append(MinInGroups[min]);

            if (result.get_len() == length)
                break;

            int i = Groups * min;
            min = i;
            for (int j = i + 1; j < i + Groups && j < length; j++)
                if (cmp(sequence[j], sequence[min]))
                    min = j;
            MinInGroups[(i / Groups)] = sequence[min];
            sequence[min] = max;
        }

        for (int i = 0; i < length; i++)
            sequence[i] = result[i];


    }

    static void QuickSort(Sequence<T> &sequence, int left, int right, bool(*cmp)(T t1, T t2)){ // O(n log n)
        if (left < right)
        {
            T temp = sequence[right];
            int p = left - 1;
            for (int i = left; i < right; i++) {
                if (cmp(sequence[i], temp)) {
                    p++;
                    swap(sequence[i], sequence[p]);

                }
            }
            p++;
            swap(sequence[p], sequence[right]);

            QuickSort(sequence, left, p - 1, cmp);
            QuickSort(sequence, p + 1, right, cmp);
        }
    }


    static void ShellSort(Sequence<T> &arr, bool(*cmp)(T t1, T t2)) { //O(n^2)
        int length = arr.get_len();
        int d = 1;
        int n = 0;
        while (d < length) {
            n++;
            d = pow(2, n) - 1;
        }
        while (d > 0) {
            for (int i = 0; i < length; i++) {
                for (int j = i + d; j < length; j += d) {
                    if (cmp(arr[j], arr[i]))
                        swap(arr[i], arr[j]);
                }
            }
            n--;
            d = pow(2, n) - 1;
        }
    }



    static void ShellSelectSort(Sequence<T> &arr, Sequence<T> &another, bool(*cmp)(T t1, T t2)) {
        int length = arr.get_len();
        int n = another.get_len() - 1;

        while (n >= 0) {
            for (int i = 0; i < length; i++)
                for (int j = i + another[n]; j < length; j += another[n])
                    if (cmp(arr[i], arr[j]))
                        swap(arr[i], arr[j]);


            n--;
        }
    }

    class Node {
        Node *left = nullptr;
        Node *right = nullptr;
        T value;

        explicit Node(T value1) : value(value1) {};
    public:
        static void add(Node *&root, T value){
            if (root == nullptr) {
                root = new Node(value);
                return;
            }
            if (root->value < value)
                add(root->left, value);
            else
                add(root->right, value);
        }

        static void input(Node *&root, Sequence<T> &arr) {
            for (int i = 0; i < arr.get_len(); i++) {
                add(root, arr[i]);
            }
        }

        static void FromTreeToMassive(Node *&root, Sequence<T> &arr, int &i) {
            if (root == nullptr) {
                return;
            }

            FromTreeToMassive(root->left, arr, i);
            arr[i] = root->value;
            i++;
            FromTreeToMassive(root->right, arr, i);
        }

        static void Delete(Node *&root) {
            if (root == nullptr)
                return;

            Delete(root->left);
            Delete(root->right);
            delete root;
        }

        static void BinaryTreeSort(Sequence<T> &arr) { //O(n log n)
            int i = 0;

            Node *root = nullptr;
            root->input(root, arr);
            root->FromTreeToMassive(root, arr, i);
            root->cleanTree(root);
        }
    };



    static void BuildMaxHeap (Sequence<T> &arr, bool(*cmp)(T t1, T t2)) {
        for (int i = arr.get_len() / 2; i >= 0; i--)
            Heap(arr, i, cmp);
    }

    static void Heap(Sequence<T> &arr, int i, bool(*cmp)(T t1, T t2)) {
        int max = i;
        int left = 2 * i;
        int right = 2 * i + 1;

        if (left < arr.get_len() && cmp(arr[i], arr[left])) max = left;
        if (right < arr.get_len() && cmp(arr[max], arr[right])) max = right;
        if (max != i) {
            swap(arr[i], arr[max]);
            Heap(arr, max, cmp);
        }
    }
//TODO не работает
    static void HeapSort(Sequence<T> &arr, bool(*cmp)(T t1, T t2)) { // O (n log n)
        int length = arr.get_len();
        BuildMaxHeap(arr, cmp);
        for (int i = 0; i < length - 1; i++) {
            swap(arr[i], arr[length - 1]);
            Heap(arr, i, cmp);
        }
    }

    static void Bitonicsort(Sequence<T> &arr, bool(*cmp)(T t1, T t2)) {
        int length = arr.get_len();
        for (int p = 1; p < length; p *= 2)   //почти номер этапа (максимальная длина компаратора)
            for (int k = p; k > 0; k /= 2)    //длина мгновенного компаратора (на каком расстоянии сравниваемые элементы)
                for (int j = k % p; j + k < length; j += 2*k)  //начальный элемент сравнения и отступ
                    for (int i = 0; i < length - j - k; i++)     //проход по всем элмеентам
                        if ((j + i) / (2*p) == (j + i + k) / (2*p))
                            if (cmp( arr[j + i + k], arr[j + i] ))
                                swap(arr[j + i] ,arr[j+i+k]);
    }


};

#endif //LAB1_3SEM_SORTER_H
