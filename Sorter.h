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


    static Sequence<T>* BubbleSortNV(Sequence<T> &sequence, bool(*cmp)(T t1, T t2)){ //O(n^2)

        if (sequence.get_len() <= 1)
            return sequence.clone();

        auto newSeq = sequence.clone();

        int size = newSeq.get_len();
        T temp;

        for (int i = 0; i < size; i++)
            for (int j = size - 1; j > i; j--){
                if (cmp(newSeq[j], newSeq[j - 1])){
                    swap(newSeq[j], newSeq[j - 1]);
                }
            }

        return newSeq;
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

    static Sequence<T>* BubbleShakerSortNV(Sequence<T> &sequence, bool(*cmp)(T t1, T t2)){ //O(n^2)
        if (sequence.get_len() <= 1)
            return sequence.clone();

        auto newSeq = sequence.clone();

        int LeftSize = 1;
        int RightSize = newSeq.get_len() - 1;

        while (LeftSize <= RightSize){
            for (int i = RightSize; i >= LeftSize; i--)
                if (cmp(newSeq[i], newSeq[i - 1]))
                    swap(newSeq[i - 1], newSeq[i]);
            LeftSize++;


            for (int i = LeftSize; i <= RightSize; i++)
                if (cmp(newSeq[i], newSeq[i - 1]))
                    swap(newSeq[i], newSeq[i - 1]);
            RightSize--;

        }
        return newSeq;
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

    static Sequence<T>* InsertionSortNV(Sequence<T> &sequence, bool(*cmp)(T t1, T t2)){ // O(n^2)
        if (sequence.get_len() <= 1)
            return sequence.clone();

        auto newSeq = sequence.clone();

        for (int i = 1; i < sequence.get_len(); i++){
            int j = i - 1;
            T temp = newSeq[i];
            while (cmp(temp, newSeq[j]) && j >= 0){
                newSeq[j + 1] = newSeq[j];
                j--;
                if (j == -1)
                    break;
            }
            newSeq[j + 1] = temp;
        }
        return newSeq;
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


    static Sequence<T>* BinaryInsertionSortNV(Sequence<T> &sequence, bool(*cmp)(T t1, T t2)){ // O(n^2)
        if (sequence.get_len() <= 1)
            return sequence.clone();

        auto newSeq = sequence.clone();

        for (int i = 0; i < newSeq.get_len(); i++){
            T temp = newSeq[i];
            if (i > 0)
                if (cmp(newSeq[i - 1], temp))
                    continue;
                else
                {
                    int left = 0;
                    int right = i - 1;

                    while (left < right){
                        int mid = left + (right - left) / 2;
                        if (cmp(temp,newSeq[mid]))
                            right = mid;
                        else
                            left = mid + 1;
                    }

                    for (int j = i; j > left ; j--){
                        newSeq[j] = newSeq[j - 1];
                    }
                    newSeq[left] = temp;
                }
        }
        return newSeq;
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

    static Sequence<T>* SelectionSortNV(Sequence<T> &sequence, bool(*cmp)(T t1, T t2)){ //O(n^2)
        if (sequence.get_len() <= 1)
            return sequence.clone();

        auto newSeq = sequence.clone();

        for (int i = newSeq.get_len() - 1; i >= 0; i--){
            T max = newSeq[0];
            int number = 0;
            for (int j = 1; j <= i; j++){
                if (cmp(max, newSeq[j])){
                    max = newSeq[j];
                    number = j;
                }

            }
            swap(newSeq[number], newSeq[i]);
            //std::cout << *sequence;
        }
        return newSeq;
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



    static Sequence<T>* CountingSortNV(Sequence<T> &sequence, bool(*cmp)(T t1, T t2)){ //O(n +k);
        int length = sequence.get_len();
        if (length <= 1)
            return sequence.clone();

        auto newSeq = sequence.clone();

        T min = newSeq[0];
        T max = newSeq[0];
        for (int i = 0; i <length; i++){
            if (cmp(max, newSeq[i]))
                max = newSeq[i];

            if (cmp(newSeq[i], min))
                min = newSeq[i];
        }

        ArraySequence<T> Temp(max - min + 1);

        for (int i = 0; i < length; i++)
            if (min <= 0)
                Temp[newSeq[i] + abs(min)]++;
            else
                Temp[newSeq[i] - min]++;

        int current = 0;
        for (int i = min; i <= max; i++){
            T k;
            if (min <= 0)
                k = i + abs(min);
            else
                k = i - min;
            for (int j = 0; j < Temp[k]; j++){
                newSeq[current] = i;
                current++;
            }
        }
    }


    static void Merge(Sequence<T> &sequence, int left, int mid, int right, bool(*cmp)(T t1, T t2)){
        //ArraySequence<T> temp(sequence);

        auto temp = sequence.clone();

        int start = left;
        int last = mid + 1;

        for (int j = left; j <= right; j++)
            if ((start <= mid) && ((last > right) || (cmp(sequence[start], sequence[last])))) {
                temp->operator[](j) = sequence[start];
                start++;
            } else {
                temp->operator[](j) = sequence[last];
                last++;
            }

        for (int i = 0; i < temp->get_len(); i++)
            sequence[i] = temp->operator[](i);

    }

    static void MergeSort(Sequence<T> &sequence, int begin, int end, bool(*cmp)(T t1, T t2)){ //O(n log n)
        if (begin >= end)
            return;

        if (sequence.get_len() == 0)
            return;

        auto mid = begin + (end - begin) / 2;
        MergeSort(sequence, begin, mid, cmp);
        MergeSort(sequence, mid + 1, end, cmp);
        Merge(sequence, begin, mid, end, cmp);


    }


    static void QuickSort(Sequence<T> &sequence, int left, int right, bool(*cmp)(T t1, T t2)){ // O(n log n)
        if (sequence.get_len() == 0)
            return;
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
        if (length == 0)
            return;
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
        if (length == 0)
            return;
        int n = another.get_len() - 1;

        while (n >= 0) {
            for (int i = 0; i < length; i++)
                for (int j = i + another[n]; j < length; j += another[n])
                    if (cmp(arr[j], arr[i]))
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
            if (root->value > value)
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
            root->Delete(root);
        }
    };



    static void BuildMaxHeap (Sequence<T> &arr, int n, bool(*cmp)(T t1, T t2)) {
        for (int i = n / 2; i >= 0; i--)
            Heap(arr, n, i, cmp);
    }

    static void Heap(Sequence<T> &arr, int n, int i, bool(*cmp)(T t1, T t2)) {
        int max;
        int left = 2 * i;
        int right = 2 * i + 1;

        if (left < n && cmp(arr[i], arr[left]))
            max = left;
        else
            max = i;

        if (right < n && cmp(arr[max], arr[right]))
            max = right;

        if (max != i) {
            swap(arr[i], arr[max]);
            Heap(arr,n,  max, cmp);
        }
    }

    static void HeapSort(Sequence<T> &arr, int n, bool(*cmp)(T t1, T t2)) { // O (n log n)
        int length = n;
        if (length == 0)
            return;
        BuildMaxHeap(arr, n,  cmp);
        for (int i = n - 1; i >= 0; i--) {
            swap(arr[i], arr[0]);
            Heap(arr, i, 0, cmp);
        }

    }



};

#endif //LAB1_3SEM_SORTER_H
