
#ifndef PROSTO_LinkedSequence_H
#define PROSTO_LinkedSequence_H
#include "link_list.h"
#include "iostream"


template<class T>
class LinkedSequence{
private:
    Linked_List<T> Llst;
public:
    class IndexOutOfRange{
    public:
        int length;
        int index;
        IndexOutOfRange(int length, int index): length(length), index(index) {};
        IndexOutOfRange(): length(-1), index(-1) {};
    };

    LinkedSequence<T>& operator = (const LinkedSequence<T> &listSequence) {
        Llst = listSequence.Llst;
        return *this;
    }

    LinkedSequence<T>& operator = (LinkedSequence<T> *listSequence) {
        Llst = listSequence->Llst;
        return *this;
    }

    int get_len(){
        return Llst.get_len();
    }

    LinkedSequence(){
        Llst = Linked_List<T>();
    }

    LinkedSequence(int size){
        Llst = Linked_List<T>(size);
    }

    LinkedSequence(const LinkedSequence<T> &list){
        Llst = list.Llst;
    }

    T get_first(){
        if (Llst.get_len() == 0) throw IndexOutOfRange(get_len(), get_len());
        return Llst.get_first();
    }

    T get_last(){
        if (Llst.get_len() == 0) throw IndexOutOfRange(get_len(),get_len());
        return Llst.get_last();
    }

    T get_i(int index){
        if (index < 0 || index >= Llst.get_len()) throw IndexOutOfRange(get_len(), index);
        return Llst.get_i(index);
    }

    void set_i(int index, T item){
        if (index < 0 || index >= Llst.get_len()) throw IndexOutOfRange(get_len(), index);
        Llst.set_i(index, item);
    }

    LinkedSequence<T> *getSubSequence(int startIndex, int endIndex) {
        if (startIndex < 0 || startIndex >= Llst.get_len())
            throw IndexOutOfRange(get_len(), startIndex);
        if (endIndex < 0 || endIndex > Llst.get_len())
            throw IndexOutOfRange(get_len(), endIndex);

        int delta = startIndex < endIndex ? 1 : -1;

        auto NewLst = new LinkedSequence<T>;
        for (int i = startIndex; i != endIndex; i += delta) {
            NewLst->append(Llst.get_i(i));
        }

        return NewLst;
    }

    void append(T item){
        Llst.append(item);
    }

    void prepend(T item){
        Llst.prepend(item);
    }

    void insert(T item, int index){
        this->Llst.insert(item, index);
    }

    LinkedSequence<T> *concat(LinkedSequence<T> *list){
        for ( int i = 0; i < list->get_len(); i++){
            this->append(list->get_i(i));
        }
        return this;
    }

    int where(T item){
        for (int i = 0; i < this->Llst.get_len(); i++){
            //if (this->Llst.get_i(i) == item)
                return i;

        }
        return -1;
    }

    LinkedSequence<LinkedSequence<T>*> *split(int index) {
        if (index < 0 || index >= get_len())
            throw IndexOutOfRange();

        auto *t1 = new LinkedSequence<T>;
        auto *t2 = new LinkedSequence<T>;
        auto *NewArr = new LinkedSequence<LinkedSequence<T>*>;

        for (int i = 0; i < index; i++){
            t1->append(this->Llst.get_i(i));
        }

        for (int i = index; i < this->Llst.get_len(); i++){
            t2->append(this->Llst.get_i(i));
        }
        NewArr->append(t1);
        NewArr->append(t2);
        return NewArr;
    }

    LinkedSequence<Linked_List<T>*>* zip(LinkedSequence<T> lst){
        auto *NewLst = new LinkedSequence<Linked_List<T>*>;
        int min;
        if (Llst.get_len() < lst.Llst.get_len()){
            min = Llst.get_len();
        }
        else {
            min = lst.Llst.get_len();
        }

        for (int i = 0; i < min; i++){
            auto *tuple = new Linked_List<T>(2);
            tuple->set_i(0, get_i(i));
            tuple->set_i(1, lst.get_i(i));
            NewLst->append(tuple);
        }

        return NewLst;
    }

};
#endif //PROSTO_LinkedSequence_H
