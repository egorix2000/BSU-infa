#include "Book.h"

Book::Book(char* name, char* author){
    name_ = name;
    author_ = author;
}

Book::~Book(){
    delete name_;
    delete author_;
}

char* Book::getName(){
    return name_;
}

char* Book::getAuthor(){
    return author_;
}

void Book::setName(char* name){
    name_ = name;
}

void Book::setAuthor(char* author){
    author_ = author;
}
