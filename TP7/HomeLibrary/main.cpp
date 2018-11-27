/**

Разработать приложение «домашняя библиотека». Предусмотреть возможность работы с произвольным
числом книг, поиска книги по какому-либо признаку (например, по автору или по году издания),
добавления книг в библиотеку, удаления книг из нее, сортировки книг по разным полям.
Написать программу, демонстрирующую работу с этим классом. Программа должна
содержать меню, позволяющее осуществить проверку всех методов класса.


**/

#include <iostream>
#include <cctype>
#include <cstring>
#include <iomanip>

#include "HomeLibrary.h"

using namespace std;

const int MAX_STRING_LENGTH = 256;

void displayMenu(){
    cout << "Enter:" << endl;
    cout << "0 to exit" << endl;
    cout << "1 to display all books in library" << endl;
    cout << "2 to add a book" << endl;
    cout << "3 to delete a book" << endl;
    cout << "4 to find books by author" << endl;
    cout << "5 to sort" << endl;
}

void printArray(Book** books, int n){
    cout << setw(10) << "Name" << setw(10) << "Author" << endl;
    for (int i = 0; i < n; i++){
        cout << setw(10) << books[i]->getName() << setw(10) << books[i]->getAuthor() << endl;
    }
}

void displayAllBooksInLibrary(HomeLibrary* library){
    Book** books = library->getAllBooks();
    printArray(books, library->getNumberOfBooks());
}

void addBook(HomeLibrary* library){
    char name[MAX_STRING_LENGTH];
    char author[MAX_STRING_LENGTH];
    cout << "Enter name: ";
    cin >> name;
    cout << "Enter author: ";
    cin >> author;

    Book* book = new Book(name, author);
    library->addBook(*book);
}

void deleteBook(HomeLibrary* library){
    char name[MAX_STRING_LENGTH];
    cout << "Enter name of book to delete: ";
    cin >> name;

    library->deleteBook(name);
}

void findBooks(HomeLibrary* library){
    char author[MAX_STRING_LENGTH];
    cout << "Enter author of book to find: ";
    cin >> author;

    pair<Book**, int> books = library->findBooksByAuthor(author);
    printArray(books.first, books.second);
}

void sortBooks(HomeLibrary* library){
    int command;
    cout << "Enter 1 if you want to sort by name, 2 if you want to sort by author: ";
    cin >> command;

    switch(command){
        case 1:
            library->sortByName();
            break;
        case 2:
            library->sortByAuthor();
            break;
        default:
            break;
    }
}

int main()
{
    HomeLibrary* library = new HomeLibrary();
    int command = -1;

    displayMenu();

    while (command != 0){
        cin >> command;
        switch(command){
            case 1:
                displayAllBooksInLibrary(library);
                break;
            case 2:
                addBook(library);
                break;
            case 3:
                deleteBook(library);
                break;
            case 4:
                findBooks(library);
                break;
            case 5:
                sortBooks(library);
                break;
            default:
                break;
        }
    }
    return 0;

}
