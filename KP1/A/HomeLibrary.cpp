#include <string.h>
#include <utility>
#include <iostream>
#include "HomeLibrary.h"

using namespace std;

void HomeLibrary::deleteBooks(){
    for (int i = 0; i < numberOfBooks_; i++){
        delete books_[i];
    }
    delete [] books_;
}

HomeLibrary::HomeLibrary(){
    if (numberOfBooks_ && numberOfBooks_ != 0){
        this->deleteBooks();
    }
    numberOfBooks_ = 0;
}

HomeLibrary::~HomeLibrary(){
    if (numberOfBooks_ && numberOfBooks_ != 0){
        this->deleteBooks();
    }
}

Book** HomeLibrary::getAllBooks(){
    return books_;
}

int HomeLibrary::getNumberOfBooks(){
    return numberOfBooks_;
}

void HomeLibrary::addBook(Book* book){
    Book** newBooks = new Book*[numberOfBooks_+1]; //create new array with size n+1
    for (int i = 0; i < numberOfBooks_; i++){
        newBooks[i] = books_[i]; // copy old array to new
    }
    newBooks[numberOfBooks_] = book; // add book

    books_ = newBooks;

    numberOfBooks_++;
}

void HomeLibrary::deleteBook(char* name){
    if (numberOfBooks_ == 1){
        delete [] books_;
    }
    else if (numberOfBooks_ > 1){
        Book** newBooks = new Book*[numberOfBooks_-1]; //create new array with size n-1
        int k = 0;
        for (int i = 0; i < numberOfBooks_; i++){
            if (!strcmp(books_[i]->getName(), name)){
                newBooks[k] = books_[i]; // copy from old array to new
                k++;
            }
        }

        books_ = newBooks;

        numberOfBooks_--;
    }
}

std::pair<Book**, int> HomeLibrary::findBooksByAuthor(char* author){
    int booksByAuthorNumber = 0;
    //booksByAuthorLong is array with all books writed by author, with size numberOfBooks_ (greatest possible number of books)
    Book** booksByAuthorLong = new Book*[numberOfBooks_];
    for (int i = 0; i < numberOfBooks_; i++){
        if (strcmp(books_[i]->getAuthor(), author)){
            booksByAuthorLong[booksByAuthorNumber] = books_[i];
            booksByAuthorNumber++;
        }
    }
    //booksByAuthor is array with all books writed by author, with size booksByAuthorNumber (real number of books)
    Book** booksByAuthor = new Book*[booksByAuthorNumber];
    for (int i = 0; i < booksByAuthorNumber; i++){
        booksByAuthor[i] = booksByAuthorLong[i];
    }

    return std::make_pair(booksByAuthor, booksByAuthorNumber);
}

HomeLibrary* HomeLibrary::sortBooks(bool (*comparator) (Book*, Book*)){
    Book* temp;
    for (int i = 0; i < numberOfBooks_; i++){
        for (int j = 0; j < numberOfBooks_-i-1; j++){
            if (comparator(books_[j], books_[j+1])){
                temp = books_[j];
                books_[j] = books_[j+1];
                books_[j+1] = temp;
            }
        }
    }
    return this;
}

bool nameComparator(Book* a, Book* b){
    if (strcmp(a->getName(), b->getName())){
        return true;
    } else {
        return false;
    }
}

bool authorComparator(Book* a, Book* b){
    if (strcmp(a->getAuthor(), b->getAuthor())){
        return true;
    } else {
        return false;
    }
}

HomeLibrary* HomeLibrary::sortByName(){
    return sortBooks(&nameComparator);
}

HomeLibrary* HomeLibrary::sortByAuthor(){
    return sortBooks(&authorComparator);
}
