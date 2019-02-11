#pragma once
#ifndef HOMELIBRARY_H_INCLUDED
#define HOMELIBRARY_H_INCLUDED

#include <utility>
#include "Book.h"

class HomeLibrary {
    private:
        Book** books_;
        int numberOfBooks_;

        void deleteBooks(); // delete books_
        HomeLibrary* sortBooks(bool (*comparator) (Book*, Book*));
        static bool nameComparator(Book* a, Book* b);
        static bool authorComparator(Book* a, Book* b);
    public:
        HomeLibrary();
        ~HomeLibrary();
        Book** getAllBooks();
        int getNumberOfBooks();
        void addBook(Book& book);
        void deleteBook(char* name);
        std::pair<Book**, int> findBooksByAuthor(char* author);
        HomeLibrary* sortByName();
        HomeLibrary* sortByAuthor();
};

#endif // HOMELIBRARY_H_INCLUDED
