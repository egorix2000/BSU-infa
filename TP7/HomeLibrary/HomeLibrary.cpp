#include <string.h>
#include <utility>
#include "HomeLibrary.h"

using namespace std;

void HomeLibrary::deleteBooks(){
    if (numberOfBooks_ > 0){
        for (int i = 0; i < numberOfBooks_; i++){
            delete books_[i];
        }
        delete [] books_;
    }
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

void HomeLibrary::addBook(Book& book){
    Book* bookCopy;
    Book** newBooks = new Book*[numberOfBooks_+1]; //create new array with size n+1
    for (int i = 0; i < numberOfBooks_; i++){
        bookCopy = new Book(*books_[i]);
        newBooks[i] = bookCopy; // copy old array to new
    }

    Book* newBook = new Book(book);
    newBooks[numberOfBooks_] = newBook; // add book

    deleteBooks();

    books_ = newBooks;

    numberOfBooks_++;
}

void HomeLibrary::deleteBook(char* name){
    if (numberOfBooks_ == 1){
        if (strcmp(books_[0]->getName(), name) == 0){
            deleteBooks();
            numberOfBooks_ = 0;
        }
    }
    else if (numberOfBooks_ > 1){
        Book* bookCopy;
        Book** newBooks = new Book*[numberOfBooks_-1]; //create new array with size n-1
        int k = 0;
        for (int i = 0; i < numberOfBooks_; i++){
            if (strcmp(books_[i]->getName(), name) != 0){
                bookCopy = new Book(*books_[i]);
                newBooks[k] = bookCopy; // copy from old array to new
                k++;
            }
        }

        deleteBooks();
        books_ = newBooks;

        numberOfBooks_--;
    }
}

std::pair<Book**, int> HomeLibrary::findBooksByAuthor(char* author){
    Book* bookCopy;
    int booksByAuthorNumber = 0;
    int k;
    //find number of books by author
    for (int i = 0; i < numberOfBooks_; i++){
        if (strcmp(books_[i]->getAuthor(), author) == 0){
            booksByAuthorNumber++;
        }
    }
    //booksByAuthor is array with all books writed by author
    Book** booksByAuthor = new Book*[booksByAuthorNumber];
    k = 0;
    for (int i = 0; i < numberOfBooks_; i++){
        if (strcmp(books_[i]->getAuthor(), author) == 0){
            bookCopy = new Book(*books_[i]);
            booksByAuthor[k] = bookCopy;
            k++;
        }
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

bool HomeLibrary::nameComparator(Book* a, Book* b){
    if (strcmp(a->getName(), b->getName()) > 0){
        return true;
    } else {
        return false;
    }
}

bool HomeLibrary::authorComparator(Book* a, Book* b){
    if (strcmp(a->getAuthor(), b->getAuthor()) > 0){
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
