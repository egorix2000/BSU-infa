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
    Node* getNext() const;
    Node* getPrev() const;
    T& getValue();
    void setNext(Node<T>*);
    void setPrev(Node<T>*);
    void setValue(const T value);
};

template <class T>
Node<T>::Node(const T& value, Node *prev, Node *next) {
    this->value_ = value;
    this->prev_ = prev;
    this->next_ = next;
};

template <class T>
Node<T>* Node<T>::getNext() const {
    return next_;
};

template <class T>
Node<T>* Node<T>::getPrev() const {
    return prev_;
};

template <class T>
T& Node<T>::getValue() {
    return value_;
};

template <class T>
void Node<T>::setNext(Node<T>* next) {
    next_ = next;
};

template <class T>
void Node<T>::setPrev(Node<T>* prev) {
    prev_ = prev;
};

template <class T>
void Node<T>::setValue(const T value) {
    value_ = value;
}

#endif //LAB_NODE_H
