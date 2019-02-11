#include <string.h>
#include "Book.h"

Book::Book(char* name, char* author){
    name_ = new char[strlen(name)+1];
    strcpy(name_, name);
    author_ = new char[strlen(author) + 1];
    strcpy(author_, author);
}

Book::Book(Book& book){
    name_ = new char[strlen(book.getName()) + 1];
    strcpy(name_, book.getName());
    author_ = new char[strlen(book.getAuthor()) + 1];
    strcpy(author_, book.getAuthor());
}

Book::~Book(){
    delete [] name_;
    delete [] author_;
}

char* Book::getName(){
    return name_;
}

char* Book::getAuthor(){
    return author_;
}

void Book::setName(char* name){
    name_ = new char[strlen(name) + 1];
    strcpy(name_, name);
}

void Book::setAuthor(char* author){
    author_ = new char[strlen(author) + 1];
    strcpy(author_, author);
}
