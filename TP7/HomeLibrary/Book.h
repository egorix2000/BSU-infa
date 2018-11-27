#pragma once
#ifndef BOOK_H_INCLUDED
#define BOOK_H_INCLUDED

class Book {
    private:
        char* name_;
        char* author_;
    public:
        Book();
        Book(char* name, char* author);
        Book(Book& book);
        ~Book();
        char* getName();
        char* getAuthor();
        void setName(char* name);
        void setAuthor(char* author);
};

#endif // BOOK_H_INCLUDED
