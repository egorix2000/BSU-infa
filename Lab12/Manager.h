#pragma once
#ifndef LAB_MANAGER_H
#define LAB_MANAGER_H

#include <string>
#include <iostream>
#include <vector>
#include "BinarySearchTree.h"
#include "Node.h"
#include "Exception.h"
#include "FileManager.h"

template <class T>
class Manager{
    public:
        Manager();
        Manager(std::string pathToProject);
        ~Manager();
        void setPathToProject(std::string pathToProject);
        bool addItem(T item);
        bool deleteItem(T item);
        bool createBinarySearchTree(std::string fileName);
        Node<T> findItem(T item, bool& isSucceed);
        bool clearBinarySearchTree();
    private:
        BinarySearchTree<T>* binarySearchTree_;
        FileManager<T>* fileManager_;
};

template <class T>
Manager<T>::Manager() {
    binarySearchTree_ = new BinarySearchTree<T>();
    fileManager_ = new FileManager<T>();
}

template <class T>
Manager<T>::Manager(std::string pathToProject) {
    binarySearchTree_ = new BinarySearchTree<T>();
    fileManager_ = new FileManager<T>(pathToProject);
}

template <class T>
Manager<T>::~Manager() {
    if (binarySearchTree_ != 0) {
        delete binarySearchTree_;
    }
    if (fileManager_ != 0) {
        delete fileManager_;
    }
    binarySearchTree_ = 0;
    fileManager_ = 0;
}

template <class T>
void Manager<T>::setPathToProject(std::string pathToProject){
    fileManager_->setPathToProject(pathToProject);
}

template <class T>
bool Manager<T>::addItem(T item) {
    binarySearchTree_->insert(item, binarySearchTree_->getRoot());
    return true;
}

template <class T>
bool Manager<T>::deleteItem(T item){
    bool isSucceed = true;
    try {
        binarySearchTree_->remove(item, binarySearchTree_->getRoot());
    } catch (Exception& e) {
        std::cout << e.execute() << std::endl;
        isSucceed = false;
    }
    return isSucceed;
}

template <class T>
bool Manager<T>::createBinarySearchTree(std::string fileName){
    std::vector<T> data;
    bool isSucceed = true;

    binarySearchTree_->reset(binarySearchTree_->getRoot());
    fileManager_->setFile(fileName);
    try {
        fileManager_->validate();
    } catch (Exception& e) {
        isSucceed = false;
        std::cout << e.execute() << std::endl;
    }
    if (isSucceed) {
        fileManager_->read(data);
        for (int i = 0; i < data.size(); i++){
            binarySearchTree_->insert(data[i], binarySearchTree_->getRoot());
        }
    }
    return isSucceed;

}

template <class T>
Node<T> Manager<T>::findItem(T item, bool& isSucceed){
    Node<T> foundItem;
    isSucceed = true;
    try {
        foundItem = Node<T> (binarySearchTree_->search(item, binarySearchTree_->getRoot()));
    } catch (Exception& e) {
        isSucceed = false;
        std::cout << e.execute() << std::endl;
    }
    return foundItem;
}

template <class T>
bool Manager<T>::clearBinarySearchTree(){
    binarySearchTree_->reset(binarySearchTree_->getRoot());
    return true;
}


#endif //LAB_MANAGER_H
