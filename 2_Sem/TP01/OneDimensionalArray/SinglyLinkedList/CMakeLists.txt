cmake_minimum_required(VERSION 3.12)
project(SinglyLinkedList)

ADD_LIBRARY(SinglyLinkedList SHARED SinglyLinkedList.h Node.h SinglyLinkedListIterator.h
        SinglyLinkedListException.h SinglyLinkedListException.cpp SinglyLinkedListEmptyException.h
        SinglyLinkedListEmptyException.cpp SinglyLinkedListIncrementException.cpp SinglyLinkedListIncrementException.h)