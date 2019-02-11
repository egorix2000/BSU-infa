#ifndef LAB_SA_ITEM_H
#define LAB_SA_ITEM_H

template <class T>
class SA_item {
public:
    SA_item() : index(-1), info(T()) {}
    SA_item(long i, T d) : index(i), info(d) {}
    long index;
    T info;
};

#endif //LAB_SA_ITEM_H
