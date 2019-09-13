#ifndef LAB_NODE_H
#define LAB_NODE_H

template <class T>
class Node {
private:
    T value_;
    Node *next_;
    Node *prev_;
public:
    Node(const T& value, Node *prev, Node *next);
    ~Node();
    const Node* getNext();
    const Node* getPrev();
    const T& getValue();
    void setNext(Node<T>*);
    void setPrev(Node<T>*);
    void setValue(const T value);
};


#endif //LAB_NODE_H
