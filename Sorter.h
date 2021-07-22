#ifndef LAB1_3SEM_SORTER_H
#define LAB1_3SEM_SORTER_H
#include "ArraySequence.h"
#include "math.h"

template<class T>
class Sorter {
private:
    ArraySequence<T> array;
public:
    class IndexOutOfRange {
    public:
        int length;
        int index;

        IndexOutOfRange(int length, int index) : length(length), index(index) {};

        IndexOutOfRange() : length(-1), index(-1) {};
    };


    Sorter<T> &operator = (const Sorter<T> &arraySequence) {

        array = arraySequence.array;
        return *this;
    }

    Sorter<T> &operator = (Sorter<T> *arraySequence) {
        array = arraySequence->array;
        return *this;
    }

    Sorter() {
        array = ArraySequence<T>();
    }

    explicit Sorter(int size) {
        array = ArraySequence<T>(size);

    }

    Sorter(int count, T *items) {
        array = ArraySequence<T>(count,items);
    }

    explicit Sorter(const Sorter<T> &arra) {
        array = arra.array;
    }


    int get_len() const {
        return array.get_len();
    }

    T &get_i(int index) const{
        if (index < 0 || index >= array.get_len()) throw IndexOutOfRange(get_len(), index);
        return array.get_i(index);
    }

    void set_i(int index,T item) {
        if (index < 0 || index >= array.get_len()) throw IndexOutOfRange(get_len(), index);
        array.set_i(index, item);
    }

    T &operator[](int index) {
        if (index < 0 || index >= get_len())
            throw IndexOutOfRange(get_len(), index);
        return array[index];
    }

    void swap(T &number1, T &number2){
        T temp;
        temp = number1;
        number1 = number2;
        number2 = temp;
    }

    Sorter<T> *getSubSequence(Sorter<T> *arraysequence, int startIndex, int endIndex) {
        array = arraysequence->array.getSubSequence(startIndex, endIndex);
        return  this;
    }

    void BubbleSort(Sorter<T> &arraySequence){ //O(n^2)
        if (arraySequence.get_len() <= 1)
            return;
        int size = arraySequence.get_len();
        T temp;

        for (int i = 0; i < size; i++)
            for (int j = size - 1; j > i; j--){
                if (arraySequence.get_i(j - 1) > arraySequence.get_i(j)){
                    swap(arraySequence.get_i(j), arraySequence.get_i(j - 1));
                }
            }
    }



    void BubbleShakerSort(Sorter<T> &arraySequence){ //O(n^2)
        if (arraySequence.get_len() <= 1)
            return;

        int LeftSize = 1;
        int RightSize = arraySequence.get_len() - 1;

        while (LeftSize <= RightSize){
            for (int i = RightSize; i >= LeftSize; i--)
                if (arraySequence.get_i(i - 1) > arraySequence.get_i(i))
                    swap(arraySequence.get_i(i - 1), arraySequence.get_i(i));
            LeftSize++;


            for (int i = LeftSize; i <= RightSize; i++)
                if (arraySequence.get_i(i - 1) > arraySequence.get_i(i))
                    swap(arraySequence.get_i(i), arraySequence.get_i(i - 1));
            RightSize--;

        }
    }

    void InsertionSort(Sorter<T> &arraysequence){ // O(n^2)
        if (arraysequence.get_len() <= 1)
            return;

        for (int i = 1; i < arraysequence.get_len(); i++){
            int j = i - 1;
            T temp = arraysequence.get_i(i);
            while (arraysequence.get_i(j) > temp && j >= 0){
                arraysequence.get_i(j + 1) = arraysequence.get_i(j);
                j--;
                if (j == -1)
                    break;
            }
            arraysequence.get_i(j + 1) = temp;
        }
    }


    void BinaryInsertionSort(Sorter<T> &arraysequence){ // O(n^2)
        if (arraysequence.get_len() <= 1)
            return;

        for (int i = 0; i < arraysequence.get_len(); i++){
            T temp = arraysequence.get_i(i);
            if (i > 0)
                if (temp > arraysequence.get_i(i - 1))
                    continue;
                else
                {
                    int left = 0;
                    int right = i - 1;

                    while (left < right){
                        int mid = left + (right - left) / 2;
                        if (temp < arraysequence.get_i(mid))
                            right = mid;
                        else
                            left = mid + 1;
                    }

                    for (int j = i; j > left ; j--){
                        arraysequence.get_i(j) = arraysequence.get_i(j - 1);
                    }
                    arraysequence.get_i(left) = temp;
                }
        }
    }





    void SelectionSort(Sorter<T> &arraysequence){ //O(n^2)
        if (arraysequence.get_len() <= 1)
            return;

        for (int i = arraysequence.get_len()- 1; i >= 0; i--){
            T max = arraysequence.get_i(0);
            int number = 0;
            for (int j = 1; j <= i; j++){
                if (max < arraysequence.get_i(j)){
                    max = arraysequence.get_i(j);
                    number = j;
                }

            }
            swap(arraysequence->get_i(number), arraysequence->get_i(i));
            //std::cout << *arraysequence;
        }
    }


    void CountingSort(Sorter<T> &arraysequence){ //O(n +k);
        int length = arraysequence.get_len();
        if (length <= 1)
            return;
        T min = arraysequence.get_i(0);
        T max = arraysequence.get_i(0);
        for (int i = 0; i <length; i++){
            if (arraysequence.get_i(i) > max)
                max = arraysequence.get_i(i);

            if (arraysequence.get_i(i) < min)
                min = arraysequence.get_i(i);
        }

        Sorter<T> Temp(max - min + 1);
        //std::cout << "asdasd   " << Temp.get_i(0) << " " << min << " " << max <<  " " << Temp.get_len() << "\n";
        for (int i = 0; i < length; i++)
            if (min <= 0)
                Temp.get_i(arraysequence.get_i(i) + abs(min))++;
            else
                Temp.get_i(arraysequence.get_i(i) - min)++;

        int current = 0;
        for (int i = min; i <= max; i++){
            T k;
            if (min <= 0)
                k = i + abs(min);
            else
                k = i - min;
            for (int j = 0; j < Temp.get_i(k); j++){
                arraysequence.get_i(current) = i;
                current++;
            }
        }
    }


    void Merge(Sorter<T> &arraysequnce, int left, int mid, int right){
        int ArrOne = mid - left + 1;
        int ArrTwo = right - mid;

        Sorter<T> lefttTemp(ArrOne);
        lefttTemp.array = arraysequnce.array.getSubSequence(left, mid);

        Sorter<T> rightTemp(ArrTwo);
        rightTemp.array = arraysequnce.array.getSubSequence(mid + 1, right);
        auto indexOfMergedArray = left;
        auto indexOfArrOne = 0;
        auto indexOfArrTwo = 0;

        while (indexOfArrOne < ArrOne && indexOfArrTwo < ArrTwo) {
            if (lefttTemp.get_i(indexOfArrOne) <= rightTemp.get_i(indexOfArrTwo)) {
                arraysequnce.get_i(indexOfMergedArray) = lefttTemp.get_i(indexOfArrOne);
                indexOfArrOne++;
            }
            else {
                arraysequnce.get_i(indexOfMergedArray) = rightTemp.get_i(indexOfArrTwo);
                indexOfArrTwo++;
            }
            indexOfMergedArray++;
        }

        while (indexOfArrOne < ArrOne) {
            arraysequnce.get_i(indexOfMergedArray) = lefttTemp.get_i(indexOfArrOne);
            indexOfArrOne++;
            indexOfMergedArray++;
        }

        while (indexOfArrTwo < ArrTwo) {
            arraysequnce.get_i(indexOfMergedArray) = rightTemp.get_i(indexOfArrTwo);
            indexOfArrTwo++;
            indexOfMergedArray++;
        }

    }


    void MergeSort(Sorter<T> &arraysequence, int begin, int end){ //O(n log n)
        if (begin >= end)
            return;

        auto mid = begin + (end - begin) / 2;
        MergeSort(arraysequence, begin, mid);
        MergeSort(arraysequence, mid + 1, end);
        Merge(arraysequence, begin, mid, end);


    }


    void SquareSelectionSort(Sorter<T> &arraysequence){ //O(n^(3/2))
        T max = arraysequence[0];
        int length = arraysequence.get_len();
        for (int i = 1; i < length; i++){
            if (arraysequence[i] > max)
                max = arraysequence[i];
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
                if (arraysequence[j] < arraysequence[min])
                    min = j;
            MinInGroups.append(arraysequence[min]);
            arraysequence[min] = max;
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
                if (arraysequence[j] < arraysequence[min])
                    min = j;
            MinInGroups[(i / Groups)] = arraysequence[min];
            arraysequence[min] = max;
        }

        for (int i = 0; i < length; i++)
            arraysequence.array[i] = result[i];


    }

    void QuickSort(Sorter<T> &arraysequence, int left, int right){ // O(n log n)
        if (left < right)
        {
            T temp = arraysequence.get_i(right);
            int p = left;
            for (int i = left; i < right; i++) {
                if (arraysequence.get_i(i) < temp) {
                    swap(arraysequence.get_i(i), arraysequence.get_i(p));
                    p++;
                }
            }
            swap(arraysequence.get_i(p),arraysequence.get_i(right));

            QuickSort(arraysequence, left, p- 1);
            QuickSort(arraysequence, p + 1, right);
        }
    }


    void ShellSort(Sorter<T> &arr) { //O(n^2)
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
                    if (arr[i] > arr[j])
                        swap(arr[i], arr[j]);
                }
            }
            n--;
            d = pow(2, n) - 1;
        }
    }



    void ShellSelectSort(Sorter<T> &arr, Sorter<T> &another) {
        int length = arr.get_len();
        int n = another.get_len() - 1;

        while (n >= 0) {
            for (int i = 0; i < length; i++)
                for (int j = i + another[n]; j < length; j += another[n])
                    if (arr[i] < arr[j])
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
        void add(Node *&root, T value){
            if (root == nullptr) {
                root = new Node(value);
                return;
            }
            if (root->value < value)
                add(root->left, value);
            else
                add(root->right, value);
        }

        void input(Node *&root, Sorter<T> &arr) {
            for (int i = 0; i < arr.get_len(); i++) {
                add(root, arr[i]);
            }
        }

        void FromTreeToMassive(Node *&root, Sorter<T> &arr, int &i) {
            if (root == nullptr) {
                return;
            }

            FromTreeToMassive(root->left, arr, i);
            arr[i] = root->value;
            i++;
            FromTreeToMassive(root->right, arr, i);
        }

        void Delete(Node *&root) {
            if (root == nullptr)
                return;

            Delete(root->left);
            Delete(root->right);
            delete root;
        }

        void BinaryTreeSort(Sorter<T> &arr) { //O(n log n)
            int i = 0;

            Node *root = nullptr;
            root->input(root, arr);
            root->FromTreeToMassive(root, arr, i);
            root->cleanTree(root);
        }
    };



    void BuildMaxHeap (Sorter<T> &arr) {
        for (int i = arr.get_len() / 2; i >= 0; i--)
            Heap(arr, i);
    }

    void Heap(Sorter<T> &arr, int i) {
        int max = i;
        int left = 2 * i;
        int right = 2 * i + 1;

        if (left < get_len() && arr[left] > arr[i] ) max = left;
        if (right < get_len() && arr[right] > arr[max]) max = right;
        if (max != i) {
            swap(arr[i], arr[max]);
            Heap(arr, max);
        }
    }

    void HeapSort(Sorter<T> &arr) { // O (n log n)
        int length = arr.get_len();
        BuildMaxHeap(arr);
        for (int i = 0; i < length - 1; i++) {
            swap(arr[i], arr[length - 1]);
            Heap(arr, i);
        }
    }


};

template <class T>
std::ostream &operator << (std::ostream &cout, Sorter<T> &Sorter1) {
    for (int i = 0; i < Sorter1.get_len(); i++){
        std::cout << Sorter1.get_i(i) << " ";
    }
    std::cout << "\n";
}
#endif //LAB1_3SEM_SORTER_H
