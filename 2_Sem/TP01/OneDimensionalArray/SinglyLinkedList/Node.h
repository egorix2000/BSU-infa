#ifndef LAB_NODE_H
#define LAB_NODE_H

template <class T>
class Node{
public:
    T value;
    Node* next;

    Node(const T& value, Node* nextNode);
};

template <class T>
Node<T>::Node(const T& value, Node* nextNode) {
    this->value = value;
    this->next = nextNode;
};


#endif //LAB_NODE_H
